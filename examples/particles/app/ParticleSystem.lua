class 'ParticleSystem'

function ParticleSystem:ParticleSystem(imgs, v)
    self.textures = imgs
    self.particles = {}

end

function ParticleSystem:run()
        for i = table.getn(self.particles),1,-1 do
            local p = self.particles[i];
            p:run()
            if p:isDead() == true then
                table.remove(self.particles,i);
            end
        end
end
    
function ParticleSystem: addParticle( x,  y) 

    r = math.floor(ofRandom(table.getn(self.textures)));
    
    if r==0 then
        r = 1;
    elseif r > table.getn(self.textures) then
        r = table.getn(self.textures)
    end
    table.insert(self.particles,Particle(x,y,self.textures[r]));
end

    
function ParticleSystem:applyForces(f)

    for i=1,table.getn(self.particles) do
        self.particles[i]:applyForce(f);
    end
end
    
--[[
function ParticleSystem: addParticle(p)
    print("insert",p)
        table.insert(self.particles,p)
end
]]--

function ParticleSystem: dead()
    if table.getn(self.particles) == 0 then
        return true;
    else
        return false;
    end
end