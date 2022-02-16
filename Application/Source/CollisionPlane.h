#ifndef COLLISIONPLANE_H
#define COLLISIONPLANE_H
#include <iostream>
#include "Vector3.h"

class CollisionPlane {
public:
	Vector3 p[4];
	Vector3 normal;
	CollisionPlane(float n1, float n2, float n3, float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l);
	Vector3 get1point();
	Vector3 get2point();
	Vector3 get3point();
	Vector3 get4point();
	Vector3 getnormal();
	bool isok();
};
#endif
