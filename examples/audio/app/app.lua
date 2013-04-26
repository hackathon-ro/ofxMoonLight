require 'Ball'

local windowWidth
local windowHeight

app = ofLuaApp()

function app:setup()
    ofSetWindowTitle('Hello World')

    windowWidth = ofGetWindowWidth()
    windowHeight = ofGetWindowHeight()

    ofEnableSmoothing()
    ofSetFrameRate(30)

    self.balls = {}

    for i=0,1000 do
        table.insert(self.balls, Ball())
    end

    beats = ofSoundPlayer()
    synth = ofSoundPlayer()
    vocals = ofSoundPlayer()
    synthPosition = 0
    font = ofTrueTypeFont()

    synth:loadSound("sounds/synth.wav")
    beats:loadSound("sounds/1085.mp3")
    vocals:loadSound("sounds/Violet.mp3")
    synth:setVolume(0.75)
    beats:setVolume(0.75)
    vocals:setVolume(0.5)
    font:loadFont("fonts/Sudbury_Basin_3D.ttf", 32)
    beats:setMultiPlay(false)
    vocals:setMultiPlay(true)

    -- TODO:
    -- soundStream = ofSoundStream()
    -- soundStream:listDevices()
    -- soundStream:setup(self, 0, 2, 44100, 256, 4);

end

function app:update()
    local distance = 100 * math.sin(ofGetElapsedTimef())

    for _,ball in ipairs(self.balls) do
        ball:moveTo(ofRandom(windowWidth * 1/4 - distance,
                             windowWidth * 3/4 + distance),
                    ofRandom(windowHeight * 1/4 - distance,
                             windowHeight * 3/4 + distance))
    end
end

function app:draw()
    widthDiv = ofGetWidth() / 3.0

    ofBackground(255,255,255);

    -- draw the background colors:
    if synthPressed then
        ofSetHexColor(0xFF0000)
        synthPressed = false
    else
        ofSetHexColor(0xeeeeee)
    end
    ofRect(0,0,widthDiv,ofGetHeight())

    if beatsPressed then
        ofSetHexColor(0xFF0000)
        beatsPressed = false
    else
        ofSetHexColor(0xffffff)
    end
    ofRect(widthDiv,0,widthDiv,ofGetHeight())

    if vocalsPressed then
        ofSetHexColor(0xFF0000)
        vocalsPressed = false
    else
        ofSetHexColor(0xdddddd)
    end
    ofRect(widthDiv*2,0,widthDiv,ofGetHeight())

    -- draw some balls
	for _,ball in ipairs(self.balls) do
        ball:draw()
	end

    ---------------------------------- synth:
    if synth:getIsPlaying() then
        ofSetHexColor(0xFF0000)
    else
        ofSetHexColor(0x000000)
    end
    font:drawString("synth !!", 50,50)


    ofSetHexColor(0x000000)
    tempStr = "click to play\npct done: "..synth:getPosition().."\nspeed: " .. synth:getSpeed() .. "\npan: " .. synth:getPan()
    ofDrawBitmapString(tempStr, 50,ofGetHeight()-50)

    ---------------------------------- beats:
    if beats:getIsPlaying() then
        ofSetHexColor(0xFF0000)
    else
        ofSetHexColor(0x000000)
        font:drawString("beats !!", widthDiv+50,50)
    end

    ofSetHexColor(0x000000);
    tempStr = "click and drag\npct done: " .. beats:getPosition() .. "\nspeed: " .. beats:getSpeed()
    ofDrawBitmapString(tempStr, widthDiv+50,ofGetHeight()-50)

    ---------------------------------- vocals:
    if vocals:getIsPlaying() then
        ofSetHexColor(0xFF0000)
    else
        ofSetHexColor(0x000000)
    end
    font:drawString("vocals !!", widthDiv*2+50,50)

    ofSetHexColor(0x000000)
    tempStr = "click to play (multiplay)\npct done: " .. (vocals:getPosition()) .. "\nspeed: " .. vocals:getSpeed()
    ofDrawBitmapString(tempStr, widthDiv*2+50,ofGetHeight()-50)

end

function app:mouseDragged(x, y, button)
	-- continuously control the speed of the beat sample via drag,
	-- when in the "beat" region:
    widthStep = ofGetWidth() / 3.0;
	if x >= widthStep and x < widthStep*2 then
        beats:setSpeed( 0.5 + ((ofGetHeight() - y) / ofGetHeight())*1.0)
	end
end

function app:mousePressed(x, y, button)
    widthStep = ofGetWidth() / 3.0
	if x < widthStep then
		synth:play()
		synth:setSpeed( 0.1 + ((ofGetHeight() - y) / ofGetHeight())*10)
		synth:setPan(ofMap(x, 0, widthStep, -1, 1, true))
        synthPressed = true
	elseif x >= widthStep and x < widthStep*2 then
		beats:play()
        beatsPressed = true
    else 
		vocals:play()
		vocals:setSpeed( 0.1 + ((ofGetHeight() - y) / ofGetHeight())*3)
		-- map x within the last third of window to -1 to 1 ( for left / right panning )
		vocals:setPan( ofMap(x, widthStep*2, widthStep*3, -1, 1, true) )
        vocalsPressed = true
	end
end
