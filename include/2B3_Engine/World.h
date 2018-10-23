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
    vector<float > groundSeparations;
    vector<float> grounds;
    vector<ParticleLink*> particleLinks;

public:
    World();
    World(const vector<Particle*> &worldParticles);

    virtual ~World();

    vector<Particle*> &getWorldParticles();

    void setWorldParticles(const vector<Particle*> &worldParticles);

    vector<ParticleLink*> getParticleLinks();

    void addParticleToWorld(Particle* particle);

    void eraseParticle(Particle* particle);

    void initWorld1();

    void eraseWorld();

    vector<float> &getGroundSeparations() ;

    void setGroundSeparations(const vector<float> &groundSeparations);

    vector<float> &getGrounds() ;

    void setGrounds(const vector<float> &grounds);

    void clearForceAccums();

    void initWorld3();
};


#endif //GAMEENGINE_WORLD_H
