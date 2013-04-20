class 'ParticleSystem'

function ParticleSystem:ParticleSystem(imgs, v)
    self.textures = imgs
    self.particles = {}
end

function ParticleSystem:run()
        for i = table.getn(self.particles),1,-1 do
            local p = particles[i];
            p:run()
            if p:isDead() then
                table.remove(self.particles,i);
            end
        end
end
    
function ParticleSystem: addParticle( x,  y) 
    r = ofRandom(table.getn(textures));
    table.insert(particles,Particle(x,y,textures[r]));
end

    
function ParticleSystem:applyForces(f)
    for _,p in ipairs(self.particles) do
        p:applyForce(f);
    end
end
    
function ParticleSystem: addParticle(p)
        table.insert(self.particles,p)
end
    
function ParticleSystem: dead()
    if table.getn(self.particles) == 0 then
        return true;
    else
        return false;
    end
end