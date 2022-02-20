#include "Object.h"

Object::Object(std::string setName, float facing, Vector3 pos, Vector3 direction)
{
	isPickUp = false;
	render = true;
	entityPos = pos;
	directionVector = direction;
	entityLookDirection = facing;
	velocity = 0;
	type = 'O';
	name = setName;
}

Object::~Object()
{
}

void Object::rotate(Vector3, float)
{
	if (isPickUp)
	{
		entityLookDirection += 10.f;
		render = true;
	}
	if (!isPickUp)
	{
		render = false;
	}
}

void Object::updatePosition(Vector3 newpos)
{
}
