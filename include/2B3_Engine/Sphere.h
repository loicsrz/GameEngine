//
// Created by totoa on 28/11/2018.
//

#ifndef GAMEENGINE_SPHERE_H
#define GAMEENGINE_SPHERE_H


#include "Vector3D.h"
#include "Primitive.h"

class Sphere : Primitive{

protected:
    Vector3D * center;
    float radius;

public:
    Sphere(RigidBody *body, Matrix4 *offset, Vector3D *center, float radius);

    virtual ~Sphere();

    Vector3D *getCenter() const;

    void setCenter(Vector3D *center);

    float getRadius() const;

    void setRadius(float radius);
};


#endif //GAMEENGINE_SPHERE_H
