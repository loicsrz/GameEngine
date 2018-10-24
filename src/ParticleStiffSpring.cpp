//
// Created by loicsrz on 17/10/2018.
//

#include "../include/2B3_Engine/ParticleStiffSpring.h"

ParticleStiffSpring::ParticleStiffSpring() {}

ParticleStiffSpring::~ParticleStiffSpring() {}

void ParticleStiffSpring::UpdateForce(Particle *particle, float frame_duration) {

    Vector3D *distance = particle->getPosition()->substractVector(anchor);

    float gamma = cos((1.0f / 2.0f) * sqrt((4 * K) - (damping * damping)));

    Vector3D *direction = distance->scalarMultiplier(cosf(gamma * frame_duration))->addVector(
            distance->scalarMultiplier(damping / (2.0f * gamma))->addVector(
                    particle->getVelocity()->scalarMultiplier(1.0f / gamma))->scalarMultiplier(
                    sinf(gamma * frame_duration)))->scalarMultiplier(expf(-1.0f / 2.0f * frame_duration * damping));

    Vector3D *acceleration = direction->substractVector(distance)->scalarMultiplier(
            1.0f / (frame_duration * frame_duration))->substractVector(particle->getVelocity()->scalarMultiplier(frame_duration));

    particle->addForce(acceleration->scalarMultiplier(particle->getMass()));

}

Vector3D *ParticleStiffSpring::getAnchor() const {
    return anchor;
}

void ParticleStiffSpring::setAnchor(Vector3D *anchor) {
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




