class 'Particle'

function Particle:Particle(x,  y,  img_)

    self.acc = ofVec2f(0, 0);
    self.vel = ofVec2f(ofRandom(),ofRandom());
    self.loc = ofVec2f(x, y);
    self.lifespan = 255;
    self.img = img_;

end
    
function Particle:run()
        update();
        render();
end
    
function Particle:applyForce(f)
    self.acc:add(f);
end
    

function Particle:update()
    self.vel:add(acc);
    self.loc:add(vel);
    self.acc:mul(0);
    self.lifespan = self.lifespan - 2.0;
end
    

function Particle:render()
    --tint(lifespan);
    
    self.image.setAnchorPoint(self.image.getWidth()/2, self.image.getHeight()/2);
    self.image.draw(self.loc.x, self.loc.y);
    self.image.resize(32,32)
    
end
    
function Particle:isDead()
    if self.lifespan <= 0.0 then
        return true;
    else
        return false;
    end
end
