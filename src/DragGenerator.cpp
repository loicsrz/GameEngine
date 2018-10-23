//
// Created by totoa on 19/09/2018.
//

#include <math.h>
#include "../include/2B3_Engine/DragGenerator.h"
# include <iostream>

using namespace std;
DragGenerator::DragGenerator() {}

DragGenerator::~DragGenerator() {}

void DragGenerator::UpdateForce(Particle *particle, float frame_duration) {
    float speed = particle->getVelocity()->getNorm();
    Vector3D* dragVector = particle->getVelocity();
    cout<<"Velocity X : "<<dragVector->getX()<<endl;
    cout<<"Velocity Y : "<<dragVector->getY()<<endl;
    cout<<"Velocity Z : "<<dragVector->getZ()<<endl;
    dragVector = dragVector->normalizeVector();
    cout<<"Velocity X : "<<dragVector->getX()<<endl;
    cout<<"Velocity Y : "<<dragVector->getY()<<endl;
    cout<<"Velocity Z : "<<dragVector->getZ()<<endl;
    dragVector = dragVector->scalarMultiplier(-1.0f);

    float drag = this->k1*speed + this->k2*pow(speed,2);
    dragVector = dragVector->scalarMultiplier(drag);
    cout<<"drag X : "<<dragVector->getX()<<endl;
    cout<<"drag Y : "<<dragVector->getY()<<endl;
    cout<<"drag Z : "<<dragVector->getZ()<<endl;
    particle->addForce(dragVector);
}

float DragGenerator::getK1() const {
    return k1;
}

void DragGenerator::setK1(float k1) {
    DragGenerator::k1 = k1;
}

float DragGenerator::getK2() const {
    return k2;
}

void DragGenerator::setK2(float k2) {
    DragGenerator::k2 = k2;
}
