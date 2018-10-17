//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_PARTICLECONTACTGENERATOR_H
#define GAMEENGINE_PARTICLECONTACTGENERATOR_H


#include "Particle.h"
#include "World.h"
#include <vector>
using namespace std;

class ParticleContactGenerator {
protected:
    vector<ParticleContact*> particleContact;

public:
    void AddContact(vector<Particle*> allparticle);


};


#endif //GAMEENGINE_PARTICLECONTACTGENERATOR_H
