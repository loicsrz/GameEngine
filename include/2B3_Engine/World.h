//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_WORLD_H
#define GAMEENGINE_WORLD_H

#include <vector>
#include "Particle.h"
#include "ParticleLink.h"

using namespace std;

class World {

protected:
    vector<Particle*> worldParticles;
    int groundX[2];
    int groundY[3];
    vector<ParticleLink*> particleLinks;

public:
    const int *getGroundX() const;
    const int *getGroundY() const;

public:
    World();
    World(const vector<Particle*> &worldParticles);

    virtual ~World();

public:
    vector<Particle*> &getWorldParticles();

    void setWorldParticles(const vector<Particle*> &worldParticles);

    vector<ParticleLink*> getParticleLinks();

    void addParticleToWorld(Particle* particle);

    void eraseParticle(Particle* particle);

    void initWorld1();
};


#endif //GAMEENGINE_WORLD_H
