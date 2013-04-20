//
//  ofLuaApp.h
//  ofxMoonLight
//
//  Created by Leonard Chioveanu on 4/20/13.
//
//

#pragma once

#include "ofMain.h"
#include "dub.h"

/** Use the following markup to use the callback:
 * @dub push: pushobject
 */
class ofLuaApp : public ofBaseApp, public dub::Thread{
    
public:
    
    void setup();
    void update();
    void draw();
    void exit();
};
