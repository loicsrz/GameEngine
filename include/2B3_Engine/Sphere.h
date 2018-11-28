//
// Created by totoa on 28/11/2018.
//

#ifndef GAMEENGINE_SPHERE_H
#define GAMEENGINE_SPHERE_H


#include "Vector3D.h"

class Sphere {

protected:
    Vector3D * center;
    float radius;

public:
    Sphere(Vector3D *center, float radius);

    virtual ~Sphere();

    Vector3D *getCenter() const;

    void setCenter(Vector3D *center);

    float getRadius() const;

    void setRadius(float radius);
};


#endif //GAMEENGINE_SPHERE_H
