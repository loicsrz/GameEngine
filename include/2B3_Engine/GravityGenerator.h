//
// Created by Vince on 20/09/2018.
//

#ifndef GAMEENGINE_GRAVITYGENERATOR_H
#define GAMEENGINE_GRAVITYGENERATOR_H


#include "ParticleForceGenerator.h"

class GravityGenerator : ParticleForceGenerator {
    ///Attributs
protected:
    Vector3D gravity;

public:
    GravityGenerator();
    ~GravityGenerator();

    void UpdateForce(Particle *particle, float frame_duration) override;

    const Vector3D &getGravity() const;

    void setGravity(const Vector3D &gravity);
};


#endif //GAMEENGINE_GRAVITYGENERATOR_H
