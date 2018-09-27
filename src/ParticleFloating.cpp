//
// Created by totoa on 26/09/2018.
//

#include "../include/2B3_Engine/ParticleFloating.h"

ParticleFloating::ParticleFloating() {}

ParticleFloating::~ParticleFloating() {}

void ParticleFloating::UpdateForce(Particle *particle, float frame_duration) {
    float d = (particle->getPosition()->getY() - liquidLevel - depth)/ 2*depth;
    Vector3D * direction = new Vector3D(0,1,0);
    if(d<=0){
        return;
    }
    else if(d>=1){
        direction = direction->scalarMultiplier(volume*liquidDensity);
    }
    else{
        direction = direction->scalarMultiplier(d*volume*liquidDensity);
    }

    particle->addForce(direction);
}

float ParticleFloating::getDepth() const {
    return depth;
}

void ParticleFloating::setDepth(float depth) {
    ParticleFloating::depth = depth;
}

float ParticleFloating::getVolume() const {
    return volume;
}

void ParticleFloating::setVolume(float volume) {
    ParticleFloating::volume = volume;
}

float ParticleFloating::getLiquidLevel() const {
    return liquidLevel;
}

void ParticleFloating::setLiquidLevel(float liquidLevel) {
    ParticleFloating::liquidLevel = liquidLevel;
}

float ParticleFloating::getLiquidDensity() const {
    return liquidDensity;
}

void ParticleFloating::setLiquidDensity(float liquidDensity) {
    ParticleFloating::liquidDensity = liquidDensity;
}

