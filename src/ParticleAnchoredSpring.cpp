//
// Created by loicsrz on 26/09/2018.
//

#include "../include/2B3_Engine/ParticleAnchoredSpring.h"

///Constructeur par défaut
ParticleAnchoredSpring::ParticleAnchoredSpring() {

}

///Destructeur
ParticleAnchoredSpring::~ParticleAnchoredSpring() {

}

///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de gravité
void ParticleAnchoredSpring::UpdateForce(Particle *particle, float frame_duration) {
    Vector3D *d = particle->getPosition()->substractVector(anchoredPoint);
    float coef = -K*(d->getNorm()-l0);
    d = d->normalizeVector();
    particle->addForce(d->scalarMultiplier(coef));
}

///Getters - Setters -------------------------------------------------------------------------------------------------
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



Vector3D *ParticleAnchoredSpring::getAnchoredPoint() const {
    return anchoredPoint;
}

void ParticleAnchoredSpring::setAnchoredPoint(Vector3D *anchoredPoint) {
    ParticleAnchoredSpring::anchoredPoint = anchoredPoint;
}
///-------------------------------------------------------------------------------------------------------------------
