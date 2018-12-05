//
// Created by vince on 05/12/2018.
//

#include "../include/2B3_Engine/Plane.h"

Plane::Plane(RigidBody *body, Matrix4 *offset1, Vector3D *perpendicularAngle, float offset) : Primitive(body, offset1),
                                                                                              perpendicularAngle(perpendicularAngle),
                                                                                              offset(offset)
{

}

Plane::~Plane() {
    delete perpendicularAngle;
}

Vector3D *Plane::getPerpendicularAngle() const {
    return perpendicularAngle;
}

void Plane::setPerpendicularAngle(Vector3D *perpendicularAngle) {
    Plane::perpendicularAngle = perpendicularAngle;
}

float Plane::getOffset() const {
    return offset;
}

void Plane::setOffset(float offset) {
    Plane::offset = offset;
}
