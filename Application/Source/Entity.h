#ifndef ENTITY_H
#define ENTITY_H

#include "hitbox.h"
#include "Vector3.h"

class Entity
{
protected:
	std::string type;
	Vector3 entityPos;
	float entityLookDirection;
	float velocity;

public:
	Entity();
	~Entity();

	std::string getType();
	Vector3 getPosition();
	float getLookDirection();

	virtual void move(Vector3, float);
	void updatePosition(Vector3 newpos);
};
#endif