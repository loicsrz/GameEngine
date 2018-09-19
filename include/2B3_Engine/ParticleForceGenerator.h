//
// Created by loicsrz on 19/09/2018.
//

#ifndef GAMEENGINE_PARTICLEFORCEGENERATOR_H
#define GAMEENGINE_PARTICLEFORCEGENERATOR_H

#include "Particle.h"

class ParticleForceGenerator {

public:
    virtual void UpdateForce(Particle *particule, float frame_duration) = 0;

};


#endif //GAMEENGINE_PARTICLEFORCEGENERATOR_H
