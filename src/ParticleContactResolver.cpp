//
// Created by Vince on 17/10/2018.
//

#include "../include/2B3_Engine/ParticleContactResolver.h"

void ParticleContactResolver::resolveContact(vector<ParticleContact*> contactVector) {
    vector<ParticleContact*>::iterator it;
    vector<ParticleContact*>::iterator itMinVs;
    float minVs = FLT_MAX;
    for (it = contactVector.begin(); it != contactVector.end(); it++) {
        (*it)->SpeedCompute();
    }
}

void ParticleContactResolver::setIterationsMax(int iterationsMax) {
    this->iterationsMax = iterationsMax;
}