#include "Camera3.h"
#include "Application.h"


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
    Vector3 view = (target - position).Normalized();
    Vector3 right = view.Cross(up);
    right.y = 0;
    right.Normalize();
    this->up = defaultUp = right.Cross(view).Normalized();

    isJumping = false;
    velocityY = 0.f;
    cameraRadius = 1.f;
    cameraHeight = 10;
}

void Camera3::Update(double dt, std::vector<Hitbox> hitbox)
{
    mouseLook();
    const float WALK_SPEED = 40.f;
    const float SPRINT_SPEED = 50.f;
    float moveSpeed;
    const float WALK_HEIGHT = 9.5f;
    const float CROUCH_HEIGHT = 5.0f;
    const float CAMERA_ROTATION_SPEED = 90.0f;

    Vector3 view = (target - position).Normalized();
    Vector3 prevPos = position;
    Vector3 right = view.Cross(up);
    right.y = 0;
    right.Normalize();

    if (position.y > 9.5)
    {
        position.y += velocityY * dt;
        velocityY--;
        target = position + view;
    }
    else
    {
        velocityY = 0;
        isJumping = false;
        target = position + view;
    }
    if (position.y < 9.5)
    {
        position.y = 9.5;
        target = position + view;
    }
    if (Application::IsKeyPressed(VK_SPACE) && !isJumping)
    {
        position.y = 9.51;
        velocityY = 30;
        isJumping = true;
    }
    //sprint
    if (Application::IsKeyPressed(VK_CONTROL))
    {
        moveSpeed = SPRINT_SPEED;
    }
    else
    {
        moveSpeed = WALK_SPEED;
    }
    if (Application::IsKeyPressed('W'))
    {
        position += view * moveSpeed * dt;
        PlayerCollision(hitbox);
        if (isJumping == false)
        {
            position.y = 9.5f;
        }
        target = position + view;
    }
    if (Application::IsKeyPressed('A'))
    {
        position -= right * moveSpeed * dt;
        PlayerCollision(hitbox);
        if (isJumping == false)
        {
            position.y = 9.5f;
        }
        target = position + view;
    }
    if (Application::IsKeyPressed('S'))
    {
        position -= view * moveSpeed * dt;
        PlayerCollision(hitbox);
        if (isJumping == false)
        {
            position.y = 9.5f;
        }
        target = position + view;
    }
    if (Application::IsKeyPressed('D'))
    {
        position += right * moveSpeed * dt;
        PlayerCollision(hitbox);

        target = position + view;
    }

    if (Application::IsKeyPressed('R'))
    {
        Reset();
    }
}

//void Camera3::Update(double dt, std::vector<Interactionbox> interactbox)
//{
//    mouseLook();
//    const float WALK_SPEED = 40.f;
//    const float SPRINT_SPEED = 50.f;
//    float moveSpeed;
//    const float WALK_HEIGHT = 9.5f;
//    const float CROUCH_HEIGHT = 5.0f;
//    const float CAMERA_ROTATION_SPEED = 90.0f;
//
//    Vector3 view = (target - position).Normalized();
//    Vector3 prevPos = position;
//    Vector3 right = view.Cross(up);
//    right.y = 0;
//    right.Normalize();
//
//    if (position.y > 9.5)
//    {
//        position.y += velocityY * dt;
//        velocityY--;
//        target = position + view;
//    }
//    else
//    {
//        velocityY = 0;
//        isJumping = false;
//        target = position + view;
//    }
//    if (position.y < 9.5)
//    {
//        position.y = 9.5;
//        target = position + view;
//    }
//    if (Application::IsKeyPressed(VK_SPACE) && !isJumping)
//    {
//        position.y = 9.51;
//        velocityY = 30;
//        isJumping = true;
//    }
//    //sprint
//    if (Application::IsKeyPressed(VK_CONTROL))
//    {
//        moveSpeed = SPRINT_SPEED;
//    }
//    else
//    {
//        moveSpeed = WALK_SPEED;
//    }
//    if (Application::IsKeyPressed('W'))
//    {
//        position += view * moveSpeed * dt;
//        PlayerInteraction(interactbox);
//        if (isJumping == false)
//        {
//            position.y = 9.5f;
//        }
//        target = position + view;
//    }
//    if (Application::IsKeyPressed('A'))
//    {
//        position -= right * moveSpeed * dt;
//        PlayerInteraction(interactbox);
//        if (isJumping == false)
//        {
//            position.y = 9.5f;
//        }
//        target = position + view;
//    }
//    if (Application::IsKeyPressed('S'))
//    {
//        position -= view * moveSpeed * dt;
//        PlayerInteraction(interactbox);
//        if (isJumping == false)
//        {
//            position.y = 9.5f;
//        }
//        target = position + view;
//    }
//    if (Application::IsKeyPressed('D'))
//    {
//        position += right * moveSpeed * dt;
//        PlayerInteraction(interactbox);
//        if (isJumping == false)
//        {
//            position.y = 9.5f;
//        }
//        target = position + view;
//    }
//
//    if (Application::IsKeyPressed('R'))
//    {
//        Reset();
//    }
//}

