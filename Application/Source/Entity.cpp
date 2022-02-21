#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

std::string Entity::getName()
{
	return name;
}

std::string Entity::getType()
{
	return type;
}

Vector3 Entity::getPosition()
{
	return entityPos;
}

float Entity::getLookDirection()
{
	return entityLookDirection;
}

float Entity::getPoints()
{
	return points;
}

Hitbox Entity::getHitbox()
{
	return hitbox;
}

bool Entity::getRender()
{
	return render;
}

bool Entity::getPickup()
{
	return isPickup;
}

void Entity::rotate(float dt)
{

}

void Entity::updatePosition(Vector3 newpos)
{
	entityPos = newpos;
}

void Entity::updatePickup(bool setpick)
{
	isPickup = setpick;
}
