//
// Created by totoa on 28/11/2018.
//

#ifndef GAMEENGINE_BOX_H
#define GAMEENGINE_BOX_H


#include "Vector3D.h"
#include "Primitive.h"
#include "Sphere.h"

class Box : public Primitive{
protected:
    Vector3D * center;
    float semiWidth; //semiX
    float semiHeight; //semiY
    float semiDepth; //semiZ
    Sphere* sphere; //Broad volume

public:
    Box(RigidBody *body, Matrix4 *offset, Vector3D *center, float semiWidth, float semiHeight, float semiDepth,
        Sphere *sphere);

    virtual ~Box();

    vector<Vector3D*> getAllCorners();

    vector<Vector3D*> getBoxVertices();

    Vector3D *getCenter() const;

    void setCenter(Vector3D *center);

    float getSemiWidth() const;

    void setSemiWidth(float semiWidth);

    float getSemiHeight() const;

    void setSemiHeight(float semiHeight);

    float getSemiDepth() const;

    void setSemiDepth(float semiDepth);

    Sphere *getSphere() const;

    void setSphere(Sphere *sphere);
};


#endif //GAMEENGINE_BOX_H
