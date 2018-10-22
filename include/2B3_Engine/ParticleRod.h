//
// Created by loicsrz on 21/10/2018.
//

#ifndef GAMEENGINE_PARTICLEROD_H
#define GAMEENGINE_PARTICLEROD_H


#include "ParticleLink.h"

class ParticleRod : public ParticleLink{

protected:

    float maxLenght;
    float restitutionCoefficient;

public:
    void addContact();


};


#endif //GAMEENGINE_PARTICLEROD_H
