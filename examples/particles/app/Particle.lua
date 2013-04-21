class 'Particle'

function Particle:Particle(x,  y,  img_)

    self.acc = ofVec2f(0, 0);
    self.vel = ofVec2f(ofRandom(10),ofRandom(10));
    self.loc = ofVec2f(x, y);
    self.lifespan = 255;
    self.image = img_;

end
    
function Particle:run()
        self:update();
        self:render();
end
    
function Particle:applyForce(f)
    self.acc:add(f);
end
    

function Particle:update()
    self.vel:add(self.acc);
    self.loc:add(self.vel);
    self.acc:mul(0);
    self.lifespan = self.lifespan - 10.0;
end
    

function Particle:render()
    --tint(lifespan);
    
    self.image:setAnchorPoint(self.image:getWidth()/2, self.image:getHeight()/2);
    self.image:draw(self.loc.x, self.loc.y);
    self.image:resize(64,64)
    
end
    
function Particle:isDead()
    if self.lifespan <= 0.0 then
        return true;
    else
        return false;
    end
end
