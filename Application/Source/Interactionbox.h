#ifndef INTERACTIONBOX_H
#define INTERACTIONBOX_H

struct Interactionbox
{
    float posX, posY, posZ, sizeX, sizeY, sizeZ;
    Interactionbox(float posX = 0, float posY = 0, float posZ = 0, float sizeX = 1, float sizeY = 1, float sizeZ = 1) { Set(posX, posY, posZ, sizeX, sizeY, sizeZ); }
    void Set(float posX, float posY, float posZ, float sizeX, float sizeY, float sizeZ) {
        this->posX = posX; this->posY = posY; this->posZ = posZ;
        this->sizeX = sizeX; this->sizeY = sizeY; this->sizeZ = sizeZ;
    }
};

#endif