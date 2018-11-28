//
// Created by totoa on 28/11/2018.
//

#include "Sphere.h"

Sphere::Sphere(Vector3D *center, float radius) : center(center), radius(radius) {}

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
