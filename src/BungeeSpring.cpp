//
// Created by totoa on 26/09/2018.
//

#include "../include/2B3_Engine/BungeeSpring.h"
#include <iostream>

using namespace std;
BungeeSpring::BungeeSpring() {}

BungeeSpring::~BungeeSpring() {}

void BungeeSpring::UpdateForce(Particle *particle, float frame_duration) {
    Vector3D *d = particle->getPosition()->substractVector(secondParticle->getPosition());
    float springLength = d->getNorm();
    if(springLength>L0){
        float coef = -K*(springLength-L0);
        d = d->normalizeVector();
        particle->addForce(d->scalarMultiplier(coef));
    }
}

float BungeeSpring::getK() const {
    return K;
}

void BungeeSpring::setK(float K) {
    BungeeSpring::K = K;
}

float BungeeSpring::getL0() const {
    return L0;
}

void BungeeSpring::setL0(float L0) {
    BungeeSpring::L0 = L0;
}

Particle *BungeeSpring::getSecondParticle() const {
    return secondParticle;
}

void BungeeSpring::setSecondParticle(Particle *secondParticle) {
    BungeeSpring::secondParticle = secondParticle;
}


