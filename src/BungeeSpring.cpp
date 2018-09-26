//
// Created by totoa on 26/09/2018.
//

#include "../include/2B3_Engine/BungeeSpring.h"

BungeeSpring::BungeeSpring() {}

BungeeSpring::~BungeeSpring() {}

void BungeeSpring::UpdateForce(Particle *particle, float frame_duration) {
    Vector3D *d = particle->getPosition()->substractVector(secondParticle.getPosition());
    float springLength = d->getNorm();
    if(springLength<=l0){
        float coef = -K*(springLength-l0);
        d = d->normalizeVector();
        particle->addForce(d->scalarMultiplier(coef));
    }
}

const Particle &BungeeSpring::getSecondParticle() const {
    return secondParticle;
}

void BungeeSpring::setSecondParticle(const Particle &secondParticle) {
    BungeeSpring::secondParticle = secondParticle;
}

float BungeeSpring::getK() const {
    return K;
}

void BungeeSpring::setK(float K) {
    BungeeSpring::K = K;
}

float BungeeSpring::getL0() const {
    return l0;
}

void BungeeSpring::setL0(float l0) {
    BungeeSpring::l0 = l0;
}


