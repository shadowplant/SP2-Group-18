#include "Camera3.h"


Camera3::Camera3()
{
}

Camera3::~Camera3()
{
}

void Camera3::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
    this->position = defaultPosition = pos;
    this->target = defaultTarget = target;
    r = 3;
    Vector3 view = (target - position).Normalized();
    Vector3 right = view.Cross(up);
    right.y = 0;
    right.Normalize();
    this->up = defaultUp = right.Cross(view).Normalized();
}

void Camera3::Update(double dt, std::vector<float>& objPos, std::vector<float>& objSize)
{
    const float CAMERA_SPEED = 30.f;
    const float CAMERA_ROTATION_SPEED = 90.0f;
    Vector3 view = (target - position).Normalized();
    Vector3 prevPos = position;

    Vector3 right = view.Cross(up);
    right.y = 0;
    right.Normalize();

    if (Application::IsKeyPressed('W'))
    {
        position += view * CAMERA_SPEED * dt;
        position.y = 9.5f;
        UpdateCamOnCollided(objPos, objSize, prevPos);

        target = position + view;
    }
    if (Application::IsKeyPressed('A'))
    {
        position -= right * CAMERA_SPEED * dt;
        position.y = 9.5f;
        UpdateCamOnCollided(objPos, objSize, prevPos);

        target = position + view;
    }
    if (Application::IsKeyPressed('S'))
    {
        position -= view * CAMERA_SPEED * dt;
        position.y = 9.5f;
        UpdateCamOnCollided(objPos, objSize, prevPos);

        target = position + view;
    }
    if (Application::IsKeyPressed('D'))
    {
        position += right * CAMERA_SPEED * dt;
        position.y = 9.5f;
        UpdateCamOnCollided(objPos, objSize, prevPos);

        target = position + view;
    }
    if (Application::IsKeyPressed(VK_LEFT))
    {
        float yaw = CAMERA_ROTATION_SPEED * static_cast<float>(dt);
        up = right.Cross(view).Normalized();

        Mtx44 rotation;
        rotation.SetToRotation(yaw, up.x, up.y, up.z);

        view = rotation * view;
        target = position + view;
    }
    if (Application::IsKeyPressed(VK_RIGHT))
    {
        float yaw = -CAMERA_ROTATION_SPEED * static_cast<float>(dt);
        up = right.Cross(view).Normalized();

        Mtx44 rotation;
        rotation.SetToRotation(yaw, up.x, up.y, up.z);

        view = rotation * view;
        target = position + view;
    }
    if (Application::IsKeyPressed(VK_UP))
    {
        float pitch = CAMERA_ROTATION_SPEED * static_cast<float>(dt);
        up = right.Cross(view).Normalized();

        Mtx44 rotation;
        rotation.SetToRotation(pitch, right.x, right.y, right.z);

        view = rotation * view;
        target = position + view;
        if (target.y > position.y + 0.5)
            target.y = position.y + 0.5;
        
    }
    if (Application::IsKeyPressed(VK_DOWN))
    {
        float pitch = -CAMERA_ROTATION_SPEED * static_cast<float>(dt);
        up = right.Cross(view).Normalized();

        Mtx44 rotation;
        rotation.SetToRotation(pitch, right.x, right.y, right.z);

        view = rotation * view;
        target = position + view;
        if (target.y < position.y - 0.5)
            target.y = position.y - 0.5;
    }
    if (Application::IsKeyPressed('R'))
    {
        Reset();
    }
}

void Camera3::UpdateCamOnCollided(std::vector<float>& objPos, std::vector<float>& objSize, Vector3& prevPos)
{
    const float HALF_MAP_SIZE = 500.0f;

    for (unsigned i = 0; i < objPos.size(); i += 3)
    {
        if (CircleRectcollision(objPos, objSize, i) == true)
        {
            position = prevPos;
        }
    }
    position.x = Math::Clamp(position.x, -HALF_MAP_SIZE, HALF_MAP_SIZE);
    position.z = Math::Clamp(position.z, -HALF_MAP_SIZE, HALF_MAP_SIZE);
}
bool Camera3::CircleRectcollision(std::vector<float>& objPos, std::vector<float>& objSize, float count)
{
   
    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
    float testX = position.x;
    float testZ = position.z;
    if (position.x < camObjVector.x - camObjSizeVector.x * 0.5)
        testX = camObjVector.x - camObjSizeVector.x * 0.5;      // test left edge

    else if (position.x > camObjVector.x + camObjSizeVector.x * 0.5)
        testX = camObjVector.x + camObjSizeVector.x * 0.5;   // right edge

    if (position.z < camObjVector.z - camObjSizeVector.z * 0.5)
        testZ = camObjVector.z - camObjSizeVector.z * 0.5;      // top edge

    else if (position.z > camObjVector.z + camObjSizeVector.z * 0.5)
        testZ = camObjVector.z + camObjSizeVector.z * 0.5;   // bottom edge

    // get distance from closest edges
    float distX = position.x - testX;
    float distZ = position.z - testZ;
    float distance = sqrt((distX * distX) + (distZ * distZ));

    // if the distance is less than the radius, collision!
    if (distance <= 3) {
        return true;
    }
    return false;
    
}

