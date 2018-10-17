//
// Created by loicsrz on 17/10/2018.
//
#include "../include/2B3_Engine/World.h"

const vector<Particle*> &World::getWorldParticles() const {
    return worldParticles;
}

void World::setWorldParticles(const vector<Particle*> &worldParticles) {
    World::worldParticles = worldParticles;
}

World::World(const vector<Particle*> &worldParticles) : worldParticles(worldParticles) {}

World::World() {}

World::~World() {}

void World::addParticleToWorld(Particle *particle) {
    worldParticles.push_back(particle);
}

void World::eraseParticle(Particle *particle) {
    vector<Particle*>::iterator it;
    for(it = worldParticles.begin();it!=worldParticles.end();it++){
        if(*it==particle){
            worldParticles.erase(it);
            break;
        }
    }
}
