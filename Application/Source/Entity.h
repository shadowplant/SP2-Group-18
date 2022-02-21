#ifndef ENTITY_H
#define ENTITY_H

#include "hitbox.h"
#include "Vector3.h"

class Entity
{
protected:
	std::string name;
	std::string type;
	Vector3 entityPos;
	Vector3 directionVector;
	Hitbox hitbox;
	float enityRadius;
	float entityLookDirection;
	float points;
	bool render;
	bool isPickup;

public:
	Entity();
	~Entity();

	std::string getName();
	std::string getType();
	Vector3 getPosition();
	float getLookDirection();
	float getPoints();
	Hitbox getHitbox();
	bool getRender();
	bool getPickup();
	virtual void rotate(float);
	void updatePosition(Vector3 newpos);
	void updatePickup(bool);
};
#endif