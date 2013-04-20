#include "ofxMoonLightLogger.h"

//--------------------------------------------------------------
void ofxMoonLightLogger::errorReceived(string& msg) {
	cout << "got an error: " << msg << endl;
}
