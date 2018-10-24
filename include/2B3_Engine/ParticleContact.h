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
    bool isLink;
    //Vector3D* interpenetrationResolvingMovement;

public:
    ParticleContact(Particle **mParticles, float restitution, Vector3D *perpendicularAngle, float penetration, bool isLink);

    virtual ~ParticleContact();

    void Resolve(float duration);
    float SpeedCompute() const;
    void ImpulsionResolve(float duration);
    void InterpenetrationResolve(float duration);

    Particle *const *getParticles() const;

    float getRestitution() const;

    void setRestitution(float restitution);

    Vector3D *getPerpendicularAngle() const;

    void setPerpendicularAngle(Vector3D *perpendicularAngle);

    float getPenetration() const;

    void setPenetration(float penetration);

    bool operator<(ParticleContact const &b);
};

#endif //GAMEENGINE_PARTICLECONTACT_H
