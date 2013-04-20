#pragma once

#include "ofTexture.h"

class ofFbo : public ofBaseDraws, public ofBaseHasTexture {
public:
	struct Settings;

	ofFbo();
	ofFbo(const ofFbo & mom);
	ofFbo & operator=(const ofFbo & fbo);
	virtual ~ofFbo();

	void allocate(int width, int height, int internalformat = GL_RGBA, int numSamples = 0);
	//void allocateForShadow( int width, int height );
	void allocate(Settings settings = Settings());
	bool isAllocated();

	void draw(float x, float y);
	void draw(float x, float y, float width, float height);

	void setAnchorPercent(float xPct, float yPct);
    void setAnchorPoint(float x, float y);
	void resetAnchor();

	void setDefaultTextureIndex(int defaultTexture);
	int getDefaultTextureIndex();

	ofTexture & getTextureReference();
	ofTexture & getTextureReference(int attachmentPoint);
	ofTexture & getDepthTexture();
	void setUseTexture(bool bUseTex){ /*irrelevant*/ };

	void begin(bool setupScreen=true);
	void end();

	void readToPixels(ofPixels & pixels, int attachmentPoint = 0);
	void readToPixels(ofShortPixels & pixels, int attachmentPoint = 0);
	void readToPixels(ofFloatPixels & pixels, int attachmentPoint = 0);

	float getWidth();
	float getHeight();

	// advanced functions
	void bind();
	void unbind();

	int	getNumTextures();

  void setActiveDrawBuffer(int i);
  void setActiveDrawBuffers(const vector<int>& i);
  void activateAllDrawBuffers();

	GLuint getFbo();	// returns GLuint of Fbo for advanced actions


	static bool	checkGLSupport();
	static int maxColorAttachments();	// return max color attachments
	static int maxDrawBuffers();		// return max simultaneous draw buffers
	static int maxSamples();			// return max MSAA samples

	GLuint getDepthBuffer(){ return depthBuffer; }
	GLuint getStencilBuffer(){ return stencilBuffer; }

	struct Settings {
		int		width;					// width of images attached to fbo
		int		height;					// height of images attached to fbo
		int		numColorbuffers;		// how many color buffers to create
		bool	useDepth;				// whether to use depth buffer or not
		bool	useStencil;				// whether to use stencil buffer or not
		bool	depthStencilAsTexture;			// use a texture instead of a renderbuffer for depth (useful to draw it or use it in a shader later)
		GLenum	textureTarget;			// GL_TEXTURE_2D or GL_TEXTURE_RECTANGLE_ARB
		GLint	internalformat;			// GL_RGBA, GL_RGBA16F_ARB, GL_RGBA32F_ARB, GL_LUMINANCE32F_ARB etc.
		GLint	depthStencilInternalFormat; 	// GL_DEPTH_COMPONENT(16/24/32)
		int		wrapModeHorizontal;		// GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER etc.
		int		wrapModeVertical;		// GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER etc.
		int		minFilter;				// GL_NEAREST, GL_LINEAR etc.
		int		maxFilter;				// GL_NEAREST, GL_LINEAR etc.
		int		numSamples;				// number of samples for multisampling (set 0 to disable)

		Settings();
	};
};

