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
    cout << "New Path: " << newPath << "\n\n";
    ofDirectory rootDir = ofDirectory(newPath);
    if(rootDir.exists()) {
        cout << "Directory already exists\n\n";
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
    cout << "Base File Path: " << baseFilePath << "\n\n";
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


    if(argc < 2) {
        ofLogError("Must supply a path parameter");
        return 1;
    }

    cout << "[1]" << argv[1] << "\n\n";
    cout << "[2]" << argv[2] << "\n\n";

    if(strcmp(argv[1], "new")==0) {
        return createNewApp(argv[2]);
        
    } else {
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


}
