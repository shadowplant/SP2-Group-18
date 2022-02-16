#ifndef CAMERA_3_H
#define CAMERA_3_H

#include "Camera.h"
#include "Vector3.h"
#include "Application.h"
#include "Mtx44.h"
#include "Collision.h"
#include <vector>
class Camera3 : public Camera
{
public:
	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;
	
	float r;
	Camera3();
	~Camera3();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	void Update(double dt, std::vector<float>& objPos, std::vector<float>& objSize);
	void UpdateCamOnCollided(std::vector<float>& objPos, std::vector<float>& objSize, Vector3& prevPos);
	void UpdateCamOnCollided2(std::vector<float>& objPos, std::vector<float>& objSize, Vector3& prevPos);
	bool CircleRectcollision(std::vector<float>& objPos, std::vector<float>& objSize, float count);
	bool CollisionAABB(float r1x, float r1y, float r1z, float r1w, float r1h, float r1d, float r2x, float r2y, float r2z, float r2w, float r2h, float r2d);
	//bool isInRange(std::vector<float>& objPos, std::vector<float>& objSize, float count);
	//bool isInDoorRange(std::vector<float>& objPos, std::vector<float>& objSize, float count);
	//bool isOnButton(std::vector<float>& objPos, std::vector<float>& objSize, float count);
	//bool ObjIsOnButton(std::vector<float>& objPos, std::vector<float>& objSize, float count, float objx, float objz);
	//bool inPortal(std::vector<float>& objPos, std::vector<float>& objSize, float count);
	virtual void Reset();

private:
	float lastX, lastY;
	float jump;
	bool firstMouse;
	void mouseLook();
	
};

#endif