/*
 *  ofMatrix4x4.h
 *  
 *  Created by Aaron Meyers on 6/22/09 -- modified by Arturo Castro, Zach Lieberman, Memo Akten
 *  based on code from OSG - 
 *  see OSG license for more details: 
 *  http://www.openscenegraph.org/projects/osg/wiki/Legal
 * 
 */

#pragma once

#include "ofVec3f.h"
#include "ofVec4f.h"
#include "ofQuaternion.h"
#include "ofConstants.h"
#include <cmath>


#if (_MSC_VER)       
		// make microsoft visual studio complain less about double / float conversion and
		// truncation
		#pragma warning(disable : 4244)
		#pragma warning(disable : 4305)
#endif


class ofMatrix4x4 {
public:
//	float _mat[4][4];
	ofVec4f _mat[4];
	
	//---------------------------------------------
	// constructors
	ofMatrix4x4() {
		makeIdentityMatrix();
	}
	ofMatrix4x4( const ofMatrix4x4& mat) {
		set(mat.getPtr());
	}
	ofMatrix4x4( const ofQuaternion& quat ) {
		makeRotationMatrix(quat);
	}

	ofMatrix4x4(	float a00, float a01, float a02, float a03,
	              float a10, float a11, float a12, float a13,
	              float a20, float a21, float a22, float a23,
	              float a30, float a31, float a32, float a33);

	//---------------------------------------------
	// destructor
	~ofMatrix4x4() {}

//	int compare(const ofMatrix4x4& m) const;
//
//	bool operator < (const ofMatrix4x4& m) const { return compare(m)<0; }
//	bool operator == (const ofMatrix4x4& m) const { return compare(m)==0; }
//	bool operator != (const ofMatrix4x4& m) const { return compare(m)!=0; }

	//---------------------------------------------
	// write data with matrix(row,col)=number
	float& operator()(int row, int col) {
		return _mat[row][col];
	}

	//---------------------------------------------
	// read data with var=matrix(row,col)
	float operator()(int row, int col) const {
		return _mat[row][col];
	}

	//----------------------------------------
	ofVec3f getRowAsVec3f(int i) const {
		return ofVec3f(_mat[i][0], _mat[i][1], _mat[i][2]);
	}
	
	//----------------------------------------
	ofVec4f getRowAsVec4f(int i) const {
		return _mat[i];
	}
	
	friend ostream& operator<<(ostream& os, const ofMatrix4x4& M);
	friend istream& operator>>(istream& is, ofMatrix4x4& M);
	
	//---------------------------------------------
	// check if the matrix is valid
	bool isValid() const {
		return !isNaN();
	}

	bool isNaN() const;

	//---------------------------------------------
	// copy a matrix using = operator
	ofMatrix4x4& operator = (const ofMatrix4x4& rhs);

	//---------------------------------------------
	// methods to set the data of the matrix
	void set(const ofMatrix4x4& rhs);
	void set(float a00, float a01, float a02, float a03,
	         float a10, float a11, float a12, float a13,
	         float a20, float a21, float a22, float a23,
	         float a30, float a31, float a32, float a33);

	//---------------------------------------------
	// access the internal data in float* format
	// useful for opengl matrix transformations
	float * getPtr() {
		return (float*)_mat;
	}
	const float * getPtr() const {
		return (const float *)_mat;
	}

	//---------------------------------------------
	// check matrix identity
	bool isIdentity() const;


	//---------------------------------------------
	// init matrix as identity, scale, translation...
	// all make* methods delete the current data
	void makeIdentityMatrix();

	void makeScaleMatrix( const ofVec3f& );
	void makeScaleMatrix( float, float, float );

	void makeTranslationMatrix( const ofVec3f& );
	void makeTranslationMatrix( float, float, float );

	void makeRotationMatrix( const ofVec3f& from, const ofVec3f& to );
	void makeRotationMatrix( float angle, const ofVec3f& axis );
	void makeRotationMatrix( float angle, float x, float y, float z );
	void makeRotationMatrix( const ofQuaternion& );
	void makeRotationMatrix( float angle1, const ofVec3f& axis1,
	                 float angle2, const ofVec3f& axis2,
	                 float angle3, const ofVec3f& axis3);


	// init related to another matrix
	bool makeInvertOf( const ofMatrix4x4& rhs);
	void makeOrthoNormalOf(const ofMatrix4x4& rhs);
	void makeFromMultiplicationOf( const ofMatrix4x4&, const ofMatrix4x4& );

	ofMatrix4x4 getInverse();


	//---------------------------------------------
	// init as opengl related matrix for perspective settings
	// see opengl docs of the related funciton for further details

	// glOrtho
	void makeOrthoMatrix(double left,   double right,
	               double bottom, double top,
	               double zNear,  double zFar);

	// glOrtho2D
	void makeOrtho2DMatrix(double left,   double right,
	                        double bottom, double top);

