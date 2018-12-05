//
// Created by totoa on 28/11/2018.
//

#include "../include/2B3_Engine/Sphere.h"

Sphere::Sphere(RigidBody *body, Matrix4 *offset, Vector3D *center, float radius) : Primitive(body, offset),
                                                                                   center(center), radius(radius) {}

Sphere::~Sphere() {

}

Vector3D *Sphere::getCenter() const {
    return center;
}

void Sphere::setCenter(Vector3D *center) {
    Sphere::center = center;
}

float Sphere::getRadius() const {
    return radius;
}

void Sphere::setRadius(float radius) {
    Sphere::radius = radius;
}
