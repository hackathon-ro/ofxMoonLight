class 'String'

function String:String(...)


    self.z = ofRandom(-radius, radius);
    self.phi = ofRandom(math.pi * 2);
    self.extend = 1.10;
    self.theta = math.asin(self.z/radius);

    self.x = radius * math.cos(self.theta) * math.cos(self.phi)
    self.y = radius * math.cos(self.theta) * math.sin(self.phi)
    self.z = radius * math.sin(self.theta);

    self.color = ofColor(190, 190, 190)

    self.phi_sin = math.sin(self.phi)
    self.z_sin = math.sin(self.z) * 0.01

end

function String:update()
end


function String:draw()
    

    ofSetColor(150, 150, 150);
    ofSetLineWidth(1);
    self.xb = self.x * self.extend
    self.yb = self.y * self.extend
    self.zb = self.z * self.extend
    ofLine(self.x, self.y, self.z, self.xb, self.yb, self.zb);


    ofSetColor(210, 210, 210);
    ofSetLineWidth(3);
    self.xc = self.xb * self.extend
    self.yc = self.yb * self.extend
    self.zc = self.zb * self.extend
    ofLine(self.xb, self.yb, self.zb, self.xc, self.yc, self.zc);
end