	// glFrustum
	void makeFrustumMatrix(double left,   double right,
	                 double bottom, double top,
	                 double zNear,  double zFar);

	// gluPerspective
	// Aspect ratio is defined as width/height.
	void makePerspectiveMatrix(double fovy,  double aspectRatio,
						 double zNear, double zFar);


	// makeLookAtMatrix:
	// creates a transformation matrix positioned at 'eye'
	// pointing at (along z axis) 'center'
	// this is what you use if you want an object to look at a point
	void makeLookAtMatrix(const ofVec3f& eye, const ofVec3f& center, const ofVec3f& up);
	
	
	// makeLookAtViewMatrix:
	// creates *the inverse of* a transformation matrix positioned at 'eye'
	// pointing at (along z axis) 'center'
	// this is what you use when you want your view matrix looking at a point
	// (the inverse of makeLookAtMatrix), same as gluLookAt
	void makeLookAtViewMatrix(const ofVec3f& eye, const ofVec3f& center, const ofVec3f& up);


	//---------------------------------------------
	// Get the perspective components from a matrix
	// this only works with pure perspective projection matrices

	bool getOrtho(double& left,   double& right,
	              double& bottom, double& top,
	              double& zNear,  double& zFar) const;

	bool getFrustum(double& left,   double& right,
	                double& bottom, double& top,
	                double& zNear,  double& zFar) const;

	/** Get the frustum settings of a symmetric perspective projection
	 * matrix.
	 * Return false if matrix is not a perspective matrix,
	 * where parameter values are undefined.
	 * Note, if matrix is not a symmetric perspective matrix then the
	 * shear will be lost.
	 * Asymmetric matrices occur when stereo, power walls, caves and
	 * reality center display are used.
	 * In these configuration one should use the AsFrustum method instead.
	 */
	bool getPerspective(double& fovy,  double& aspectRatio,
	                    double& zNear, double& zFar) const;

	// will only work for modelview matrices
	void getLookAt(ofVec3f& eye, ofVec3f& center, ofVec3f& up,
	               float lookDistance = 1.0f) const;



	//---------------------------------------------
	// decompose the matrix into translation, rotation,
	// scale and scale orientation.
	void decompose( ofVec3f& translation,
					ofQuaternion& rotation,
					ofVec3f& scale,
					ofQuaternion& so ) const;


	//---------------------------------------------
	// basic utility functions to create new matrices
	inline static ofMatrix4x4 newIdentityMatrix( void );
	inline static ofMatrix4x4 newScaleMatrix( const ofVec3f& sv);
	inline static ofMatrix4x4 newScaleMatrix( float sx, float sy, float sz);
	inline static ofMatrix4x4 newTranslationMatrix( const ofVec3f& dv);
	inline static ofMatrix4x4 newTranslationMatrix( float x, float y, float z);
	inline static ofMatrix4x4 newRotationMatrix( const ofVec3f& from, const ofVec3f& to);
	inline static ofMatrix4x4 newRotationMatrix( float angle, float x, float y, float z);
	inline static ofMatrix4x4 newRotationMatrix( float angle, const ofVec3f& axis);
	inline static ofMatrix4x4 newRotationMatrix( float angle1, const ofVec3f& axis1,
	                                   float angle2, const ofVec3f& axis2,
	                                   float angle3, const ofVec3f& axis3);
	inline static ofMatrix4x4 newRotationMatrix( const ofQuaternion& quat);


	// create new matrices as transformation of another
	inline static ofMatrix4x4 getInverseOf( const ofMatrix4x4& matrix);
	inline static ofMatrix4x4 getTransposedOf( const ofMatrix4x4& matrix);
	inline static ofMatrix4x4 getOrthoNormalOf(const ofMatrix4x4& matrix);


	// create new matrices related to glFunctions

	// glOrtho
	inline static ofMatrix4x4 newOrthoMatrix(double left,   double right,
	                                 double bottom, double top,
	                                 double zNear,  double zFar);

	// glOrtho2D
	inline static ofMatrix4x4 newOrtho2DMatrix(double left,   double right,
	                                   double bottom, double top);

	// glFrustum
	inline static ofMatrix4x4 newFrustumMatrix(double left,   double right,
	                                   double bottom, double top,
	                                   double zNear,  double zFar);

	// gluPerspective
	inline static ofMatrix4x4 newPerspectiveMatrix(double fovy,  double aspectRatio,
	                                       double zNear, double zFar);

	// gluLookAt
	inline static ofMatrix4x4 newLookAtMatrix(const ofVec3f& eye,
	                                  const ofVec3f& center,
	                                  const ofVec3f& up);


