#pragma once

#include "ofConstants.h"
#include "ofUtils.h"
#include "ofColor.h"
#include "ofMath.h"
#include <limits>

//---------------------------------------
enum ofInterpolationMethod {
	OF_INTERPOLATE_NEAREST_NEIGHBOR =1,
	OF_INTERPOLATE_BILINEAR			=2,
	OF_INTERPOLATE_BICUBIC			=3
};

class ofPixels {

	friend class ofPixelUtils;

public:

	ofPixels();
	~ofPixels();
	ofPixels(const ofPixels & mom);
	ofPixels& operator=(const ofPixels & mom);

	void allocate(int w, int h, int channels);

	void set(unsigned char val);
	void set(int channel,unsigned char val);
	void setFromPixels(const unsigned char * newPixels,int w, int h, int channels);
	void setFromExternalPixels(unsigned char * newPixels,int w, int h, int channels);
	void setFromAlignedPixels(const unsigned char * newPixels, int width, int height, int channels, int stride);
	void swap(ofPixels & pix);

	//From ofPixelsUtils
	// crop to a new width and height, this reallocates memory.
	void crop(int x, int y, int width, int height);
	// not in place
	
	void cropTo(ofPixels &toPix, int x, int y, int _width, int _height);

	// crop to a new width and height, this reallocates memory.
	void rotate90(int nClockwiseRotations);
	void rotate90To(ofPixels & dst, int nClockwiseRotations);
	void mirrorTo(ofPixels & dst, bool vertically, bool horizontal);
	void mirror(bool vertically, bool horizontal);
	bool resize(int dstWidth, int dstHeight, ofInterpolationMethod interpMethod=OF_INTERPOLATE_NEAREST_NEIGHBOR);	
	bool resizeTo(ofPixels & dst, ofInterpolationMethod interpMethod=OF_INTERPOLATE_NEAREST_NEIGHBOR);
	bool pasteInto(ofPixels &dst, int x, int y);

	void swapRgb();

	void clear();
	
	unsigned char * getPixels();
	const unsigned char * getPixels() const;

	int getPixelIndex(int x, int y) const;
	ofColor getColor(int x, int y) const;
	void setColor(int x, int y, ofColor color);

	const unsigned char& operator[](int pos) const;
	unsigned char& operator[](int pos);

	bool isAllocated() const;

	int getWidth() const;
	int getHeight() const;

	int getBytesPerPixel() const;
	int getBitsPerPixel() const;
	int getBytesPerChannel() const;
	int getBitsPerChannel() const;
	int getNumChannels() const;

	ofPixels getChannel(int channel) const;
	void setChannel(int channel, const ofPixels channelPixels);

	ofImageType getImageType() const;
	void setImageType(ofImageType imageType);
	void setNumChannels(int numChannels);

	int size() const;
};
