local windowWidth
local windowHeight

app = ofLuaApp()

function app:setup()
    ofSetWindowTitle('New app')

    windowWidth = ofGetWindowWidth()
    windowHeight = ofGetWindowHeight()

    ofEnableSmoothing()
    ofSetFrameRate(30)
end

function app:update()
end

function app:draw()
end

function app:keyPressed(key)
end

function app:keyReleased(key)
end

function app:mouseMoved(x, y)
end

function app:mouseDragged(x, y, button)
end

function app:mousePressed(x, y, button)
end

function app:mouseReleased(x, y, button)
end

function app:windowResized(w, h)
end
