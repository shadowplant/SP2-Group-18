#ifndef COLLISIONSPHERE_H
#define COLLISIONSPHERE_H
#include "Vector3.h"

class CollisionSphere {
public:
	float r;
	Vector3 center;
	CollisionSphere(Vector3 c, float rad);
	CollisionSphere();
};

#endif