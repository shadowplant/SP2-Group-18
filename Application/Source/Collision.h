#ifndef COLLISION_H
#define COLLISION_H
#include "Vector3.h"
#include <cmath>

class Collision {
public:
	static bool sphereplane(Vector3& sp, Vector3 pn, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4, float r);
	static bool raysphere(float xc, float yc, float zc, float xd, float yd, float zd, float xs, float ys, float zs, float r, float* dist = NULL, Vector3* collpoint = NULL);
	static bool rayplane(const float& nx, float ny, float nz, float x0, float y0, float z0, float xs, float ys, float zs, float xd, float yd, float zd, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4, float* dis = NULL, Vector3* point = NULL);
	static float rayplanedist(float nx, float ny, float nz, float x0, float y0, float z0, float xs, float ys, float zs, float xd, float yd, float zd);
	static float trianglearea(Vector3 p1, Vector3 p2, Vector3 p3);
	static bool spheresphere(Vector3& c1, float r1, Vector3& c2, float r2);
	static float pointdistacesquare(Vector3 p1, Vector3 p2);
	static float pointdistace(Vector3 p1, Vector3 p2);

	/*	static bool sphereplane(Vector3& sp,const Vector3& pn,const Vector3& p1,const Vector3& p2,const Vector3& p3,const Vector3& p4, const float& r);
		static bool raysphere(const Vector3& center,const Vector3& direction,const Vector3& startpoint,const float& r);
		static bool rayplane(const Vector3& normal,const Vector3& startpoint,const Vector3& direction,const Vector3& p1,const Vector3& p2,const Vector3& p3,const Vector3& p4);
		static float trianglearea(const Vector3& p1,const Vector3& p2,const Vector3& p3);
		static bool spheresphere(const Vector3& c1,float r1,const Vector3& c2,float r2);*/
};


#endif
