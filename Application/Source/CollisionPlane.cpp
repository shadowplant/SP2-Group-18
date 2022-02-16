#include "CollisionPlane.h"

CollisionPlane::CollisionPlane(float n1, float n2, float n3, float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l)
{
	p[0].Set(a, b, c);
	p[1].Set(d, e, f);
	p[2].Set(g, h, i);
	p[3].Set(j, k, l);
	normal.Set(n1, n2, n3);
}

Vector3 CollisionPlane::get1point()
{
	return p[0];
}
Vector3 CollisionPlane::get2point()
{
	return p[1];
}

Vector3 CollisionPlane::get3point()
{
	return p[2];
}

Vector3 CollisionPlane::get4point()
{
	return p[3];
}

Vector3 CollisionPlane::getnormal()
{
	return normal;
}

bool CollisionPlane::isok()
{
	return (normal.x != 0 && normal.y != 0 && normal.z != 0);
}
