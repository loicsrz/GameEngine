//
// Created by loicsrz on 19/10/2018.
//

#include "../include/2B3_Engine/ParticleLink.h"

float ParticleLink::cableLenght() {
    float xLenght = fabs(particle[0]->getPosition()->getX() - particle[1]->getPosition()->getX());

    float yLenght = fabs(particle[0]->getPosition()->getY() - particle[1]->getPosition()->getY());

    return sqrt((xLenght*xLenght)+(yLenght*yLenght));

}

