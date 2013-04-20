#pragma once

class ofVec3f;
class ofVec4f;
#include "ofConstants.h"

class ofVec2f {
public:
	float x, y;
    
//    static const int DIM = 2;
	
	ofVec2f();
	explicit ofVec2f( float _scalar );
	ofVec2f( float _x, float _y );
    ofVec2f( const ofVec3f& vec );
    ofVec2f( const ofVec4f& vec );
	
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
	
	
    // Getters and Setters.
    //
	void set( float _scalar );
    void set( float _x, float _y );
    void set( const ofVec2f& vec );
	
    // Check similarity/equality.
    //
    bool operator==( const ofVec2f& vec ) const;
    bool operator!=( const ofVec2f& vec ) const;
    bool match( const ofVec2f& vec, float tolerance=0.0001 ) const;
    /**
	 * Checks if vectors look in the same direction.
	 * Tolerance is specified in degree.
	 */
    bool isAligned( const ofVec2f& vec, float tolerance=0.0001 ) const;
    bool isAlignedRad( const ofVec2f& vec, float tolerance=0.0001 ) const;
    bool align( const ofVec2f& vec, float tolerance=0.0001 ) const;
    bool alignRad( const ofVec2f& vec, float tolerance=0.0001 ) const;
	
	
    // Overloading for any type to any type
    //
    ofVec2f  operator+( const ofVec2f& vec ) const;
    ofVec2f& operator+=( const ofVec2f& vec );
    ofVec2f  operator-( const ofVec2f& vec ) const;
    ofVec2f& operator-=( const ofVec2f& vec );
    ofVec2f  operator*( const ofVec2f& vec ) const;
    ofVec2f& operator*=( const ofVec2f& vec );
    ofVec2f  operator/( const ofVec2f& vec ) const;
    ofVec2f& operator/=( const ofVec2f& vec );
	
	
    //operator overloading for float
    //
	//    void 	  operator=( const float f);
    ofVec2f  operator+( const float f ) const;
    ofVec2f& operator+=( const float f );
    ofVec2f  operator-( const float f ) const;
    ofVec2f& operator-=( const float f );
    ofVec2f  operator-() const;
    ofVec2f  operator*( const float f ) const;
    ofVec2f& operator*=( const float f );
    ofVec2f  operator/( const float f ) const;
    ofVec2f& operator/=( const float f );
	
	friend ostream& operator<<(ostream& os, const ofVec2f& vec);
	friend istream& operator>>(istream& is, const ofVec2f& vec);
	
    // Scaling
    //
    ofVec2f  getScaled( const float length ) const;
    ofVec2f& scale( const float length );
	
	
    // Rotation
    //
    ofVec2f  getRotated( float angle ) const;
    ofVec2f  getRotatedRad( float angle ) const;
    ofVec2f& rotate( float angle );
    ofVec2f& rotateRad( float angle );
	
    
    // Rotation - point around pivot
    //
    ofVec2f  getRotated( float angle, const ofVec2f& pivot ) const;
    ofVec2f& rotate( float angle, const ofVec2f& pivot );
    ofVec2f  getRotatedRad( float angle, const ofVec2f& pivot ) const;
    ofVec2f& rotateRad( float angle, const ofVec2f& pivot );
	
	
    // Map point to coordinate system defined by origin, vx, and vy.
    //
    ofVec2f getMapped( const ofVec2f& origin,
					  const ofVec2f& vx,
					  const ofVec2f& vy ) const;
    ofVec2f& map( const ofVec2f& origin,
				 const ofVec2f& vx, const ofVec2f& vy );
	
	
    // Distance between two points.
    //
    float distance( const ofVec2f& pnt) const;
    float squareDistance( const ofVec2f& pnt ) const;
	
	
    // Linear interpolation.
    //
    //
    /**
	 * p==0.0 results in this point, p==0.5 results in the
	 * midpoint, and p==1.0 results in pnt being returned.
	 */
    ofVec2f   getInterpolated( const ofVec2f& pnt, float p ) const;
    ofVec2f&  interpolate( const ofVec2f& pnt, float p );
    ofVec2f   getMiddle( const ofVec2f& pnt ) const;
    ofVec2f&  middle( const ofVec2f& pnt );
    ofVec2f&  average( const ofVec2f* points, int num );
    
    
    // Normalization
    //
    ofVec2f  getNormalized() const;
    ofVec2f& normalize();
	
	
    // Limit length.
    //
	ofVec2f  getLimited(float max) const;
    ofVec2f& limit(float max);
	
	
    // Perpendicular normalized vector.
    //
    ofVec2f  getPerpendicular() const;
    ofVec2f& perpendicular();
	
	
    // Length
    //
    float length() const;
    float lengthSquared() const;
	
	
    /**
	 * Angle (deg) between two vectors.
	 * This is a signed relative angle between -180 and 180.
	 */
//    float angle( const ofVec2f& vec ) const;
    float angleRad( const ofVec2f& vec ) const;
	
	
    /**
	 * Dot Product.
	 */
    float dot( const ofVec2f& vec ) const;
	
	
	
    //---------------------------------------------------
    // this methods are deprecated in 006 please use:
	
    // getScaled
    ofVec2f rescaled( const float length ) const;
	
    // scale
    ofVec2f& rescale( const float length );
	
    // getRotated
    ofVec2f rotated( float angle ) const;
	
    // getNormalized
    ofVec2f normalized() const;
	
    // getLimited
    ofVec2f limited(float max) const;
	
    // getPerpendicular
    ofVec2f perpendiculared() const;
	
    // getInterpolated
    ofVec2f interpolated( const ofVec2f& pnt, float p ) const;
    
    // getMiddled
    ofVec2f middled( const ofVec2f& pnt ) const;
    
    // getMapped 
    ofVec2f mapped( const ofVec2f& origin, const ofVec2f& vx, const ofVec2f& vy ) const;
    
    // squareDistance
    float distanceSquared( const ofVec2f& pnt ) const;
    
    // use getRotated
    ofVec2f rotated( float angle, const ofVec2f& pivot ) const;    
    
    // return all zero vector
    static ofVec2f zero() { return ofVec2f(0, 0); }

    // return all one vector
    static ofVec2f one() { return ofVec2f(1, 1); }
};





// Non-Member operators
//
ofVec2f operator+( float f, const ofVec2f& vec );
ofVec2f operator-( float f, const ofVec2f& vec );
ofVec2f operator*( float f, const ofVec2f& vec );
ofVec2f operator/( float f, const ofVec2f& vec );

