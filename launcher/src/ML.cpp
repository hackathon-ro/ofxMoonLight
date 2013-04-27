/*
 * Based on https://github.com/danomatika/ofxLua
 */
#include "ML.h"
#include "ofUtils.h"

int setLuaPath( lua_State* L, const char* path )
{
    lua_getglobal( L, "package" );
    lua_getfield( L, -1, "path" ); 
    std::string cur_path = lua_tostring( L, -1 ); 

    cur_path.append( ";" ); 
    cur_path.append( path );
    cur_path.append("/app/?.lua");

    lua_pop( L, 1 );
    lua_pushstring( L, cur_path.c_str() ); 
    lua_setfield( L, -2, "path" ); 
    lua_pop( L, 1 );


    lua_getglobal( L, "_G" );
    lua_getfield( L, -1, "current_dir" ); 
    std::string app_path = path;
    lua_pop(L, 1);
    lua_pushstring(L, app_path.c_str() ); 
    lua_setfield( L, -2, "current_dir" ); 
    lua_pop( L, 1 );
    return 0;
}

// local pointer for static functions
ML* luaPtr;

//------------------------------------------------------------------------------
ML::ML() {
	L = NULL;
	bAbortOnError = false;
	luaPtr = this;
}

//------------------------------------------------------------------------------
ML::~ML() {
}

//------------------------------------------------------------------------------
bool ML::init(bool abortOnError, bool openLibs) {
	
	L = luaL_newstate();
	if(L == NULL) {
		ofLogError("ML") << "Error initializing lua";
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
	ofLogVerbose("ML") << "Initialized state";
	
	return true;
}

bool ML::isValid() {
	return L != NULL ? true : false;
}

//------------------------------------------------------------------------------
bool ML::doString(const string& text) {
	
	if(L == NULL) {
		ofLogError("ML") << "Cannot do string, lua state not inited!";
		return false;
	}

	ofLogVerbose("ML") << "Doing string: \"" << text.substr(0,40) << "\"";
	
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
bool ML::doScript(const string& script) {

	if(L == NULL) {
		ofLogError("ML") << "Cannot do script, lua state not inited!";
		return false;
	}

    string fullpath;
    if(ofFilePath::isAbsolute(script) == 1) {
        fullpath = script;
    } else {
        fullpath = ofFilePath::join(ofFilePath::getCurrentWorkingDirectory(), script);
    }


    string filepath = fullpath.append("/main.lua");
    string file = ofFilePath::getFileName(filepath);

    std::string folder = ofFilePath::getEnclosingDirectory(fullpath);
	
	// trim the trailing slash Poco::Path always adds ... blarg
	if(folder.size() > 0 && folder.at(folder.size()-1) == '/') {
		folder.erase(folder.end()-1);
	}
	
	ofLogVerbose("ML") << "Doing script: \"" << file << "\" path: \"" << folder << "\"";

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
void ML::addListener(MLListener* listener) {
	ofAddListener(errorEvent, listener, &MLListener::errorReceived);
}
		
//------------------------------------------------------------------------------		
void ML::removeListener(MLListener* listener) {
	ofRemoveListener(errorEvent, listener, &MLListener::errorReceived);
}
		
//------------------------------------------------------------------------------
void ML::errorOccurred(string& msg) {
	
	errorMessage = msg;
	
	// send to listeners
	ofNotifyEvent(errorEvent, msg, this);
	
	// print
	ofLogError("ML") << msg;
	
	// close the state?
	if(bAbortOnError) {
		ofLogError("ML") << "Closing state";
	}
}

//------------------------------------------------------------------------------
int ML::atPanic(lua_State *L) {
	ofLogError("ML") << "Lua panic ocurred! : " << lua_tostring(L, -1);
	ofLogError("ML") << "Closing state";
	return 0;
}
