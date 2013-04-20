#pragma once

#include "ofxMoonLight.h"

/// a desktop os app wrapper
class ofxMoonLightLogger : public ofxMoonLightListener{

	public:
        // ofxLua error callback
        void errorReceived(string& msg);
};
