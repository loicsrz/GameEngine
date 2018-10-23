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
    int consumedIterations;

public:
    ParticleContactResolver();

    ParticleContactResolver(int iterationsMax);

    virtual ~ParticleContactResolver();

    int getIterationsMax() const;

    int getConsumedIterations() const;

    void setIterationsMax(int iterationsMax);

    void setConsumedIterations(int consumedIterations);

    void resolveContact(vector<ParticleContact*> contactVector,float duration);


};


#endif //GAMEENGINE_PARTICLECONTACTRESOLVER_H
