//
// Created by totoa on 26/09/2018.
//

#ifndef GAMEENGINE_BUNGEESPRING_H
#define GAMEENGINE_BUNGEESPRING_H


#include "ParticleForceGenerator.h"

class BungeeSpring : public ParticleForceGenerator {

protected:
    Particle* secondParticle;
    float K;
    float L0;

public:
    BungeeSpring();

    virtual ~BungeeSpring();

    void UpdateForce(Particle *particle, float frame_duration) override;

    Particle *getSecondParticle() const;

    void setSecondParticle(Particle *secondParticle);

    float getK() const;

    void setK(float K);

    float getL0() const;

    void setL0(float L0);

};


#endif //GAMEENGINE_BUNGEESPRING_H
