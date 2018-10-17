//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_WORLD_H
#define GAMEENGINE_WORLD_H

#include <vector>
#include "Particle.h"
using namespace std;
class World {

protected:
    vector<Particle*> worldParticles;
    vector<int> groundX;
    vector<int> groundY;

public:
    World();
    World(const vector<Particle*> &worldParticles);

    virtual ~World();

public:
    const vector<Particle*> &getWorldParticles() const;

    void setWorldParticles(const vector<Particle*> &worldParticles);

    void addParticleToWorld(Particle* particle);

    void eraseParticle(Particle* particle);
};


#endif //GAMEENGINE_WORLD_H
