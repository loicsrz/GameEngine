//
// Created by loicsrz on 26/09/2018.
//

#include "../include/2B3_Engine/AnchoredParticle.h"

float AnchoredParticle::getK() const {
    return K;
}

void AnchoredParticle::setK(float K) {
    AnchoredParticle::K = K;
}

float AnchoredParticle::getL0() const {
    return l0;
}

void AnchoredParticle::setL0(float l0) {
    AnchoredParticle::l0 = l0;
}

AnchoredParticle::AnchoredParticle() {

}

AnchoredParticle::~AnchoredParticle() {

}

Vector3D *AnchoredParticle::getAnchoredPoint() const {
    return anchoredPoint;
}

void AnchoredParticle::setAnchoredPoint(Vector3D *anchoredPoint) {
    AnchoredParticle::anchoredPoint = anchoredPoint;
}

void AnchoredParticle::UpdateForce(Particle *particle, float frame_duration) {
    Vector3D *d = particle->getPosition()->substractVector(anchoredPoint);
    float coef = -K*(d->getNorm()-l0);
    d = d->normalizeVector();
    particle->addForce(d->scalarMultiplier(coef));
}

