//
// Created by loicsrz on 17/10/2018.
//

#include "../include/2B3_Engine/ParticleStiffSpring.h"

ParticleStiffSpring::ParticleStiffSpring() {}

ParticleStiffSpring::~ParticleStiffSpring() {}

void ParticleStiffSpring::UpdateForce(Particle *particle, float frame_duration) {

    float gamma = cos((1/2)*sqrt((4*K)-(damping*damping)));
    Vector3D * direction = particle->getPosition()->scalarMultiplier(gamma*frame_duration)
           ->addVector(particle->getPosition()->scalarMultiplier(damping/(2*gamma))->addVector(particle->getVelocity()->scalarMultiplier(1/gamma))
           ->scalarMultiplier(sin(gamma*frame_duration)))->scalarMultiplier(exp((-1/2)*damping*frame_duration));

    Vector3D * acceleration = direction->substractVector(particle->getPosition())->scalarMultiplier(1/(frame_duration*frame_duration));
    acceleration = acceleration->substractVector(particle->getVelocity());

    particle->addForce(acceleration->scalarMultiplier(particle->getMass()));

}

float ParticleStiffSpring::getAnchor() const {
    return anchor;
}

void ParticleStiffSpring::setAnchor(float anchor) {
    ParticleStiffSpring::anchor = anchor;
}

float ParticleStiffSpring::getK() const {
    return K;
}

void ParticleStiffSpring::setK(float K) {
    ParticleStiffSpring::K = K;
}

float ParticleStiffSpring::getDamping() const {
    return damping;
}

void ParticleStiffSpring::setDamping(float damping) {
    ParticleStiffSpring::damping = damping;
}




