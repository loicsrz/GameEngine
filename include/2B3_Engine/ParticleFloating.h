//
// Created by totoa on 26/09/2018.
//

#ifndef GAMEENGINE_PARTICLEFLOATING_H
#define GAMEENGINE_PARTICLEFLOATING_H


#include "ParticleForceGenerator.h"
#include<iostream>

class ParticleFloating : public ParticleForceGenerator {
protected:
    float depth;
    float volume;
    float liquidLevel;
    float liquidDensity;

public:
    ParticleFloating();

    virtual ~ParticleFloating();

    void UpdateForce(Particle *particle, float frame_duration) override;

    float getDepth() const;

    void setDepth(float depth);

    float getVolume() const;

    void setVolume(float volume);

    float getLiquidLevel() const;

    void setLiquidLevel(float liquidLevel);

    float getLiquidDensity() const;

    void setLiquidDensity(float liquidDensity);
};


#endif //GAMEENGINE_PARTICLEFLOATING_H
