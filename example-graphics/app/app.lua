app = ofLuaApp()
        
function app:setup()
    
    counter = 0;
	ofSetCircleResolution(50);
	ofBackground(255,255,255);
	bSmooth = false;
	ofSetWindowTitle("graphics example");

	ofSetFrameRate(60)

end

function app:update()
  
  counter = counter + 0.033

end

function app:draw()

	
	ofSetColor(255,130,0);
    radius = 50 + 10 * math.sin(counter);
	ofFill();		
	ofCircle(100,400,radius);


	ofNoFill();
	ofSetHexColor(0xCCCCCC);
	ofCircle(100,400,80);

	ofSetHexColor(0x000000);
	ofDrawBitmapString("circle", 75,500);


    ofFill();

	for i = 0,200 do
		ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		ofRect(ofRandom(250,350),ofRandom(350,450),ofRandom(10,20),ofRandom(10,20));
	end
    
	ofSetHexColor(0x000000);
	ofDrawBitmapString("rectangles", 275,500);

	
	ofSetHexColor(0x00FF33);
	ofRect(400,350,100,100);
	
	ofEnableAlphaBlending();
	ofSetColor(255,0,0,127);   
	ofRect(450,430,100,33);
	ofSetColor(255,0,0,(counter * 10.0) % 255); 
	ofRect(450,370,100,33);
	ofDisableAlphaBlending();

	ofSetHexColor(0x000000);
	ofDrawBitmapString("transparency", 410,500);


	if bSmooth then
		ofEnableSmoothing();
	end

	ofSetHexColor(0xFF0000);
	for i = 0,20 do
		ofLine(600,300 + (i*5),800, 250 + (i*10));
	end

	if bSmooth then
		ofDisableSmoothing();
	end

	ofSetHexColor(0x000000);
	ofDrawBitmapString("lines\npress 's' to toggle smoothness", 600,500);


end

function app:mouseDragged(x, y, button)

end

function app:mousePressed(x, y, button)

end



function app:keyPressed(key)

	if key == string.byte('s') then
		bSmooth = not bSmooth
    end
	
end