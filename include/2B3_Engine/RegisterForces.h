//
// Created by loicsrz on 19/09/2018.
//

#ifndef GAMEENGINE_REGISTERFORCES_H
#define GAMEENGINE_REGISTERFORCES_H


#include <vector>
#include "Particle.h"
#include "ParticleForceGenerator.h"

struct SaveForce {
    Particle *particle;
    ParticleForceGenerator *forceGenerator;
};

typedef std::vector<SaveForce> Register;

class RegisterForces {

public:
    Register m_register;

public:
    RegisterForces();

    ~RegisterForces();

    void addRegister(SaveForce saveForce);

    void deleteRegister(SaveForce saveForce);

    int countRegister();

    void clearRegister();
};


#endif //GAMEENGINE_REGISTERFORCES_H
