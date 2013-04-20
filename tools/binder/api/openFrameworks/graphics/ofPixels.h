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

template <typename PixelType>
class ofPixels {

	friend class ofPixelUtils;

public:

	ofPixels();
	~ofPixels();
	ofPixels(const ofPixels & mom);
	ofPixels& operator=(const ofPixels & mom);

	void allocate(int w, int h, int channels);
	void allocate(int w, int h, ofPixelFormat type);
	void allocate(int w, int h, ofImageType type);

	void set(PixelType val);
	void set(int channel,PixelType val);
	void setFromPixels(const PixelType * newPixels,int w, int h, int channels);
	void setFromPixels(const PixelType * newPixels,int w, int h, ofImageType type);
	void setFromExternalPixels(PixelType * newPixels,int w, int h, int channels);
	void setFromAlignedPixels(const PixelType * newPixels, int width, int height, int channels, int stride);
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
	
	PixelType * getPixels();
	const PixelType * getPixels() const;

	int getPixelIndex(int x, int y) const;
	ofColor getColor(int x, int y) const;
	void setColor(int x, int y, ofColor color);

	const PixelType& operator[](int pos) const;
	PixelType& operator[](int pos);

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