bool Camera3::isInRange(std::vector<float>& objPos, std::vector<float>& objSize, float count)
{
    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
    float testX = position.x;
    float testZ = position.z;
    if (position.x < camObjVector.x - camObjSizeVector.x * 0.5)
        testX = camObjVector.x - camObjSizeVector.x * 0.5;      // test left edge

    else if (position.x > camObjVector.x + camObjSizeVector.x * 0.5)
        testX = camObjVector.x + camObjSizeVector.x * 0.5;   // right edge

    if (position.z < camObjVector.z - camObjSizeVector.z * 0.5)
        testZ = camObjVector.z - camObjSizeVector.z * 0.5;      // top edge

    else if (position.z > camObjVector.z + camObjSizeVector.z * 0.5)
        testZ = camObjVector.z + camObjSizeVector.z * 0.5;   // bottom edge

    // get distance from closest edges
    float distX = position.x - testX;
    float distZ = position.z - testZ;
    float distance = sqrt((distX * distX) + (distZ * distZ));

    // if the distance is less than the radius, collision!
    if (distance <= 5) {
        return true;
    }
    return false;

}

bool Camera3::isInDoorRange(std::vector<float>& objPos, std::vector<float>& objSize, float count)
{
    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
    float testX = position.x;
    float testZ = position.z;
    if (position.x < camObjVector.x - camObjSizeVector.x * 0.5)
        testX = camObjVector.x - camObjSizeVector.x * 0.5;      // test left edge

    else if (position.x > camObjVector.x + camObjSizeVector.x * 0.5)
        testX = camObjVector.x + camObjSizeVector.x * 0.5;   // right edge

    if (position.z < camObjVector.z - camObjSizeVector.z * 0.5)
        testZ = camObjVector.z - camObjSizeVector.z * 0.5;      // top edge

    else if (position.z > camObjVector.z + camObjSizeVector.z * 0.5)
        testZ = camObjVector.z + camObjSizeVector.z * 0.5;   // bottom edge

    // get distance from closest edges
    float distX = position.x - testX;
    float distZ = position.z - testZ;
    float distance = sqrt((distX * distX) + (distZ * distZ));

    // if the distance is less than the radius, collision!
    if (distance <= 20) {
        return true;
    }
    return false;
}

bool Camera3::isOnButton(std::vector<float>& objPos, std::vector<float>& objSize, float count)
{
    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
    float distX = position.x - camObjVector.x;
    float distZ = position.z - camObjVector.z;
    float distance = sqrt((distX * distX) + (distZ * distZ));

    // if the distance is less than the sum of the circle's
    // radii, the circles are touching!
    if (distance <= 3 + 10) {
        return true;
    }
    return false;
}

bool Camera3::ObjIsOnButton(std::vector<float>& objPos, std::vector<float>& objSize, float count, float objx, float objz)
{
    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
    float distX = objx - camObjVector.x;
    float distZ = objz - camObjVector.z;
    float distance = sqrt((distX * distX) + (distZ * distZ));

    // if the distance is less than the sum of the circle's
    // radii, the circles are touching!
    if (distance <= 3 + 10) {
        return true;
    }
    return false;
}

bool Camera3::inPortal(std::vector<float>& objPos, std::vector<float>& objSize, float count)
{
    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
    float distX = position.x - camObjVector.x;
    float distZ = position.z - camObjVector.z;
    float distance = sqrt((distX * distX) + (distZ * distZ));

    // if the distance is less than the sum of the circle's
    // radii, the circles are touching!
    if (distance <= 3 + 1) {
        return true;
    }
    return false;
}



void Camera3::Reset()
{
    position = defaultPosition;
    target = defaultTarget;
    up = defaultUp;
}
