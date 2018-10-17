//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_PARTICLESTIFFSPRING_H
#define GAMEENGINE_PARTICLESTIFFSPRING_H


class ParticleStiffSpring {
protected:
    float anchor;
    float K;
    float damping;

public:
    ParticleStiffSpring();

    virtual ~ParticleStiffSpring();
};


#endif //GAMEENGINE_PARTICLESTIFFSPRING_H
