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
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
};
