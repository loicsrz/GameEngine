//
// Created by vince on 05/12/2018.
//

#ifndef GAMEENGINE_PLANE_H
#define GAMEENGINE_PLANE_H


#include "Primitive.h"

class Plane : public Primitive{
public:
    Plane(Vector3D *perpendicularAngle, float offset);

    Vector3D *getPerpendicularAngle() const;

    void setPerpendicularAngle(Vector3D *perpendicularAngle);

    float getOffset() const;

    void setOffset(float offset);

    virtual ~Plane();

private:

    Vector3D * perpendicularAngle;
    float offset;

};


#endif //GAMEENGINE_PLANE_H
