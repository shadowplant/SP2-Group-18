#include "Player.h"

Player::Player(std::string n, CollisionSphere sphere)
{
	name = n;
	cs = sphere;
}


CollisionSphere Player::getCollisionSphere()
{
	return cs;
}

std::string Player::getName()
{
	return name;
}

void Player::setPosition(Vector3 pos)
{
	cs.center = pos;
}

void Player::update(std::vector<CollisionPlane>& cp)
{
	Camera3 camera;
	Vector3 newpos(camera.position.x, camera.position.y * 0.5, camera.position.z);
	for (int i = 0; i < cp.size(); i++)
		sphereplane(newpos, cp[i].normal, cp[i].p[0], cp[i].p[1], cp[i].p[2], cp[i].p[3], cs.r);
	setPosition(newpos);
}



