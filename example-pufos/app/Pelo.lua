class 'Pelo'

function Pelo:Pelo(...)

    self.z = ofRandom(-radio, radio);
    self.phi = ofRandom(math.pi * 2);
    self.largo = ofRandom(1.15, 1.2);
    self.theta = math.asin(self.z/radio);

end


function Pelo:dibujar()
    
    local off = (ofNoise(ofGetElapsedTimeMillis() * 0.0005, math.sin(self.phi))-0.5) * 0.3;
    local offb = (ofNoise(ofGetElapsedTimeMillis() * 0.0007, math.sin(self.z) * 0.01)-0.5) * 0.3;
    
    local thetaff = self.theta+off;
    local phff = self.phi+offb;
    local x = radio * math.cos(self.theta) * math.cos(self.phi);
    local y = radio * math.cos(self.theta) * math.sin(self.phi);
    local z = radio * math.sin(self.theta);
    
    local xo = radio * math.cos(thetaff) * math.cos(phff);
    local yo = radio * math.cos(thetaff) * math.sin(phff);
    local zo = radio * math.sin(thetaff);
    
    local xb = xo * self.largo;
    local yb = yo * self.largo;
    local zb = zo * self.largo;
    
    ofSetLineWidth(1);
    ofBeginShape(OF_PRIMITIVE_LINES);
    ofSetColor(0);
    ofVertex(x, y, z);
    
    ofEnableAlphaBlending();
    ofSetColor(200,255,255,150);
    ofVertex(xb, yb, zb);
    ofDisableAlphaBlending();
    ofEndShape();
end