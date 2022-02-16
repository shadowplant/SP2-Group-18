#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include "Vector3.h"
#include "CollisionSphere.h"
#include "Collision.h"
#include "CollisionPlane.h"
#include "Camera3.h"
#include <string>
#include <vector>

class Player : private Collision 
{
	std::string name;
	CollisionSphere cs;
	int health;
	Vector3 force;
	Vector3 direction;
	bool isground;
	bool iscollision;
	float sprintspeed;
	float normalspeed;
	float lookspeed;
	bool issprint;

public:

	Player(std::string n, CollisionSphere sphere);
	void update(std::vector<CollisionPlane>& cp);
	CollisionSphere getCollisionSphere();
	std::string getName();
	void setPosition(Vector3 pos);


};
#endif