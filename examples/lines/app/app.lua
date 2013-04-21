app = ofLuaApp()

function app:setup()

    width = ofGetWindowWidth()
    height = ofGetWindowHeight()

    mouseX = 0
    mouseY = 0

    ofHideCursor()

end

function app:update()
end

function app:draw()

    pos1=ofRandom(width);
    pos2=ofRandom(height);
    pos3=ofRandom(width);
    pos4=ofRandom(height);
    pos5=ofRandom(width);
    pos6=ofRandom(height);
    pos7=ofRandom(width);
    pos8=ofRandom(height);

    distGeo1 = ofDist(pos1,pos2,mouseX,mouseY);

    ofEnableAlphaBlending(); 
    ofSetColor(255,255,255,10);
    ofFill()
    ofRect(0,0,width,height);
    ofDisableAlphaBlending();  


    if ofGetMousePressed() == true then
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
        ofSetLineWidth(3);
    else
        ofSetColor(0);
        ofFill();
        ofSetLineWidth(1);
    end

    ofLine(pos1,pos2,mouseX,mouseY)
    ofLine(pos3,pos4,mouseX,mouseY)
    ofLine(pos5,pos6,mouseX,mouseY)
    ofLine(pos7,pos8,mouseX,mouseY)
    pos9 = mouseX + ofRandom(width)
    pos10 = mouseX + ofRandom(height)

    ofEllipse(pos9,pos10,20,20);

    if (distGeo1 > 200) == true then
        ofTriangle(pos1,pos2,pos1+20,pos2+10,pos1-10,pos2-20)
    end

    if (distGeo1 < 200) == true then
        ofRect(pos3,pos4,pos3/10,pos4/10,3)
        ofEllipse(pos5,pos6,pos5/10,pos6/10)
    end

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
