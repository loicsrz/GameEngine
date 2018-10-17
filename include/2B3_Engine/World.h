//
// Created by totoa on 17/10/2018.
//

#ifndef GAMEENGINE_WORLD_H
#define GAMEENGINE_WORLD_H


#include <vector>
#include "Particle.h"
using namespace std;
class World {
protected:
    vector<Particle*> worldPaticles;
public:
    World();
    World(const vector<Particle*> &worldPaticles);

    virtual ~World();

public:
    const vector<Particle*> &getWorldPaticles() const;

    void setWorldPaticles(const vector<Particle*> &worldPaticles);

    void addParticleToWorld(Particle* particle);

    void eraseParticle(Particle* particle);
};


#endif //GAMEENGINE_WORLD_H
