#include "ofxMoonLightLogger.h"
#include "ofUtils.h"

ofxMoonLight lua;
vector<string> scripts;
int currentScript;

int createNewApp(string path) {
    string newPath = path;
    if(ofFilePath::isAbsolute(newPath) == 0) {
        newPath = ofFilePath::join(ofFilePath::getCurrentWorkingDirectory(), newPath);
    }
    ofDirectory rootDir = ofDirectory(newPath);
    if(rootDir.exists()) {
        return 1;
    }

    //create top level folder
    rootDir.create();

    //create application folders
    ofDirectory appDir = ofDirectory(ofFilePath::join(rootDir.path(), "app"));
    ofDirectory dataDir = ofDirectory(ofFilePath::join(rootDir.path(), "data"));
    appDir.create();
    dataDir.create();

    //add application files
    string baseFilePath = ofFilePath::join(ofFilePath::getCurrentExeDir(), "appfiles");
    ofFile mainFile = ofFile(ofFilePath::join(baseFilePath, "main.lua"));
    ofFile appFile = ofFile(ofFilePath::join(baseFilePath, "app.lua"));
    ofFile classFile = ofFile(ofFilePath::join(baseFilePath, "class.lua"));
    bool movedMainFile = mainFile.copyTo(rootDir.path());
    bool movedAppFile = appFile.copyTo(ofFilePath::join(rootDir.path(), "app"));
    bool movedClassFile = classFile.copyTo(ofFilePath::join(rootDir.path(), "app"));

    if(movedMainFile && movedAppFile && movedClassFile) {
        cout << "Initialized app at " << rootDir.path() << "\n\n";
        return 0;
    } else {
        return 1;
    }
}

//========================================================================
int main(int argc, char* argv[]) {

    if(argc > 1 && strcmp(argv[1], "new")==0) {
        cout << "Argv[1]: " << argv[1] << "\n\n";
        return createNewApp(argv[2]);
    } else {
        std::string script;
        if(argc == 1) {
            script = ".";
        } else {
            script = argv[1];
        }

        cout << "Script: " << argc << "\n\n";

        // scripts to run
        scripts.push_back(script);
        currentScript = 0;
        
        // listen to error events
        lua.addListener(new ofxMoonLightLogger());
        lua.init();
        
        // run a script
        lua.doScript(scripts[currentScript]);
    }


}
