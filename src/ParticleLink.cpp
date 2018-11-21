//
// Created by loicsrz on 19/10/2018.
//

#include "../include/2B3_Engine/ParticleLink.h"

/// Méthode de récupération de la longueur actuelle du Link entre deux Particle
float ParticleLink::linkLength() {

    return linkedParticles[0]->getPosition()->substractVector((linkedParticles[1])->getPosition())->getNorm();
}

///Getters - Setters ------------------------------------------------------------------------------------------------
Particle *const *ParticleLink::getLinkedParticles() const {
    return linkedParticles;
}

void ParticleLink::setParticles(Particle * particleA, Particle * particleB){
    ParticleLink::linkedParticles[0] = particleA;
    ParticleLink::linkedParticles[1] = particleB;
}
///------------------------------------------------------------------------------------------------------------------



