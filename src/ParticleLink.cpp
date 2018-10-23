//
// Created by loicsrz on 19/10/2018.
//

#include "../include/2B3_Engine/ParticleLink.h"

float ParticleLink::linkLength() {
    float xLenght = fabs(linkedParticles[0]->getPosition()->getX() - linkedParticles[1]->getPosition()->getX());

    float yLenght = fabs(linkedParticles[0]->getPosition()->getY() - linkedParticles[1]->getPosition()->getY());

    return sqrt((xLenght*xLenght)+(yLenght*yLenght));

}

Particle *const *ParticleLink::getLinkedParticles() const {
    return linkedParticles;
}



