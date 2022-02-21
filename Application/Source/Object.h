#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"
#include "hitbox.h"
#include "Vector3.h"

class Object : public Entity
{
protected:
	bool isPickUp;

public:
	Object();
	~Object();

	virtual void move(Vector3, float);
	void updatePosition(Vector3 newpos);
};
#endif