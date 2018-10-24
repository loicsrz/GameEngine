//
// Created by loicsrz on 21/10/2018.
//

#ifndef GAMEENGINE_PARTICLEROD_H
#define GAMEENGINE_PARTICLEROD_H


#include "ParticleLink.h"

class ParticleRod : public ParticleLink{

protected:

    float maxLength;
    float restitutionCoefficient;

public:
    ParticleRod(float maxLenght, float restitutionCoefficient);

    virtual ~ParticleRod();

    virtual ParticleContact* addContact();


};


#endif //GAMEENGINE_PARTICLEROD_H
