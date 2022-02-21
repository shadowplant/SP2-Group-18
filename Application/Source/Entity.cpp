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

Hitbox Entity::getHitbox()
{
	return hitbox;
}

bool Entity::getRender()
{
	return render;
}

void Entity::move(Vector3, float)
{

}

void Entity::updatePosition(Vector3 newpos)
{
	entityPos = newpos;
}
