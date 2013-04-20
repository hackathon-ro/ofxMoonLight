require 'Particle'
require 'ParticleSystem'

app = ofLuaApp()

ps = {}
imgs = {}


function app:setup()

    ofSetSmoothLighting()

    width = ofGetWindowWidth()
    height = ofGetWindowHeight()

    mouseX = 0
    mouseY = 0

    imgs = {};


    imgs[1] = ofImage():loadImage("corona.png");
    imgs[2] = ofImage():loadImage("emitter.png");
    imgs[3] = ofImage():loadImage("particle.png");
    imgs[4] = ofImage():loadImage("texture.png");
    imgs[5] = ofImage():loadImage("reflection.png");

    ps = ParticleSystem(imgs, ofVec2f(width/2, 50));

end

function app:update()
end

function app:draw()

    ofBackground(255);

    ofEnableBlendMode(OF_BLENDMODE_ADD);

    up = ofVec2f(0,-0.2);
    ps:applyForces(up);
    ps:run();
    for i=0,5 do
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

