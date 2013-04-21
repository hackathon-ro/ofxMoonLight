require 'FractalRoot'
require 'PointObj'
require 'Branch'

app = ofLuaApp()

_maxLevels = 4;
_strutFactor = 0.2;
xdirection = 1;
 ydirection = 1;
 xspeed = 2.2;
 yspeed = 2.5;

function app:setup()

    ofBackground(255);
    ofSetSmoothLighting()

    ofSetFrameRate(30)

    width = ofGetWindowWidth()
    height = ofGetWindowHeight()

  _strutNoise = ofRandom(10);
  red1 = ofRandom(255);
  green1 = ofRandom(255);
  blue1 = ofRandom(255);
  red2 = ofRandom(255);
  green2 = ofRandom(255);
  blue2 = ofRandom(255);
  red3 = ofRandom(255);
  green3 = ofRandom(255);
  blue3 = ofRandom(255);
  red4 = ofRandom(255);
  green4 = ofRandom(255);
  blue4 = ofRandom(255);
  red5 = ofRandom(255);
  green5 = ofRandom(255);
  blue5 = ofRandom(255);
  red6 = ofRandom(255);
  green6 = ofRandom(255);
  blue6 = ofRandom(255);
 
  xpos = ofRandom(-500, 500);
  ypos = ofRandom(-500, 500);
  xpos2 = ofRandom(-500, 500);
  ypos2 = ofRandom(-500, 500);
 
  Rad = ofRandom(100, 600)
 
  _numSides = ofRandom(3, 10)
  
end

function app:update()

    pentagon = FractalRoot(ofGetElapsedTimef()*0.05);
end

function app:draw()

    _strutNoise = _strutNoise+0.01;
    _strutFactor = ofNoise(_strutNoise)*2;
    pentagon:drawShape();
    ofTranslate(xpos, ypos);
    pentagon:drawShape();
    ofTranslate(xpos, ypos);
    pentagon:drawShape();
    ofTranslate(xpos2, ypos2);
    pentagon:drawShape();
    ofTranslate(xpos2, ypos2);
    pentagon:drawShape();

end

function app:mouseDragged(x, y, button)
    mouseX = x
    mouseY = y
end

function app:mousePressed(x, y, button)
   
    red1 = ofRandom(255);
    green1 = ofRandom(255);
    blue1 = ofRandom(255);
    red2 = ofRandom(255);
    green2 = ofRandom(255);
    blue2 = ofRandom(255);
    red3 = ofRandom(255);
    green3 = ofRandom(255);
    blue3 = ofRandom(255);
    red4 = ofRandom(255);
    green4 = ofRandom(255);
    blue4 = ofRandom(255);
    red5 = ofRandom(255);
    green5 = ofRandom(255);
    blue5 = ofRandom(255);
    red6 = ofRandom(255);
    green6 = ofRandom(255);
    blue6 = ofRandom(255);

    xpos = ofRandom(-500, 500);
    ypos = ofRandom(-500, 500);
    xpos2 = ofRandom(-500, 500);
    ypos2 = ofRandom(-500, 500);

    Rad = ofRandom(100, 600);

    _strutNoise = ofRandom(20);

    _numSides = ofRandom(3, 10);

end

function app:mouseMoved(x, y, button)
    mouseX = x
    mouseY = y
end

