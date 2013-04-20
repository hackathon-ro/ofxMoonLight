#include "ofxMoonLightLogger.h"

ofxMoonLight lua;
vector<string> scripts;
int currentScript;

//========================================================================
int main(){
    
    // scripts to run
    scripts.push_back("scripts/helloworld.lua");
	currentScript = 0;
	
	// listen to error events
	lua.addListener(new ofxMoonLightLogger());
	
	lua.init();
	
	// run a script
	lua.doScript(scripts[currentScript]);
}
