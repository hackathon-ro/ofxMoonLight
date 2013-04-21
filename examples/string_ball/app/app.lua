
app = ofLuaApp()

count = 400;
radius = 20;

function app:setup()


    width = ofGetWindowWidth()
    height = ofGetWindowHeight()
    self.h_width = width/2
    self.h_height = height/2

    mouseX = 0
    mouseY = 0

    self.rx = 0;
    self.ry = 0;

    radius = height/8;

    lista = {}
    for i = 1,count do
        lista[i] = String(self.h_width, self.h_height)
    end

    ofBackground(0);
    ofSetBackgroundAuto(false);
end

function app:update()
    rxp = (mouseX-(self.h_width)) * 0.0005;
    ryp = (mouseY-(self.h_height)) * 0.0005;

    self.rx = (self.rx*0.9) + rxp;
    self.ry = (self.ry*0.9) + ryp;
end

function app:draw()
    --ofEnableAlphaBlending(); 
    --ofSetColor(0,0,0, 20);
    --ofFill()
    --ofRect(0,0,width,height);

    ofPushMatrix()
        ofTranslate(self.h_width, self.h_height)
        ofPushMatrix()
            ofRotateY(self.rx * (180/math.pi))
            ofRotateX(self.ry * (180/math.pi))
            for _,v in ipairs(lista) do
                v:draw();
            end
        ofPopMatrix()
    ofPopMatrix()
    --ofDisableAlphaBlending();  
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
