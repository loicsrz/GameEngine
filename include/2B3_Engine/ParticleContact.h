//
// Created by Vince on 17/10/2018.
//

#ifndef GAMEENGINE_PARTICLECONTACT_H
#define GAMEENGINE_PARTICLECONTACT_H

#include "Particle.h"

class ParticleContact {
    friend class ParticleContactResolver;

protected:
    Particle* particles[2];
    float restitution;
    Vector3D* perpendicularAngle;
    float penetration;
    //Vector3D* interpenetrationResolvingMovement;

public:
    void Resolve(float duration);
    float SpeedCompute() const;
    void ImpulsionResolve(float duration);
    void InterpenetrationResolve(float duration);
};

#endif //GAMEENGINE_PARTICLECONTACT_H
