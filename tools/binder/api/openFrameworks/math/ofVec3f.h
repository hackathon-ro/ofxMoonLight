#pragma once

#include "ofVec2f.h"
#include "ofVec4f.h"
#include "ofConstants.h"

#include <cmath>
#include <iostream>

class ofVec3f {
public:
	float x,y,z;
    
//    static const int DIM = 3;
	
	ofVec3f();
	ofVec3f( float _x, float _y, float _z=0 );
	/// assigns scalar to x, y, and z
	explicit ofVec3f( float _scalar );
	
    ofVec3f( const ofVec2f& vec );
    ofVec3f( const ofVec4f& vec );
	
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
    void set( float _x, float _y, float _z = 0 );
    void set( const ofVec3f& vec );
	void set( float _scalar );
	
    // Check similarity/equality.
    //
    bool operator==( const ofVec3f& vec ) const;
    bool operator!=( const ofVec3f& vec ) const;
    bool match( const ofVec3f& vec, float tolerance=0.0001 ) const;
    /**
	 * Checks if vectors look in the same direction.
	 */
    bool isAligned( const ofVec3f& vec, float tolerance=0.0001 ) const;
    bool align( const ofVec3f& vec, float tolerance=0.0001 ) const;
    bool isAlignedRad( const ofVec3f& vec, float tolerance=0.0001 ) const;
    bool alignRad( const ofVec3f& vec, float tolerance=0.0001 ) const;
	
	
    // Operator overloading for ofVec3f
    //
    ofVec3f  operator+( const ofVec3f& pnt ) const;
    ofVec3f& operator+=( const ofVec3f& pnt );
    ofVec3f  operator-( const ofVec3f& vec ) const;
    ofVec3f& operator-=( const ofVec3f& vec );
    ofVec3f  operator*( const ofVec3f& vec ) const;
    ofVec3f& operator*=( const ofVec3f& vec );
    ofVec3f  operator/( const ofVec3f& vec ) const;
    ofVec3f& operator/=( const ofVec3f& vec );
    ofVec3f  operator-() const;
	
    //operator overloading for float
    //
	//    void 	  operator=( const float f);
    ofVec3f  operator+( const float f ) const;
    ofVec3f& operator+=( const float f );
 	ofVec3f  operator-( const float f ) const;
    ofVec3f& operator-=( const float f );
    ofVec3f  operator*( const float f ) const;
    ofVec3f& operator*=( const float f );
    ofVec3f  operator/( const float f ) const;
    ofVec3f& operator/=( const float f );
	
	friend ostream& operator<<(ostream& os, const ofVec3f& vec);
	friend istream& operator>>(istream& is, const ofVec3f& vec);
	
