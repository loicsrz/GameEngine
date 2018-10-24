//
// Created by Vince on 26/09/2018.
//

#include "../include/2B3_Engine/ParticleSpring.h"

///Constructeur par défaut
ParticleSpring::ParticleSpring() {}

///Destructeur
ParticleSpring::~ParticleSpring() {}

///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de ressort classique
void ParticleSpring::UpdateForce(Particle *particle, float frame_duration) {
    Vector3D *d = particle->getPosition()->substractVector(secondParticle->getPosition());
    float coef = -K*(d->getNorm()-l0);
    d = d->normalizeVector();
    particle->addForce(d->scalarMultiplier(coef));
}

///Getters - Setters -------------------------------------------------------------------------------------------------
Particle * ParticleSpring::getSecondParticle(){
    return secondParticle;
}

float ParticleSpring::getK() const {
    return K;
}

float ParticleSpring::getL0() const {
    return l0;
}

void ParticleSpring::setSecondParticle( Particle * secondParticle) {
    ParticleSpring::secondParticle = secondParticle;
}

void ParticleSpring::setK(float K) {
    ParticleSpring::K = K;
}

void ParticleSpring::setL0(float l0) {
    ParticleSpring::l0 = l0;
}
///-------------------------------------------------------------------------------------------------------------------