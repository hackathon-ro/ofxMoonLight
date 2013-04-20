require 'Ball'

local windowWidth
local windowHeight

app = ofLuaApp()

function app:setup()
    ofSetWindowTitle('Balls')

    windowWidth = ofGetWindowWidth()
    windowHeight = ofGetWindowHeight()

    ofEnableSmoothing()
    ofSetFrameRate(30)

    self.ball1 = Ball()
    self.ball2 = Ball()
end

function app:update()
    local distance = 100 * math.sin(ofGetElapsedTimef())

    self.ball1:moveTo(ofRandom(windowWidth * 1/4 - distance, windowWidth * 3/4 + distance),
                ofRandom(windowHeight * 1/4 - distance, windowHeight * 3/4 + distance))

    self.ball2:moveTo(ofRandom(windowWidth * 1/4 - distance, windowWidth * 3/4 + distance),
                ofRandom(windowHeight * 1/4 - distance, windowHeight * 3/4 + distance))
end

function app:draw()
    widthDiv = ofGetWidth() / 3.0

    ofBackground(255,255,255);

    self.ball1:draw()
    self.ball2:draw()
end
