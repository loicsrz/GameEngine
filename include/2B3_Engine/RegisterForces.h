//
// Created by loicsrz on 19/09/2018.
//

#ifndef GAMEENGINE_REGISTERFORCES_H
#define GAMEENGINE_REGISTERFORCES_H


#include <vector>
#include "Particule.h"
#include "ParticleForceGenerator.h"

class RegisterForces {


    struct SaveForce{
        Particule *particule;
        ParticleForceGenerator *forceGenerator;
    };

    typedef std::vector<SaveForce> Register;

    void addRegister(Register *aRegister);

    void deleteRegister(Register *aRegister);

    void countRegsiter (Register *aRegister);





};


#endif //GAMEENGINE_REGISTERFORCES_H