void Camera3::mouseLook()
{
    Vector3 view = (target - position).Normalized();
    Vector3 right = view.Cross(up);
    right.y = 0;
    right.Normalize();

    double x, y;
    Application::GetCursorPos(&x, &y);
    if (firstMouse)
    {
        lastX = x;
        lastY = y;
        firstMouse = false;
    }
    float xoffset = x - lastX;
    float yoffset = lastY - y;
    lastX = x;
    lastY = y;

    float sensitivity = 0.05f;
    xoffset *= -sensitivity;
    yoffset *= sensitivity;

    float totalPitch = pitch + yoffset;
    if (totalPitch > 80.f)       yoffset -= totalPitch - 80.f;
    else if (totalPitch < -80.f) yoffset -= totalPitch + 80.f;
    
    //yaw
    Mtx44 rotation;
    rotation.SetToRotation(xoffset, up.x, up.y, up.z);
    up = rotation * up;
    view = rotation * view;
    target = position + view;

    //pitch
    right.y = 0;
    right.Normalize();
    up = right.Cross(view).Normalized();
    rotation.SetToRotation(yoffset, right.x, right.y, right.z);
    view = rotation * view;
    target = position + view;
    Vector3 sightLine = view;
    sightLine.y = 0;
    pitch = acosf((view.Dot(sightLine)) / view.Length() * sightLine.Length());
    if (view.y >= 0) pitch = Math::RadianToDegree(pitch);
    else    pitch = -Math::RadianToDegree(pitch);
}

void Camera3::PlayerCollision(std::vector<Hitbox> hitbox)
{
    const float HALF_MAP_SIZE = 500.0f;
    for (int i = 0; i < hitbox.size(); i++) {
        if (CollisionAABB(position.x, position.y + 0.5f - cameraHeight * 0.5f, position.z, cameraRadius * 2.f, cameraHeight, cameraRadius * 2.f, (hitbox[i]).posX, (hitbox[i]).posY, (hitbox[i]).posZ, (hitbox[i]).sizeX, (hitbox[i]).sizeY, (hitbox[i]).sizeZ)) {
            Vector3 PrevPos = CircleRectcollision(position.x, position.z, cameraRadius, (hitbox[i]).posX, (hitbox[i]).posZ, (hitbox[i]).sizeX, (hitbox[i]).sizeZ);
            position.x = PrevPos.x;
            position.z = PrevPos.z;
        }
    }
    position.x = Math::Clamp(position.x, -HALF_MAP_SIZE, HALF_MAP_SIZE);
    position.z = Math::Clamp(position.z, -HALF_MAP_SIZE, HALF_MAP_SIZE);

    return;
}

//void Camera3::PlayerInteraction(std::vector<Interactionbox> interact)
//{
//    const float HALF_MAP_SIZE = 500.0f;
//    for (int i = 0; i < interact.size(); i++) {
//        if (CollisionAABB(position.x, position.y + 0.5f - cameraHeight * 0.5f, position.z, cameraRadius * 2.f, cameraHeight, cameraRadius * 2.f, (interact[i]).posX, (interact[i]).posY, (interact[i]).posZ, (interact[i]).sizeX, (interact[i]).sizeY, (interact[i]).sizeZ)) {
//            Vector3 PrevPos = CircleRectcollision(position.x, position.z, cameraRadius, (interact[i]).posX, (interact[i]).posZ, (interact[i]).sizeX, (interact[i]).sizeZ);
//            abletointeract = true;
//        }
//        else
//        {
//            abletointeract = false;
//        }
//    }
//    position.x = Math::Clamp(position.x, -HALF_MAP_SIZE, HALF_MAP_SIZE);
//    position.z = Math::Clamp(position.z, -HALF_MAP_SIZE, HALF_MAP_SIZE);
//
//    return;
//}

Vector3 Camera3::CircleRectcollision(float cx, float cy, float radius, float rx, float ry, float rw, float rh)
{
    //set potential position
    Vector3 setPos = Vector3(cx, 0, cy);
    
    //check to see if potential position collides with perimeter of 2d rectandgle
    Vector3 nearestPoint;
    nearestPoint.x = Math::Clamp(cx, rx - 0.5f * rw, rx + 0.5f * rw);
    nearestPoint.y = 0;
    nearestPoint.z = Math::Clamp(cy, ry - 0.5f * rh, ry + 0.5f * rh);
    Vector3 rayToNearest = nearestPoint - setPos;
    float overlap = radius - rayToNearest.Length();
    if (rayToNearest.Length() == 0) overlap = 0; 
    //If overlap is positive, then a collision has occurred, so we displace backwards by the overlap amount. 
    //The potential position is then tested against other tiles in the area therefore "statically" resolving the collision

    if (overlap > 0)
    {
        //Statically resolve the collision
        setPos = setPos - rayToNearest.Normalized() * overlap;
    }

    return setPos;
}
bool Camera3::CollisionAABB(float r1x, float r1y, float r1z, float r1w, float r1h, float r1d, float r2x, float r2y, float r2z, float r2w, float r2h, float r2d)
{
    return	(r1x - r1w * 0.5f < r2x + r2w * 0.5f && r1x + r1w * 0.5f > r2x - r2w * 0.5f) &&
        (r1y - r1h * 0.5f < r2y + r2h * 0.5f && r1y + r1h * 0.5f > r2y - r2h * 0.5f) &&
        (r1z - r1d * 0.5f < r2z + r2d * 0.5f && r1z + r1d * 0.5f > r2z - r2d * 0.5f);
}


