//
// Created by Vince on 17/10/2018.
//

#include "../include/2B3_Engine/ParticleContact.h"

void ParticleContact::Resolve(float duration) {
    InterpenetrationResolve(duration);
    ImpulsionResolve(duration);
}

float ParticleContact::SpeedCompute() const {
    Particle* A = particles[0];
    Particle* B = particles[1];
    float vS = A->getVelocity()->substractVector(B->getVelocity())->scalarProduct(perpendicularAngle);
    return (- restitution * vS);
}

void ParticleContact::ImpulsionResolve(float duration) {
    Particle* A = particles[0];
    Particle* B = particles[1];
    float vS = SpeedCompute();
    Vector3D* velocity0 = perpendicularAngle->scalarMultiplier(vS);
    Vector3D* velocity1 = velocity0->scalarMultiplier(-1.0f);

    A->setVelocity(A->getVelocity()->addVector(velocity0->scalarMultiplier(A->getInvertedMass())));
    B->setVelocity(B->getVelocity()->addVector(velocity1->scalarMultiplier(B->getInvertedMass())));
}

void ParticleContact::InterpenetrationResolve(float duration) {
    Particle* A = particles[0];
    Particle* B = particles[1];
    Vector3D* deltaPosA = perpendicularAngle->scalarMultiplier((B->getMass() * penetration) / (A->getMass() + B->getMass()));
    Vector3D* deltaPosB = perpendicularAngle->scalarMultiplier(-1 * (A->getMass() * penetration) / (A->getMass() + B->getMass()));

    A->setPosition(A->getPosition()->addVector(deltaPosA));
    B->setPosition(B->getPosition()->addVector(deltaPosB));
}
