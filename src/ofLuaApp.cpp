//
//  ofLuaApp.cpp
//  ofxMoonLight
//
//  Created by Leonard Chioveanu on 4/20/13.
//
//

#include "ofLuaApp.h"

//--------------------------------------------------------------
void ofLuaApp::setup() {
    if (!dub_pushcallback("setup")) return;
    dub_call(1, 0);
}

//--------------------------------------------------------------
void ofLuaApp::update() {
    if (!dub_pushcallback("update")) return;
    dub_call(1, 0);
}

//--------------------------------------------------------------
void ofLuaApp::draw() {
    if (!dub_pushcallback("draw")) return;
    dub_call(1, 0);
}

//--------------------------------------------------------------
void ofLuaApp::exit() {
    if (!dub_pushcallback("exit")) return;
    dub_call(1, 0);
}
