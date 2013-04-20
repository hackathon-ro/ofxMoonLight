class 'Ball'

function Ball:Ball(...)
    self.color = ofColor(ofRandom(0, 255),
                         ofRandom(0, 255),
                         ofRandom(0, 255))
end

function Ball:moveTo(x, y)
    self.x = x
    self.y = y
end

function Ball:draw()
    ofSetColor(self.color)
    ofCircle(self.x, self.y, ofRandom(5, 30))
end
