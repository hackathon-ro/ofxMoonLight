#pragma once

class ofVec2f;
class ofVec3f;
#include "ofConstants.h"

class ofVec4f {
public:
	float x, y, z, w;
    
//    static const int DIM = 4;
	
	ofVec4f();
	explicit ofVec4f( float _scalar );
	ofVec4f( float _x, float _y, float _z, float _w );
	ofVec4f( const ofVec2f& vec);
	ofVec4f( const ofVec3f& vec);
	
    // Getters and Setters.
    //
//	void set( float _scalar );
    void set( float _x, float _y, float _z, float _w );
    void set( const ofVec4f& vec );
	
	float * getPtr() {
		return (float*)&x;
	}
	const float * getPtr() const {
		return (const float *)&x;
	}
	
	float& operator[]( int n ){
		return getPtr()[n];
	}
	
	float operator[]( int n ) const {
		return getPtr()[n];
	}
	
	
    // Check similarity/equality.
    //
    bool operator==( const ofVec4f& vec ) const;
    bool operator!=( const ofVec4f& vec ) const;
    bool match( const ofVec4f& vec, float tolerance=0.0001) const;
	
	
    // Additions and Subtractions.
    //
    ofVec4f  operator+( const ofVec4f& vec ) const;
    ofVec4f& operator+=( const ofVec4f& vec );
    ofVec4f  operator-( const float f ) const;
    ofVec4f& operator-=( const float f );
    ofVec4f  operator-( const ofVec4f& vec ) const;
    ofVec4f& operator-=( const ofVec4f& vec );
    ofVec4f  operator+( const float f ) const;
    ofVec4f& operator+=( const float f );
    ofVec4f  operator-() const;
	
	
    // Scalings
    //
    ofVec4f  operator*( const ofVec4f& vec ) const;
    ofVec4f& operator*=( const ofVec4f& vec );
    ofVec4f  operator*( const float f ) const;
    ofVec4f& operator*=( const float f );
    ofVec4f  operator/( const ofVec4f& vec ) const;
    ofVec4f& operator/=( const ofVec4f& vec );
    ofVec4f  operator/( const float f ) const;
    ofVec4f& operator/=( const float f );
	
	friend ostream& operator<<(ostream& os, const ofVec4f& vec);
	friend istream& operator>>(istream& is, const ofVec4f& vec);
	
	
    ofVec4f  getScaled( const float length ) const;
    ofVec4f& scale( const float length );
	
	
    // Distance between two points.
    //
    float distance( const ofVec4f& pnt) const;
    float squareDistance( const ofVec4f& pnt ) const;
	
	
    // Linear interpolation.
    //
    /**
	 * p==0.0 results in this point, p==0.5 results in the
	 * midpoint, and p==1.0 results in pnt being returned.
	 */
    ofVec4f   getInterpolated( const ofVec4f& pnt, float p ) const;
    ofVec4f&  interpolate( const ofVec4f& pnt, float p );
    ofVec4f   getMiddle( const ofVec4f& pnt ) const;
    ofVec4f&  middle( const ofVec4f& pnt );
    ofVec4f&  average( const ofVec4f* points, int num );
    
	
    // Normalization
    //
    ofVec4f  getNormalized() const;
    ofVec4f& normalize();
	
	
    // Limit length.
    //
	ofVec4f  getLimited(float max) const;
    ofVec4f& limit(float max);
	
	
    // Length
    //
    float length() const;
    float lengthSquared() const;
    /**
	 * Dot Product.
	 */
    float dot( const ofVec4f& vec ) const;
	
	
	
	
    //---------------------------------------
    // this methods are deprecated in 006 please use:
	
    // getScaled
    ofVec4f rescaled( const float length ) const;
	
    // scale
    ofVec4f& rescale( const float length );
	
    // getNormalized
    ofVec4f normalized() const;
	
    // getLimited
    ofVec4f limited(float max) const;
	
    // use squareDistance
    float  distanceSquared( const ofVec4f& pnt ) const;
	
    // use getInterpolated
    ofVec4f 	interpolated( const ofVec4f& pnt, float p ) const;
	
    // use getMiddle
    ofVec4f 	middled( const ofVec4f& pnt ) const;    
    
    // return all zero vector
    static ofVec4f zero() { return ofVec4f(0, 0, 0, 0); }
    
    // return all one vector
    static ofVec4f one() { return ofVec4f(1, 1, 1, 1); }

};




// Non-Member operators
//
//
ofVec4f operator+( float f, const ofVec4f& vec );
ofVec4f operator-( float f, const ofVec4f& vec );
ofVec4f operator*( float f, const ofVec4f& vec );
ofVec4f operator/( float f, const ofVec4f& vec );
