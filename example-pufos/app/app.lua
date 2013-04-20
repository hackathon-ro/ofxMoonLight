require 'Pelo'

app = ofLuaApp()

cuantos = 1800;
radio = 200;
rx = 0;
ry = 0;

function app:setup()

ofSetSmoothLighting()

    width = ofGetWindowWidth()
    height = ofGetWindowHeight()

    mouseX = 0
    mouseY = 0

    radio = height/3.5;

    lista = {}
    for i = 1,cuantos do
        lista[i] = Pelo()
    end

end

function app:update()
end

function app:draw()

    ofBackground(0);

    rxp = (mouseX-(width/2)) * 0.005;
    ryp = (mouseY-(height/2)) * 0.005;
    
    rx = rx*0.9 + rxp*0.1;
    ry = ry*0.9 + ryp*0.1;

    ofTranslate(width/2, height/2);
--    ofRotateY(rx);
--    ofRotateX(ry);
    ofFill();
    ofSetColor(10);
    ofSphere(radio);

    for _,v in ipairs(lista) do
        v:dibujar();
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
