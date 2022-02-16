#include "CollisionSphere.h"

CollisionSphere::CollisionSphere()
{
	center.x = center.y = center.z = 0;
	r = 0;
}

CollisionSphere::CollisionSphere(Vector3 c, float r2)
{
	center = c;
	r = r2;
}