    //Scale
    //
    ofVec3f  getScaled( const float length ) const;
    ofVec3f& scale( const float length );
    
	
    // Rotation
    //
    ofVec3f  getRotated( float angle, const ofVec3f& axis ) const;
    ofVec3f  getRotatedRad( float angle, const ofVec3f& axis ) const;
    ofVec3f& rotate( float angle, const ofVec3f& axis );
    ofVec3f& rotateRad( float angle, const ofVec3f& axis );
    ofVec3f  getRotated(float ax, float ay, float az) const;
    ofVec3f  getRotatedRad(float ax, float ay, float az) const;
    ofVec3f& rotate(float ax, float ay, float az);
    ofVec3f& rotateRad(float ax, float ay, float az);
    
    
    // Rotation - point around pivot
    //    
    ofVec3f   getRotated( float angle, const ofVec3f& pivot, const ofVec3f& axis ) const;
    ofVec3f&  rotate( float angle, const ofVec3f& pivot, const ofVec3f& axis );
    ofVec3f   getRotatedRad( float angle, const ofVec3f& pivot, const ofVec3f& axis ) const;
    ofVec3f&  rotateRad( float angle, const ofVec3f& pivot, const ofVec3f& axis );    
	
	
    // Map point to coordinate system defined by origin, vx, vy, and vz.
    //
    ofVec3f getMapped( const ofVec3f& origin,
					  const ofVec3f& vx,
					  const ofVec3f& vy,
					  const ofVec3f& vz ) const;
    ofVec3f& map( const ofVec3f& origin,
				 const ofVec3f& vx,
				 const ofVec3f& vy,
				 const ofVec3f& vz );
	
	
    // Distance between two points.
    //
    float distance( const ofVec3f& pnt) const;
    float squareDistance( const ofVec3f& pnt ) const;
	
	
    // Linear interpolation.
    //
    /**
	 * p==0.0 results in this point, p==0.5 results in the
	 * midpoint, and p==1.0 results in pnt being returned.
	 */
    ofVec3f   getInterpolated( const ofVec3f& pnt, float p ) const;
    ofVec3f&  interpolate( const ofVec3f& pnt, float p );
    ofVec3f   getMiddle( const ofVec3f& pnt ) const;
    ofVec3f&  middle( const ofVec3f& pnt );
    ofVec3f&  average( const ofVec3f* points, int num );
    
	
    // Normalization
    //
    ofVec3f  getNormalized() const;
    ofVec3f& normalize();
	
	
    // Limit length.
    //
    ofVec3f  getLimited(float max) const;
    ofVec3f& limit(float max);
	
	
    // Perpendicular vector.
    //
    ofVec3f  getCrossed( const ofVec3f& vec ) const;
    ofVec3f& cross( const ofVec3f& vec );
    /**
	 * Normalized perpendicular.
	 */
    ofVec3f  getPerpendicular( const ofVec3f& vec ) const;
    ofVec3f& perpendicular( const ofVec3f& vec );
	
	
    // Length
    //
    float length() const;
    float lengthSquared() const;
    /**
	 * Angle (deg) between two vectors.
	 * This is an unsigned relative angle from 0 to 180.
	 * http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
	 */
    float angle( const ofVec3f& vec ) const;
    float angleRad( const ofVec3f& vec ) const;
	
	
    // Dot Product
    //
    float dot( const ofVec3f& vec ) const;
	
	
	
    //-----------------------------------------------
    // this methods are deprecated in 006 please use:
	
    // getScaled
    ofVec3f rescaled( const float length ) const;
	
    // scale
    ofVec3f& rescale( const float length );
	
    // getRotated
    ofVec3f rotated( float angle, const ofVec3f& axis ) const;
	
    // getRotated should this be const???
    ofVec3f rotated(float ax, float ay, float az);
	
    // getNormalized
    ofVec3f normalized() const;
	
    // getLimited
    ofVec3f limited(float max) const;
	
    // getCrossed
    ofVec3f crossed( const ofVec3f& vec ) const;
	
    // getPerpendicular
    ofVec3f perpendiculared( const ofVec3f& vec ) const;
    
    // use getMapped
    ofVec3f  mapped( const ofVec3f& origin,
					const ofVec3f& vx,
					const ofVec3f& vy,
					const ofVec3f& vz ) const;
	
    // use squareDistance
    float  distanceSquared( const ofVec3f& pnt ) const;
	
    // use getInterpolated
    ofVec3f 	interpolated( const ofVec3f& pnt, float p ) const;
	
    // use getMiddle
    ofVec3f 	middled( const ofVec3f& pnt ) const;
    
    // use getRotated
    ofVec3f 	rotated( float angle,
						const ofVec3f& pivot,
						const ofVec3f& axis ) const;    

    // return all zero vector
    static ofVec3f zero() { return ofVec3f(0, 0, 0); }
    
    // return all one vector
    static ofVec3f one() { return ofVec3f(1, 1, 1); }
};




// Non-Member operators
//
//
ofVec3f operator+( float f, const ofVec3f& vec );
ofVec3f operator-( float f, const ofVec3f& vec );
ofVec3f operator*( float f, const ofVec3f& vec );
ofVec3f operator/( float f, const ofVec3f& vec );
