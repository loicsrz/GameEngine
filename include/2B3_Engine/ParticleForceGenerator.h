//
// Created by loicsrz on 19/09/2018.
//

#ifndef GAMEENGINE_PARTICLEFORCEGENERATOR_H
#define GAMEENGINE_PARTICLEFORCEGENERATOR_H

#include "Particle.h"

///Classe ParticleForceGenerator
    ///Classe abstraite qui permet la génération de forces de tout type
class ParticleForceGenerator {

public:
    ///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force
    virtual void UpdateForce(Particle *particle, float frame_duration) = 0;

};


#endif //GAMEENGINE_PARTICLEFORCEGENERATOR_H
