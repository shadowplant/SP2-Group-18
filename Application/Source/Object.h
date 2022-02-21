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
	Object(std::string setName, float facing, Vector3 pos, Vector3 direction);
	~Object();

	virtual void rotate(Vector3, float);
	void updatePosition(Vector3 newpos);
};
#endif