//bool Camera3::isInRange(std::vector<float>& objPos, std::vector<float>& objSize, float count)
//{
//    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
//    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
//    float testX = position.x;
//    float testZ = position.z;
//    if (position.x < camObjVector.x - camObjSizeVector.x * 0.5)
//        testX = camObjVector.x - camObjSizeVector.x * 0.5;      // test left edge
//
//    else if (position.x > camObjVector.x + camObjSizeVector.x * 0.5)
//        testX = camObjVector.x + camObjSizeVector.x * 0.5;   // right edge
//
//    if (position.z < camObjVector.z - camObjSizeVector.z * 0.5)
//        testZ = camObjVector.z - camObjSizeVector.z * 0.5;      // top edge
//
//    else if (position.z > camObjVector.z + camObjSizeVector.z * 0.5)S
//        testZ = camObjVector.z + camObjSizeVector.z * 0.5;   // bottom edge
//
//    // get distance from closest edges
//    float distX = position.x - testX;
//    float distZ = position.z - testZ;
//    float distance = sqrt((distX * distX) + (distZ * distZ));
//
//    // if the distance is less than the radius, collision!
//    if (distance <= 5) {
//        return true;
//    }
//    return false;
//
//}
//
//bool Camera3::isInDoorRange(std::vector<float>& objPos, std::vector<float>& objSize, float count)
//{
//    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
//    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
//    float testX = position.x;
//    float testZ = position.z;
//    if (position.x < camObjVector.x - camObjSizeVector.x * 0.5)
//        testX = camObjVector.x - camObjSizeVector.x * 0.5;      // test left edge
//
//    else if (position.x > camObjVector.x + camObjSizeVector.x * 0.5)
//        testX = camObjVector.x + camObjSizeVector.x * 0.5;   // right edge
//
//    if (position.z < camObjVector.z - camObjSizeVector.z * 0.5)
//        testZ = camObjVector.z - camObjSizeVector.z * 0.5;      // top edge
//
//    else if (position.z > camObjVector.z + camObjSizeVector.z * 0.5)
//        testZ = camObjVector.z + camObjSizeVector.z * 0.5;   // bottom edge
//
//    // get distance from closest edges
//    float distX = position.x - testX;
//    float distZ = position.z - testZ;
//    float distance = sqrt((distX * distX) + (distZ * distZ));
//
//    // if the distance is less than the radius, collision!
//    if (distance <= 20) {
//        return true;
//    }
//    return false;
//}
//
//bool Camera3::isOnButton(std::vector<float>& objPos, std::vector<float>& objSize, float count)
//{
//    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
//    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
//    float distX = position.x - camObjVector.x;
//    float distZ = position.z - camObjVector.z;
//    float distance = sqrt((distX * distX) + (distZ * distZ));
//
//    // if the distance is less than the sum of the circle's
//    // radii, the circles are touching!
//    if (distance <= 3 + 10) {
//        return true;
//    }
//    return false;
//}
//
//bool Camera3::ObjIsOnButton(std::vector<float>& objPos, std::vector<float>& objSize, float count, float objx, float objz)
//{
//    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
//    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
//    float distX = objx - camObjVector.x;
//    float distZ = objz - camObjVector.z;
//    float distance = sqrt((distX * distX) + (distZ * distZ));
//
//    // if the distance is less than the sum of the circle's
//    // radii, the circles are touching!
//    if (distance <= 3 + 10) {
//        return true;
//    }
//    return false;
//}
//
//bool Camera3::inPortal(std::vector<float>& objPos, std::vector<float>& objSize, float count)
//{
//    Vector3 camObjVector = Vector3(objPos[count], objPos[count + 1], objPos[count + 2]);
//    Vector3 camObjSizeVector = Vector3(objSize[count], objSize[count + 1], objSize[count + 2]);
//    float distX = position.x - camObjVector.x;
//    float distZ = position.z - camObjVector.z;
//    float distance = sqrt((distX * distX) + (distZ * distZ));
//
//    // if the distance is less than the sum of the circle's
//    // radii, the circles are touching!
//    if (distance <= 3 + 1) {
//        return true;
//    }
//    return false;
//}



void Camera3::Reset()
{
    position = defaultPosition;
    target = defaultTarget;
    up = defaultUp;
}
