//
// Created by loicsrz on 19/09/2018.
//

#ifndef GAMEENGINE_REGISTERFORCES_H
#define GAMEENGINE_REGISTERFORCES_H


#include <vector>
#include "Particle.h"
#include "ParticleForceGenerator.h"
struct SaveForce{
    Particle *particule;
    ParticleForceGenerator *forceGenerator;
};

typedef std::vector<SaveForce> Register;

class RegisterForces{

protected:
    Register m_register;

public:
    RegisterForces();
    ~RegisterForces();

    void addRegister(SaveForce saveForce);

    void deleteRegister(SaveForce saveForce);

    int countRegister (SaveForce saveForce);





};


#endif //GAMEENGINE_REGISTERFORCES_H
