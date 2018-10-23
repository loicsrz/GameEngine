//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_PARTICLECONTACTGENERATOR_H
#define GAMEENGINE_PARTICLECONTACTGENERATOR_H


#include "Particle.h"
#include "ParticleContact.h"
#include <vector>

using namespace std;

class ParticleContactGenerator {

public:
    virtual ParticleContact* addContact(Particle* particle, Particle* particle1);

    ParticleContactGenerator();

    virtual ~ParticleContactGenerator();
};
#endif


