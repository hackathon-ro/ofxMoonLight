#pragma once

#include "ofConstants.h"
#include "ofTexture.h"
#include "ofBaseTypes.h"
#include "ofTypes.h"

//---------------------------------------------
class ofVideoPlayer : public ofBaseVideoPlayer,public ofBaseVideoDraws{

	public:

		ofVideoPlayer ();

		void						setPlayer(ofPtr<ofBaseVideoPlayer> newPlayer);
		ofPtr<ofBaseVideoPlayer>	getPlayer();

		bool 				loadMovie(string name);
	    string				getMoviePath();

		bool				setPixelFormat(ofPixelFormat pixelFormat);
		ofPixelFormat		getPixelFormat(); 
		
		void 				closeMovie();
		void 				close();		

		void				update();
//		OF_DEPRECATED_MSG("Use ofVideoPlayer::update() instead.", void idleMovie());
		void 				play();
		void 				stop();

		bool 				isFrameNew();
//		unsigned char * 	getPixels();
//		ofPixelsRef			getPixelsRef();
		float 				getPosition();
		float 				getSpeed();
		float 				getDuration();
		bool				getIsMovieDone();

		void 				setPosition(float pct);
		void 				setVolume(float volume); // 0..1
		void 				setLoopState(ofLoopType state);
		ofLoopType			getLoopState();
		void   				setSpeed(float speed);
		void				setFrame(int frame);  // frame 0 = first frame...

		void 				setUseTexture(bool bUse);
		ofTexture &			getTextureReference();
		void 				draw(float x, float y, float w, float h);
		void 				draw(float x, float y);
		using ofBaseDraws::draw;

		//the anchor is the point the image is drawn around.
		//this can be useful if you want to rotate an image around a particular point.
        void				setAnchorPercent(float xPct, float yPct);	//set the anchor as a percentage of the image width/height ( 0.0-1.0 range )
        void				setAnchorPoint(float x, float y);				//set the anchor point in pixels
        void				resetAnchor();								//resets the anchor to (0, 0)

		void 				setPaused(bool bPause);

		int					getCurrentFrame();
		int					getTotalNumFrames();

		void				firstFrame();
		void				nextFrame();
		void				previousFrame();

		float 				getHeight();
		float 				getWidth();

		bool				isPaused();
		bool				isLoaded();
		bool				isPlaying();

		//this is kept as legacy to support people accessing width and height directly. 
		int					height;
		int					width;
};





