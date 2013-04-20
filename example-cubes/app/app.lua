app = ofLuaApp()

ofLogo = ofImage(); 
light = ofLight();
cam = ofEasyCam(); 
        
function app:setup()
   ofSetVerticalSync(true);

    glEnable(GL_DEPTH_TEST);

	ofEnableNormalizedTexCoords();
	
	ofLogo:loadImage("of.png");
	
	ofSetLineWidth(10);
end

function app:update()
  
end

function app:draw()

    ofBackground(0, 0, 0);
	
	movementSpeed = .1;
	cloudSize = ofGetWidth() / 2;
	maxBoxSize = 100;
	spacing = 1;
	boxCount = 100;
	
	cam:begin()
	
	for i = 1,boxCount do

		ofPushMatrix();
		
		t = (ofGetElapsedTimef() + i * spacing) * movementSpeed;
        
		pos = ofVec3f(
			ofSignedNoise(t, 0, 0),
			ofSignedNoise(0, t, 0),
			ofSignedNoise(0, 0, t));
		
		boxSize = maxBoxSize * ofNoise(pos.x, pos.y, pos.z);
		
		pos =pos * cloudSize;
		ofTranslate(pos);
		ofRotateX(pos.x);
		ofRotateY(pos.y);
		ofRotateZ(pos.z);
		
		ofLogo:bind();
		ofFill();
		ofSetColor(255);
		ofBox(boxSize);
		ofLogo:unbind();
		
		ofNoFill();
		ofSetColor(ofColor().fromHsb(math.sin(t) * 128 + 128, 255, 255));
		ofBox(boxSize * 1.1);
		
		ofPopMatrix()
	end
	
	cam:end()

end

function app:mouseDragged(x, y, button)

end

function app:mousePressed(x, y, button)

end