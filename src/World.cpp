//
// Created by totoa on 17/10/2018.
//

#include "../include/2B3_Engine/World.h"

const vector<Particle*> &World::getWorldPaticles() const {
    return worldPaticles;
}

void World::setWorldPaticles(const vector<Particle*> &worldPaticles) {
    World::worldPaticles = worldPaticles;
}

World::World(const vector<Particle*> &worldPaticles) : worldPaticles(worldPaticles) {}

World::World() {}

World::~World() {

}

void World::addParticleToWorld(Particle *particle) {
    worldPaticles.push_back(particle);
}

void World::eraseParticle(Particle *particle) {
    vector<Particle*>::iterator it;
    for(it = worldPaticles.begin();it!=worldPaticles.end();it++){
        if(*it==particle){
            worldPaticles.erase(it);
            break;
        }
    }
}
