//
// Created by loicsrz on 26/09/2018.
//

#include "../include/2B3_Engine/ParticleAnchoredSpring.h"
#include <iostream>
using namespace std;

void ParticleAnchoredSpring::UpdateForce(Particle *particle, float frame_duration) {
    Vector3D *d = particle->getPosition()->substractVector(anchoredPoint);
    float coef = -K*(d->getNorm()-l0);
    d = d->normalizeVector();
    particle->addForce(d->scalarMultiplier(coef));
}

float ParticleAnchoredSpring::getK() const {
    return K;
}

void ParticleAnchoredSpring::setK(float K) {
    ParticleAnchoredSpring::K = K;
}

float ParticleAnchoredSpring::getL0() const {
    return l0;
}

void ParticleAnchoredSpring::setL0(float l0) {
    ParticleAnchoredSpring::l0 = l0;
}

ParticleAnchoredSpring::ParticleAnchoredSpring() {

}

ParticleAnchoredSpring::~ParticleAnchoredSpring() {

}

Vector3D *ParticleAnchoredSpring::getAnchoredPoint() const {
    return anchoredPoint;
}

void ParticleAnchoredSpring::setAnchoredPoint(Vector3D *anchoredPoint) {
    ParticleAnchoredSpring::anchoredPoint = anchoredPoint;
    cout<<"APX :"<<anchoredPoint->getX()<<endl;
    cout<<"APY :"<<anchoredPoint->getY()<<endl;
    cout<<"APZ :"<<anchoredPoint->getZ()<<endl;
}

