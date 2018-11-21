//
// Created by totoa on 26/09/2018.
//

#include "../include/2B3_Engine/BungeeSpring.h"

///Constructeur par défaut
BungeeSpring::BungeeSpring() {}

///Destructeur
BungeeSpring::~BungeeSpring() {}

///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de ressort Bungee
void BungeeSpring::UpdateForce(Particle *particle, float frame_duration) {
    Vector3D *d = particle->getPosition()->substractVector(secondParticle->getPosition());
    float springLength = d->getNorm();
    if(springLength>L0){
        float coef = -K*(springLength-L0);
        d = d->normalizeVector();
        particle->addForce(d->scalarMultiplier(coef));
    }
}

///Getters-Setters --------------------------------------------------
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
///------------------------------------------------------------------


