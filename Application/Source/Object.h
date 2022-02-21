#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"
#include "hitbox.h"
#include "Vector3.h"

class Object : public Entity
{
protected:


public:
	Object(std::string setName, float facing, Vector3 pos, Vector3 direction, float points);
	~Object();

	virtual void rotate(float);
	void updatePosition(Vector3 newpos);
	void updatePickup(bool setpick);

};
#endif