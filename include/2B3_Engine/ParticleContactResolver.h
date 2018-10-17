//
// Created by Vince on 17/10/2018.
//

using namespace std;

#ifndef GAMEENGINE_PARTICLECONTACTRESOLVER_H
#define GAMEENGINE_PARTICLECONTACTRESOLVER_H

#include <vector>
#include "ParticleContact.h"

class ParticleContactResolver {
    friend class ParticleContact;

protected:
    int iterationsMax;
    int usedInterations;

public:
    void setIterationsMax(int iterationsMax);
    void resolveContact(vector<ParticleContact*> contactVector);
};


#endif //GAMEENGINE_PARTICLECONTACTRESOLVER_H
