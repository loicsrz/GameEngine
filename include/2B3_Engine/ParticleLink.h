//
// Created by loicsrz on 19/10/2018.
//

#ifndef GAMEENGINE_PARTICLELINK_H
#define GAMEENGINE_PARTICLELINK_H


#include "Particle.h"
#include "ParticleContactGenerator.h"

class ParticleLink : public ParticleContactGenerator {

protected:
    Particle* particle[2];

public:

    float linkLength();

    virtual void addContact( World world);


};


#endif //GAMEENGINE_PARTICLELINK_H
