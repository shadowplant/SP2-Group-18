#include "Object.h"

Object::Object(std::string setName, float facing, Vector3 pos, Vector3 direction, float setPoints)
{
	isPickup = false;
	render = true;
	entityPos = pos;
	directionVector = direction;
	entityLookDirection = facing;
	type = 'O';
	name = setName;
	points = setPoints;
}

Object::~Object()
{
}

void Object::rotate(float dt)
{
	if (isPickup == false)
	{
		entityLookDirection += 10.f * dt;
		render = true;
	}
	if (isPickup == true)
	{
		render = false;
	}
}

void Object::updatePosition(Vector3 newpos)
{
	entityPos = newpos;
}
void Object::updatePickup(bool setpick)
{
	isPickup = setpick;
}

