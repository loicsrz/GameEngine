//
// Created by Vince on 20/09/2018.
//

#include "../include/2B3_Engine/GravityGenerator.h"

GravityGenerator::GravityGenerator() {

}

GravityGenerator::~GravityGenerator() {

}

void GravityGenerator::UpdateForce(Particle *particle, float frame_duration) {
    if(particle->getMass()==0) return;
    particle->addForce(gravity.scalarMultiplier(particle->getMass()));
}

const Vector3D &GravityGenerator::getGravity() const {
    return gravity;
}

void GravityGenerator::setGravity(const Vector3D &gravity) {
    GravityGenerator::gravity = gravity;
}
