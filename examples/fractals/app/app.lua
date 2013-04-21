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

    ofEnableAlphaBlending()

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
  
    -- 8 bits red, 8 bits green, 8 bits blue, from 0 to 255 in 256 steps
    rgbaFbo = ofFbo() -- with alpha
    rgbaFbo:allocate(width, height)
		
    -- 32 bits red, 32 bits green, 32 bits blue, from 0 to 1 in 'infinite' steps
    rgbaFboFloat = ofFbo() -- with alpha
    rgbaFboFloat:allocate(width, height)
		
    fadeAmnt = 0
    
    rgbaFbo:begin()
	ofClear(255,255,255, 0)
    rgbaFbo:finish()
	
	rgbaFboFloat:begin()
	ofClear(255,255,255, 0)
    rgbaFboFloat:finish()

  
end

function app:update()

    
    pentagon = FractalRoot(ofGetElapsedTimef()*0.05);


	
	-- lets draw some graphics into our two fbos
    rgbaFbo:begin()
    self:drawFboTest()
    rgbaFbo:finish()
    
    -- lets draw some graphics into our two fbos
    rgbaFbo:begin()
    self:drawFboTest()
    rgbaFbo:finish()

end

function app:drawFboTest()

	-- this is where we fade the fbo
	-- by drawing a rectangle the size of the fbo with a small alpha value, we can slowly fade the current contents of the fbo.
	ofFill()
	ofSetColor(255,255,255, 15)
	ofRect(0,0,width,height)

   -- ofClear(255,255,255, 5)

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

function app:draw()

    ofSetColor(255,255,255)
    rgbaFbo:draw(0,0)
    rgbaFboFloat:draw(410,0)

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

