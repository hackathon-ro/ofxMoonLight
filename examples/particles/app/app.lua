require 'Particle'
require 'ParticleSystem'

app = ofLuaApp()


function app:setup()

    --ofSetSmoothLighting()

    width = ofGetWindowWidth()
    height = ofGetWindowHeight()

    mouseX = 0
    mouseY = 0

    ofBackground(0);

    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    imgs = {};

    img1 = ofImage();
    img1:loadImage("corona.png");
    img2 = ofImage();
    img2:loadImage("emitter.png");
    img3 = ofImage();
    img3:loadImage("particle.png");
    img4 = ofImage();
    img4:loadImage("texture.png");
    img5 = ofImage();
    img5:loadImage("reflection.png");
    
    imgs[1] = img1
    imgs[2] = img2
    imgs[3] = img3
    imgs[4] = img4
    imgs[5] = img5

    ps = ParticleSystem(imgs, ofVec2f(width/2, 50));
    

end

function app:update()
end

function app:draw()

    up = ofVec2f(0,-0.2);
    ps:applyForces(up);
    ps:run();
    for i=1,2 do
        ps:addParticle(mouseX,mouseY);
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

