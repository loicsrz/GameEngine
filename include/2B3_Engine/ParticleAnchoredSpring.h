//
// Created by loicsrz on 26/09/2018.
//

#ifndef GAMEENGINE_ANCHOREDPARTICLE_H
#define GAMEENGINE_ANCHOREDPARTICLE_H


#include "ParticleForceGenerator.h"

class ParticleAnchoredSpring : public ParticleForceGenerator  {

protected:
    Vector3D* anchoredPoint;
    float K;
    float l0;
public:


    float getK() const;

    void setK(float K);

    float getL0() const;

    void setL0(float l0);

public:
    ParticleAnchoredSpring();
    ~ParticleAnchoredSpring();
    void UpdateForce(Particle *particle, float frame_duration) override;

    Vector3D *getAnchoredPoint() const;

    void setAnchoredPoint(Vector3D *anchoredPoint);
};



#endif //GAMEENGINE_ANCHOREDPARTICLE_H
