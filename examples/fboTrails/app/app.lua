app = ofLuaApp()

function app:setup()

    width = ofGetWindowWidth()
    height = ofGetWindowHeight()
    
    ofBackground(0,0,0)
	ofSetFrameRate(60)

    mouseX = 0
    mouseY = 0
    
    -- 8 bits red, 8 bits green, 8 bits blue, from 0 to 255 in 256 steps
    rgbaFbo = ofFbo() -- with alpha
    rgbaFbo:allocate(400, 400)
		
    -- 32 bits red, 32 bits green, 32 bits blue, from 0 to 1 in 'infinite' steps
    rgbaFboFloat = ofFbo() -- with alpha
    rgbaFboFloat:allocate(400, 400)
		
    fadeAmnt = 0
    
    rgbaFbo:begin()
	ofClear(255,255,255, 0)
    rgbaFbo:finish()
	
	rgbaFboFloat:begin()
	ofClear(255,255,255, 0)
    rgbaFboFloat:finish()

end

function app:update()
    ofEnableAlphaBlending()
	
	-- lets draw some graphics into our two fbos
    rgbaFbo:begin()
    self:drawFboTest()
    rgbaFbo:finish()
	  	
    rgbaFboFloat:begin()
    self:drawFboTest()
	rgbaFboFloat:finish()
end

function app:drawFboTest()
	-- we clear the fbo if c is pressed. 
	-- this completely clears the buffer so you won't see any trails
	if ofGetKeyPressed(string.byte('c')) then
		ofClear(255,255,255, 0)
	end
	
	-- some different alpha values for fading the fbo
	-- the lower the number, the longer the trails will take to fade away.
	fadeAmnt = 40
	if ofGetKeyPressed(1) then
		fadeAmnt = 1
	elseif ofGetKeyPressed(2) then
		fadeAmnt = 5
	elseif ofGetKeyPressed(3) then
		fadeAmnt = 15
	end

	-- 1 - Fade Fbo
	
	-- this is where we fade the fbo
	-- by drawing a rectangle the size of the fbo with a small alpha value, we can slowly fade the current contents of the fbo.
	ofFill()
	ofSetColor(255,255,255, fadeAmnt)
	ofRect(0,0,400,400)

	-- 2 - Draw graphics
	
	ofNoFill()
	ofSetColor(255,255,255)
	
	-- we draw a cube in the center of the fbo and rotate it based on time
	ofPushMatrix() 
		ofTranslate(200,200,0)
		ofRotate(ofGetElapsedTimef()*30, 1,0,0.5)
		ofBox(0,0, 100)
	ofPopMatrix()

	-- also draw based on our mouse position
	ofFill()	   
	ofCircle(ofGetMouseX() % 410, ofGetMouseY(), 8)

	-- we move a line across the screen based on the time
	-- the %400 makes the number stay in the 0-400 range. 
	local shiftX   = (ofGetElapsedTimeMillis() / 8 ) % 400

	ofRect(shiftX, rgbaFbo:getHeight()-30, 3, 30)
end

function app:draw()

    ofSetColor(255,255,255)
    rgbaFbo:draw(0,0)
    rgbaFboFloat:draw(410,0)
	  	
    ofDrawBitmapString("non floating point FBO", 10,20)
    ofDrawBitmapString("floating point FBO", 420,20)

    local alphaInfo = "Current alpha fade amnt = " .. fadeAmnt
	alphaInfo = alphaInfo .. "\nHold '1' to set alpha fade to 1"
	alphaInfo = alphaInfo .. "\nHold '2' to set alpha fade to 5"
	alphaInfo = alphaInfo .. "\nHold '3' to set alpha fade to 15"
	alphaInfo = alphaInfo .. "\nHold 'c' to clear the fbo each frame\n\nMove mouse to draw with a circle"
	
    ofDrawBitmapString(alphaInfo, 10,430)

end

function app:mouseDragged(x, y, button)
    mouseX = x
    mouseY = y
end

function app:mousePressed(x, y, button)
    mouseX = x
    mouseY = y
end

function app:mouseMoved(x, y, button)
    mouseX = x
    mouseY = y
end
