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

//--------------------------------------------------------------
void ofLuaApp::keyPressed(int key) {
    if (!dub_pushcallback("keyPressed")) return;
    
    lua_pushnumber(dub_L, key);
    
    dub_call(2, 0);
}

void ofLuaApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofLuaApp::mouseMoved(int x, int y) {
    if (!dub_pushcallback("mouseMoved")) return;
    
    lua_pushnumber(dub_L, x);
    lua_pushnumber(dub_L, y);
    
    dub_call(3, 0);
}

//--------------------------------------------------------------
void ofLuaApp::mouseDragged(int x, int y, int button) {
    if (!dub_pushcallback("mouseDragged")) return;
    
    lua_pushnumber(dub_L, x);
    lua_pushnumber(dub_L, y);
    lua_pushnumber(dub_L, button);
    
    dub_call(4, 0);
}

//--------------------------------------------------------------
void ofLuaApp::mousePressed(int x, int y, int button) {
    if (!dub_pushcallback("mousePressed")) return;
    
    lua_pushnumber(dub_L, x);
    lua_pushnumber(dub_L, y);
    lua_pushnumber(dub_L, button);
    
    dub_call(4, 0);
}

//--------------------------------------------------------------
void ofLuaApp::mouseReleased(int x, int y, int button) {
    if (!dub_pushcallback("mouseReleased")) return;
    
    lua_pushnumber(dub_L, x);
    lua_pushnumber(dub_L, y);
    lua_pushnumber(dub_L, button);
    
    dub_call(4, 0);
}

//--------------------------------------------------------------
void ofLuaApp::windowResized(int w, int h) {
    if (!dub_pushcallback("windowResized")) return;
    
    lua_pushnumber(dub_L, w);
    lua_pushnumber(dub_L, h);
    
    dub_call(3, 0);
}
