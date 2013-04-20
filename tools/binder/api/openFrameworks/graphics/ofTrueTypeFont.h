#pragma once


#include <vector>
#include "ofPoint.h"
#include "ofRectangle.h"
#include "ofConstants.h"
#include "ofPath.h"
#include "ofTexture.h"
#include "ofMesh.h"

//--------------------------------------------------
typedef struct {
	int character;
	int height;
	int width;
	int setWidth;
	int topExtent;
	int leftExtent;
	float tW,tH;
	float x1,x2,y1,y2;
	float t1,t2,v1,v2;
} charProps;


typedef ofPath ofTTFCharacter;

//--------------------------------------------------
#define NUM_CHARACTER_TO_START		33		// 0 - 32 are control characters, no graphics needed.

class ofTrueTypeFont{

public:


	ofTrueTypeFont();
	virtual ~ofTrueTypeFont();
	
	//set the default dpi for all typefaces.
	static void setGlobalDpi(int newDpi);
			
	// 			-- default (without dpi), non-full char set, anti aliased, 96 dpi:
	bool 		loadFont(string filename, int fontsize, bool _bAntiAliased=true, bool _bFullCharacterSet=false, bool makeContours=false, float simplifyAmt=0.3, int dpi=0);
	
	bool		isLoaded();
	bool		isAntiAliased();
	bool		hasFullCharacterSet();

    int         getSize();
    float       getLineHeight();
  	void 		setLineHeight(float height);
	float 		getLetterSpacing();
	void 		setLetterSpacing(float spacing);
	float 		getSpaceSize();
	void 		setSpaceSize(float size);
	float 		stringWidth(string s);
	float 		stringHeight(string s);
	
	ofRectangle    getStringBoundingBox(string s, float x, float y);
	
	void 		drawString(string s, float x, float y);
	void		drawStringAsShapes(string s, float x, float y);
	
	//			get the num chars in the loaded char set
	int			getNumCharacters();	
	
	ofTTFCharacter getCharacterAsPoints(int character);
	vector<ofTTFCharacter> getStringAsPoints(string str);

	void bind();
	void unbind();
};


