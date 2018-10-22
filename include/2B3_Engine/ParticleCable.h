//
// Created by loicsrz on 19/10/2018.
//

#ifndef GAMEENGINE_PARTICLECABLE_H
#define GAMEENGINE_PARTICLECABLE_H


#include "ParticleLink.h"

class ParticleCable : public ParticleLink {
protected:

    float maxLenght;
    float restitutionCoefficient;

public:

    void AddContact(World world);

};


#endif //GAMEENGINE_PARTICLECABLE_H
