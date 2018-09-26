//
// Created by totoa on 26/09/2018.
//

#ifndef GAMEENGINE_BUNGEESPRING_H
#define GAMEENGINE_BUNGEESPRING_H


#include "ParticleForceGenerator.h"

class BungeeSpring : ParticleForceGenerator {

protected:
    Particle secondParticle;
    float K;
    float l0;

public:
    BungeeSpring();

    virtual ~BungeeSpring();

    void UpdateForce(Particle *particle, float frame_duration) override;

    const Particle &getSecondParticle() const;

    void setSecondParticle(const Particle &secondParticle);

    float getK() const;

    void setK(float K);

    float getL0() const;

    void setL0(float l0);

};


#endif //GAMEENGINE_BUNGEESPRING_H
