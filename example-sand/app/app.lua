n = 5000 -- number of cells
bd = 37 -- base line length
sp = 0.004 -- rotation speed step
sl = 0.97 -- slow down rate

pmouseX = 0
mouseX = 0
pmouseY = 0
mouseY = 0

all = {}

local width
local height


function det( x1,  y1, x2, y2, x3,  y3)
    return ((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1))
end

class 'Cell'

function Cell:Cell(x, y)
    self.x = x or 0
    self.y = y or 0
    self.s = 0
    self.c = 0
end

function Cell:sense()
    if pmouseX ~= 0 or pmouseY ~= 0 then
        self.s = self.s + sp * det(self.x, self.y, pmouseX, pmouseY, mouseX, mouseY) / (ofDist(self.x, self.y, mouseX, mouseY) + 1)
        self.s = self.s * sl;
        self.c = self.c + self.s;
        local d = bd * self.s + 0.001;

        ofLine(self.x, self.y, self.x + d * math.cos(self.c), self.y + d * math.sin(self.c))
    end
end

app = ofLuaApp()

function app:setup()
    ofSetWindowTitle('New app')

    width = ofGetWindowWidth()
    height = ofGetWindowHeight()

    -- ofEnableSmoothing()
    ofSetFrameRate(30)

    for i = 1, n do
        a = i + ofRandom(0, math.pi / 9)
        r = ((i /  n) * (width / 2) * (((n-i) / n) * 3.3)) + ofRandom(-3,3) + 3;
        all[i] = Cell((r*math.cos(a)) + (width/2), (r*math.sin(a)) + (height/2));
    end
end

function app:update()
end

function app:draw()

    ofSetLineWidth(1)
    for i = 1, n do
        ofSetColor(ofColor().fromHsb(math.sin(i) * 128 + 128, 255, 255))
        all[i]:sense()
    end
end

function app:keyPressed(key)
end

function app:keyReleased(key)
end

function app:mouseMoved(x, y)

    pmouseX = mouseX
    pmouseY = mouseY
    mouseX = x
    mouseY = y

end

function app:mouseDragged(x, y, button)
    
end

function app:mousePressed(x, y, button)
    for i = 1, n do
        all[i].c = 0
    end
end

function app:mouseReleased(x, y, button)
    mouseX = 0
    mouseY = 0
end

function app:windowResized(w, h)
end