	//---------------------------------------------
	// matrix - vector multiplication
	// although opengl uses premultiplication
	// because of the way matrices are used in opengl:
	//
	// ofMatrix4x4				openGL
	// [0]  [1]  [2]  [3]		[0] [4] [8]  [12]
	// [4]  [5]  [6]  [7]		[1] [5] [9]  [13]
	// [8]  [9]  [10] [11]		[2] [6] [10] [14]
	// [12] [13] [14] [15]		[3] [7] [11] [15]
	//
	// in memory though both are layed in the same way
	// so when uploading a matrix it just works without
	// needing to transpose
	//
	// so although opengl docs explain transformations
	// like:
	//
	// ofVec3f c = rotateZ 30º ofVec3f a around ofVec3f b
	//
	// openGL docs says: c = T(b)*R(30)*a;
	//
	// with ofMatrix4x4:
	// ofMatrix4x4 R = ofMatrix4x4::newRotationMatrix(30,0,0,1);
	// ofMatrix4x4 T = ofMatrix4x4::newTranlationMatrix(b);
	// ofVec3f c = a*R*T;
	// where * is calling postMult

	inline ofVec3f postMult( const ofVec3f& v ) const;
	inline ofVec3f operator* (const ofVec3f& v) const {
		return postMult(v);
	}

	inline ofVec4f postMult( const ofVec4f& v ) const;
	inline ofVec4f operator* (const ofVec4f& v) const {
		return postMult(v);
	}

	inline ofVec3f preMult( const ofVec3f& v ) const;
	inline ofVec4f preMult( const ofVec4f& v ) const;


	//---------------------------------------------
	// set methods: all these alter the components
	// deleting the previous data only in that components
	void setRotate(const ofQuaternion& q);
	void setTranslation( float tx, float ty, float tz );
	void setTranslation( const ofVec3f& v );

	//---------------------------------------------
	// all these apply the transformations over the
	// current one, it's actually postMult... and behaves
	// the opposite to the equivalent gl functions
	// glTranslate + glRotate == rotate + translate
	void rotate(float angle, float x, float y, float z);
	void rotateRad(float angle, float x, float y, float z);
	void rotate(const ofQuaternion& q);
	void translate( float tx, float ty, float tz );
	void translate( const ofVec3f& v );
	void scale(float x, float y, float z);
	void scale( const ofVec3f& v );

	//---------------------------------------------
	// all these apply the transformations over the
	// current one, it's actually preMult... and behaves
	// the the same the equivalent gl functions
	void glRotate(float angle, float x, float y, float z);
	void glRotateRad(float angle, float x, float y, float z);
	void glRotate(const ofQuaternion& q);
	void glTranslate( float tx, float ty, float tz );
	void glTranslate( const ofVec3f& v );
	void glScale(float x, float y, float z);
	void glScale( const ofVec3f& v );

	//---------------------------------------------
	// get methods: return matrix components
	// rotation and scale can only be used if the matrix
	// only has rotation or scale.
	// for matrices with both use decompose instead.
	ofQuaternion getRotate() const;
	ofVec3f getTranslation() const;
	ofVec3f getScale() const;


	//---------------------------------------------
	// apply a 3x3 transform of v*M[0..2,0..2].
	inline static ofVec3f transform3x3(const ofVec3f& v, const ofMatrix4x4& m);

	// apply a 3x3 transform of M[0..2,0..2]*v.
	inline static ofVec3f transform3x3(const ofMatrix4x4& m, const ofVec3f& v);


	//---------------------------------------------
	// basic Matrixf multiplication, our workhorse methods.
	void postMult( const ofMatrix4x4& );
	inline void operator *= ( const ofMatrix4x4& other ) {
		if ( this == &other ) {
			ofMatrix4x4 temp(other);
			postMult( temp );
		} else postMult( other );
	}

	inline ofMatrix4x4 operator * ( const ofMatrix4x4 &m ) const {
		ofMatrix4x4 r;
		r.makeFromMultiplicationOf(*this, m);
		return  r;
	}
	
	

	void preMult( const ofMatrix4x4& );



	//---------------------------------------------
	// specialized postMult methods, usually you want to use this
	// for transforming ofVec not preMult
	// equivalent to postMult(newTranslationMatrix(v)); */
	inline void postMultTranslate( const ofVec3f& v );
	// equivalent to postMult(scale(v));
	inline void postMultScale( const ofVec3f& v );
	// equivalent to postMult(newRotationMatrix(q));
	inline void postMultRotate( const ofQuaternion& q );

	// AARON METHODS
	inline void postMultTranslate(float x, float y, float z);
	inline void postMultRotate(float angle, float x, float y, float z);
	inline void postMultScale(float x, float y, float z);


	//---------------------------------------------
	// equivalent to preMult(newScaleMatrix(v));
	inline void preMultScale( const ofVec3f& v );
	// equivalent to preMult(newTranslationMatrix(v));
	inline void preMultTranslate( const ofVec3f& v );
	// equivalent to preMult(newRotationMatrix(q));
	inline void preMultRotate( const ofQuaternion& q );
};

