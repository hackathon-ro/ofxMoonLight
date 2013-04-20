/*
 * Copyright (c) 2012 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMoonLight for documentation
 *
 * This project uses the following libraries:
 *
 * Lua, Copyright (c) 1994�2011 Lua.org, PUC-Rio using the MIT License.
 * See the file "COPYRIGHT" in src/lua.
 * See http://www.lua.org/docs.html for documentation
 *
 * Luabind, Copyright (c) 2003 Daniel Wallin and Arvid Norberg using the
 * MIT License. See the file "LICENSE" in src/luabind.
 * See http://www.rasterbar.com/products/luabind/docs.html for documentation
 *
 */
#include "ofxMoonLight.h"
#include "ofUtils.h"

int setLuaPath( lua_State* L, const char* path )
{
    lua_getglobal( L, "package" );
    lua_getfield( L, -1, "path" ); // get field "path" from table at top of stack (-1)
    std::string cur_path = lua_tostring( L, -1 ); // grab path string from top of stack

    cur_path.append( ";" ); // do your path magic here
    cur_path.append( path );
    cur_path.append("/app/?.lua");

    lua_pop( L, 1 ); // get rid of the string on the stack we just pushed on line 5
    lua_pushstring( L, cur_path.c_str() ); // push the new one
    lua_setfield( L, -2, "path" ); // set the field "path" in table at -2 with value at top of stack
    lua_pop( L, 1 ); // get rid of package table from top of stack
    return 0; // all done!
}

// local pointer for static functions
ofxMoonLight* luaPtr;

//------------------------------------------------------------------------------
ofxMoonLight::ofxMoonLight() {
	L = NULL;
	bAbortOnError = false;
	luaPtr = this;
}

//------------------------------------------------------------------------------
ofxMoonLight::~ofxMoonLight() {
}

//------------------------------------------------------------------------------
bool ofxMoonLight::init(bool abortOnError, bool openLibs) {
	
	L = luaL_newstate();
	if(L == NULL) {
		ofLogError("ofxMoonLight") << "Error initializing lua";
		return false;
	}
	
	// open libs
	if(openLibs) {
		luaL_openlibs(L);
        luaopen_of(L);
	}
	
	// set the panic function
	lua_atpanic(L, &atPanic);
	
	bAbortOnError = abortOnError;
	ofLogVerbose("ofxMoonLight") << "Initialized state";
	
	return true;
}

bool ofxMoonLight::isValid() {
	return L != NULL ? true : false;
}

//------------------------------------------------------------------------------
bool ofxMoonLight::doString(const string& text) {
	
	if(L == NULL) {
		ofLogError("ofxMoonLight") << "Cannot do string, lua state not inited!";
		return false;
	}

	ofLogVerbose("ofxMoonLight") << "Doing string: \"" << text.substr(0,40) << "\"";
	
	// load the string
	int ret = luaL_loadstring(L, text.c_str());
	if(ret != 0) {
		switch(ret) {
			case LUA_ERRSYNTAX:
			{
				string msg = "Syntax error in string \""
					 +text.substr(0,40)+"\": "
					 +(string) lua_tostring(L, -1);
				errorOccurred(msg);
				break;
			}
			case LUA_ERRMEM:
			{
				string msg = "String \""+text.substr(0,40)+"\" memory error",
				errorOccurred(msg);
				break;
			}
		}
				
		return false;
	}
	
	// run the string
	ret = lua_pcall(L, 0, LUA_MULTRET, 0);
	if(ret != 0) {
		string msg = "Runtime error in string \""+text.substr(0,40)+"\": "
					 +(string) lua_tostring(L, -1);
		errorOccurred(msg);
		return false;
	}
	
	return true;
}

//------------------------------------------------------------------------------
bool ofxMoonLight::doScript(const string& script) {

	if(L == NULL) {
		ofLogError("ofxMoonLight") << "Cannot do script, lua state not inited!";
		return false;
	}
    cout << "Script: " << script << "\n";
	
    string fullpath = ofFilePath::getAbsolutePath(script);

    string filepath = fullpath.append("/main.lua");
    string file = ofFilePath::getFileName(filepath);

    std::string folder = ofFilePath::getEnclosingDirectory(fullpath);
	
	// trim the trailing slash Poco::Path always adds ... blarg
	if(folder.size() > 0 && folder.at(folder.size()-1) == '/') {
		folder.erase(folder.end()-1);
	}
	
	ofLogVerbose("ofxMoonLight") << "Doing script: \"" << file << "\" path: \"" << folder << "\"";

    setLuaPath(L, folder.c_str());
    std::string data_path = folder.append("/data/");
	ofSetDataPathRoot(data_path);
	// load the script
	int ret = luaL_loadfile(L, fullpath.c_str());
	if(ret != 0) {
		switch(ret) {
			case LUA_ERRFILE:
			{
				string msg = (string)"Script \""+file+"\" not found or unreadable";
				errorOccurred(msg);
				break;
			}
			case LUA_ERRSYNTAX:
			{
				string msg = "Syntax error: "+(string) lua_tostring(L, -1);
				errorOccurred(msg);
				break;
			}
			case LUA_ERRMEM:
			{
				string msg = "Script \""+file+"\" memory error";
				errorOccurred(msg);
				break;
			}
		}
		return false;
	}
	
	// run the script
	if(lua_pcall(L, 0, LUA_MULTRET, 0) != 0) {
		string msg = "Runtime error: "+(string) lua_tostring(L, -1);
		errorOccurred(msg);
		return false;
	}
	
	return true;
}

//------------------------------------------------------------------------------		
void ofxMoonLight::addListener(ofxMoonLightListener* listener) {
	ofAddListener(errorEvent, listener, &ofxMoonLightListener::errorReceived);
}
		
//------------------------------------------------------------------------------		
void ofxMoonLight::removeListener(ofxMoonLightListener* listener) {
	ofRemoveListener(errorEvent, listener, &ofxMoonLightListener::errorReceived);
}
		
//------------------------------------------------------------------------------
void ofxMoonLight::errorOccurred(string& msg) {
	
	errorMessage = msg;
	
	// send to listeners
	ofNotifyEvent(errorEvent, msg, this);
	
	// print
	ofLogError("ofxMoonLight") << msg;
	
	// close the state?
	if(bAbortOnError) {
		ofLogError("ofxMoonLight") << "Closing state";
	}
}

//------------------------------------------------------------------------------
int ofxMoonLight::atPanic(lua_State *L) {
	ofLogError("ofxMoonLight") << "Lua panic ocurred! : " << lua_tostring(L, -1);
	ofLogError("ofxMoonLight") << "Closing state";
	return 0;
}
