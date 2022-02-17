#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

std::string Entity::getType()
{
	return std::string();
}

Vector3 Entity::getPosition()
{
	return entityPos;
}

float Entity::getLookDirection()
{
	return entityLookDirection;
}

void Entity::move(Vector3, float)
{

}

void Entity::updatePosition(Vector3 newpos)
{
	entityPos = newpos;
}
