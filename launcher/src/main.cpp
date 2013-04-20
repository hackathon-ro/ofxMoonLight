#include "ofxMoonLightLogger.h"
#include "ofUtils.h"

ofxMoonLight lua;
vector<string> scripts;
int currentScript;

//========================================================================
int main(int argc, char* argv[]) {


    if(argc < 2) {
        ofLogError("Must supply a path parameter");
        return 1;
    }

    cout << argv[1] << "\n";
    
    // scripts to run
    scripts.push_back(argv[1]);
	currentScript = 0;
	
	// listen to error events
	lua.addListener(new ofxMoonLightLogger());
	lua.init();
	
	// run a script
	lua.doScript(scripts[currentScript]);
}
