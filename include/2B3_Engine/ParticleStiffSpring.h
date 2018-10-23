//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_PARTICLESTIFFSPRING_H
#define GAMEENGINE_PARTICLESTIFFSPRING_H


#include "ParticleForceGenerator.h"

class ParticleStiffSpring : public ParticleForceGenerator {
protected:
    Vector3D* anchor;
    float K;
    float damping;

public:
    ParticleStiffSpring();

    virtual ~ParticleStiffSpring();

    void UpdateForce(Particle *particle, float frame_duration) override;

    Vector3D* getAnchor() const;

    void setAnchor(Vector3D* anchor);

    float getK() const;

    void setK(float K);

    float getDamping() const;

    void setDamping(float damping);

};


#endif //GAMEENGINE_PARTICLESTIFFSPRING_H
