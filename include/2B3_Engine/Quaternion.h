//
// Created by loicsrz on 07/11/2018.
//


#ifndef GAMEENGINE_QUATERNION_H
#define GAMEENGINE_QUATERNION_H

class Vector3D;
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

    void doRotation(Vector3D* v);

    void UpdateAngularVelocity(Vector3D* v, float duration);

    Quaternion* operator*(Quaternion const &b);

    Quaternion* operator*(float const &number);

    Quaternion* operator+(Quaternion const &quaternion);

    float getR() const;

    void setR(float r);

    float getI() const;

    void setI(float i);

    float getJ() const;

    void setJ(float j);

    float getK() const;

    void setK(float k);

};


#endif //GAMEENGINE_QUATERNION_H
