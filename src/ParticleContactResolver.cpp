//
// Created by Vince on 17/10/2018.
//

#include "../include/2B3_Engine/ParticleContactResolver.h"
#include <algorithm>

using namespace std;



void ParticleContactResolver::resolveContact(vector<ParticleContact*> contactVector,float duration) {

    sort(contactVector.begin(),contactVector.end(),[] (ParticleContact* a, ParticleContact* b) { return (*a < *b); });
    for(auto it = contactVector.begin();it!=contactVector.end();it++){
        if(consumedIterations>iterationsMax){
            break;
        }
        (*it)->Resolve(duration);
        consumedIterations++;
    }


}

void ParticleContactResolver::setIterationsMax(int iterationsMax) {
    this->iterationsMax = iterationsMax;
}

int ParticleContactResolver::getIterationsMax() const {
    return iterationsMax;
}

int ParticleContactResolver::getConsumedIterations() const {
    return consumedIterations;
}

ParticleContactResolver::ParticleContactResolver(int iterationsMax) : iterationsMax(iterationsMax),consumedIterations(0) {}

ParticleContactResolver::~ParticleContactResolver() {

}


