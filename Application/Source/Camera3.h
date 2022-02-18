#ifndef CAMERA_3_H
#define CAMERA_3_H

#include "Camera.h"
#include "Vector3.h"
#include "Application.h"
#include "Mtx44.h"
#include "Hitbox.h"
#include "Interactionbox.h"
#include <vector>


class Camera3 : public Camera
{
public:
	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;
	
	Camera3();
	~Camera3();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	void Update(double dt, std::vector<Hitbox> hitbox);
	/*void Update(double dt, std::vector<Interactionbox> interactbox);*/
	void PlayerCollision(std::vector<Hitbox>);
	/*void PlayerInteraction(std::vector<Interactionbox>);*/
	Vector3 CircleRectcollision(float cx, float cy, float radius, float rx, float ry, float rw, float rh);
	bool CollisionAABB(float r1x, float r1y, float r1z, float r1w, float r1h, float r1d, float r2x, float r2y, float r2z, float r2w, float r2h, float r2d);

	//bool isInRange(std::vector<float>& objPos, std::vector<float>& objSize, float count);
	//bool isInDoorRange(std::vector<float>& objPos, std::vector<float>& objSize, float count);
	//bool isOnButton(std::vector<float>& objPos, std::vector<float>& objSize, float count);
	//bool ObjIsOnButton(std::vector<float>& objPos, std::vector<float>& objSize, float count, float objx, float objz);
	//bool inPortal(std::vector<float>& objPos, std::vector<float>& objSize, float count);
	virtual void Reset();

private:
	float lastX, lastY;
	float pitch, totalPitch;
	float cameraRadius, cameraHeight;
	float velocityY;
	float timer;
	float jump;
	bool firstMouse;
	//bool abletointeract = false;

	bool isJumping;
	void mouseLook();
	
};

#endif