//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_PARTICLESTIFFSPRING_H
#define GAMEENGINE_PARTICLESTIFFSPRING_H


#include "ParticleForceGenerator.h"

class ParticleStiffSpring : public ParticleForceGenerator {
protected:
    float anchor;
    float K;
    float damping;

public:
    ParticleStiffSpring();

    virtual ~ParticleStiffSpring();

    void UpdateForce(Particle *particle, float frame_duration) override;

    float getAnchor() const;

    void setAnchor(float anchor);

    float getK() const;

    void setK(float K);

    float getDamping() const;

    void setDamping(float damping);

};


#endif //GAMEENGINE_PARTICLESTIFFSPRING_H
