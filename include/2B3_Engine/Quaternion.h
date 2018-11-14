//
// Created by loicsrz on 07/11/2018.
//

#ifndef GAMEENGINE_QUATERNION_H
#define GAMEENGINE_QUATERNION_H


#include "Vector3D.h"

class Quaternion {

protected:
    float r;
    float i;
    float j;
    float k;

public:

    Quaternion(float a, float b, float c, float d);

    ~Quaternion();

    void normalize();

    void doRotation(Vector3D v);

    void UpdateAngularVelocity(Vector3D v, float duration);

    Quaternion* operator*(Quaternion const &b);

    Quaternion* operator*(float const &number);

    Quaternion* operator+(Quaternion const &quaternion);

};


#endif //GAMEENGINE_QUATERNION_H
