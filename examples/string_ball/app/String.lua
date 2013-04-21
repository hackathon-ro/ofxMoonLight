class 'String'

function String:String(width, height)


    self.w = width
    self.h = height

    self.z = ofRandom(-radius, radius);
    self.phi = ofRandom(math.pi * 2);
    self.largo = ofRandom(1.15, 1.2);
    self.theta = math.asin(self.z/radius);

    self.x = radius * math.cos(self.theta) * math.cos(self.phi)
    self.y = radius * math.cos(self.theta) * math.sin(self.phi)
    self.z = radius * math.sin(self.theta);

    self.color = ofColor().fromHsb(self.z + 128, 255, 255)

    self.phi_sin = math.sin(self.phi)
    self.z_sin = math.sin(self.z) * 0.01
end

function String:update()
end


function String:draw()
    

    local milis = ofGetElapsedTimeMillis() 
    local off = (ofNoise(milis * 0.0005, self.phi_sin) - 0.5) * 0.3;
    local offb = (ofNoise(milis * 0.0007, self.z_sin) - 0.5) * 0.3;
    
    local thetaff = self.theta+off;
    local phff = self.phi+offb;
    radius_cos_thetaff = radius * math.cos(thetaff)
    
    local xo = radius_cos_thetaff * math.cos(phff);
    local yo = radius_cos_thetaff * math.sin(phff);
    local zo = radius * math.sin(thetaff);
    
    self.xb = xo * self.largo
    self.yb = yo * self.largo
    self.zb = zo * self.largo;
    
    ofSetLineWidth(2);
    ofSetColor(self.color);
    ofLine(self.x, self.y, self.z, self.xb, self.yb, self.zb);
end
