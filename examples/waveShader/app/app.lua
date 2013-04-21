local windowWidth
local windowHeight

mouseX = 0
mouseY = 0

app = ofLuaApp()

function app:setup()
    ofSetWindowTitle('Balls')

    ofBackground(34, 34, 34);

    windowWidth = ofGetWindowWidth()
    windowHeight = ofGetWindowHeight()

    ofSetVerticalSync(false)
    ofEnableAlphaBlending()

    shader = ofShader()

    shader:load("shaders/noise.vert","shaders/noise.frag")

    doShader = true
end

function app:update()
end

function app:draw()
    ofSetColor(225)
    ofDrawBitmapString("'s' toggles shader", 10, 20)

    ofSetColor(245, 58, 135)
    ofFill()

    if doShader then
        shader:begin()
        -- we want to pass in some varrying values to animate our type / color
        shader:setUniform1f("time", ofGetElapsedTimef())
        shader:setUniform2f("resolution", windowWidth, windowHeight )

        -- we also pass in the mouse position
        -- we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped.
        shader:setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY )

    end
    
    ofRect(0,0, windowWidth, windowHeight)

    if doShader then
        shader:finish()
    end
end

function app:mouseMoved(x, y)

    mouseX = x
    mouseY = y

end

function app:keyPressed(key)

    if key == string.byte('s') then
        doShader = not doShader
    end

end
