//
// Created by totoa on 28/11/2018.
//

#include "../include/2B3_Engine/Box.h"

/// Constructeur
Box::Box(RigidBody *body, Matrix4 *offset, Vector3D *center, float semiWidth, float semiHeight, float semiDepth,
         Sphere *sphere) : Primitive(body, offset), center(center), semiWidth(semiWidth), semiHeight(semiHeight),
                           semiDepth(semiDepth), sphere(sphere) {}

/// Destructeur
Box::~Box() {
    delete center;
}

/// Getters - Setters ----------------------------------------------------------------------------------------------

Vector3D *Box::getCenter() const {
    return center;
}

void Box::setCenter(Vector3D *center) {
    Box::center = center;
}

float Box::getSemiWidth() const {
    return semiWidth;
}

void Box::setSemiWidth(float semiWidth) {
    Box::semiWidth = semiWidth;
}

float Box::getSemiHeight() const {
    return semiHeight;
}

void Box::setSemiHeight(float semiHeight) {
    Box::semiHeight = semiHeight;
}

float Box::getSemiDepth() const {
    return semiDepth;
}

void Box::setSemiDepth(float semiDepth) {
    Box::semiDepth = semiDepth;
}

Sphere *Box::getSphere() const {
    return sphere;
}

void Box::setSphere(Sphere *sphere) {
    Box::sphere = sphere;
}

vector<Vector3D *> Box::getBoxVertices() {
    vector<Vector3D*> vertices;

    Vector3D* v1 = new Vector3D(center->getX()-semiWidth,center->getY()-semiHeight,center->getZ()-semiDepth);
    Vector3D* v2 = new Vector3D(center->getX()+semiWidth,center->getY()-semiHeight,center->getZ()-semiDepth);
    Vector3D* v3 = new Vector3D(center->getX()+semiWidth,center->getY()+semiHeight,center->getZ()-semiDepth);
    Vector3D* v4 = new Vector3D(center->getX()-semiWidth,center->getY()+semiHeight,center->getZ()-semiDepth);
    Vector3D* v5 = new Vector3D(center->getX()-semiWidth,center->getY()-semiHeight,center->getZ()+semiDepth);
    Vector3D* v6 = new Vector3D(center->getX()+semiWidth,center->getY()-semiHeight,center->getZ()+semiDepth);
    Vector3D* v7 = new Vector3D(center->getX()+semiWidth,center->getY()+semiHeight,center->getZ()+semiDepth);
    Vector3D* v8 = new Vector3D(center->getX()-semiWidth,center->getY()+semiHeight,center->getZ()+semiDepth);

    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);
    vertices.push_back(v5);
    vertices.push_back(v6);
    vertices.push_back(v7);
    vertices.push_back(v8);

    return vertices;
}

/// Méthode permettant d'obtenir l'ensemble des sommets
vector<Vector3D *> Box::getAllCorners() {
    vector<Vector3D*> corners;
    for(Particle* & particle: getBody()->getBodyParticles()){
        corners.push_back(particle->getPosition());
    }
    return corners;
}


