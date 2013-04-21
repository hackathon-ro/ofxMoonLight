
app = ofLuaApp()

count = 500;
radius = 20;

function app:setup()

    width = ofGetWindowWidth()
    height = ofGetWindowHeight()
    self.h_width = width/2
    self.h_height = height/2

    self.bCenterX = self.h_width
    self.bCenterY = self.h_height

    mouseX = 0
    mouseY = 0

    self.rx = 0;
    self.ry = 0;

    radius = height/8;

    lista = {}
    for i = 1,count do
        lista[i] = String(self.h_width, self.h_height)
    end

    shader = ofShader()
    shader:load("shaders_gles/string")

    ofBackground(0);
end

function app:update()
    rxp = (mouseX-(self.h_width)) * 0.0005;
    ryp = (mouseY-(self.h_height)) * 0.0005;

    self.rx = (self.rx*0.9) + rxp;
    self.ry = (self.ry*0.9) + ryp;
end

function app:draw()

    tMat = ofMatrix4x4()
    tMat:setTranslation(self.bCenterX, self.bCenterY, 0)
    tMat:glRotateRad(self.ry, 1, 0, 0)
    tMat:glRotateRad(self.rx, 0, 1, 0)
    

    shader:begin()
        shader:setUniformMatrix4f("trans", tMat)
        shader:setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 )
        shader:setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 )
        shader:setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY )

        for _,v in ipairs(lista) do
            v:draw();
        end
    shader:finish()
end

function app:mouseDragged(x, y, button)
    self.bCenterX = x
    self.bCenterY = y
    mouseX = x
    mouseY = y
end

function app:mouseMoved(x, y, button)
    mouseX = x
    mouseY = y
end
