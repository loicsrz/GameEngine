//
// Created by totoa on 22/10/2018.
//

#ifndef GAMEENGINE_WORLDPHYSICS_H
#define GAMEENGINE_WORLDPHYSICS_H

#include <vector>
#include "Particle.h"
#include "ParticleContact.h"
#include "World.h"
#include "RegisterForces.h"
#include "ParticleContactResolver.h"

using namespace std;

class WorldPhysics {
protected:
    vector<ParticleContact*> contacts;
    ParticleContactGenerator contactGenerator;
    RegisterForces registerForces;
    ParticleContactResolver contactResolver;
public:

    WorldPhysics();

    virtual ~WorldPhysics();

    void initWorldPhysics1(World world);

    void initWorldPhysics2(World world);

    const vector<ParticleContact *> &getContacts() const;

    void setContacts(const vector<ParticleContact *> &contacts);

    void applyForces(float duration);

    void particlesIntegrator(vector<Particle *> particles, float deltaTime);

    void searchAndResolveContactsWithGround(World world);

    void searchContacts(World world);

    void resolveContacts(float duration);

    void initFrameContactResolver(int nbIterMax);

    const ParticleContactResolver &getContactResolver() const;

    void setContactResolver(const ParticleContactResolver &contactResolver);

    void erasePhysics();

    void initWorldPhysics3(World world);

    void initWorldPhysics4(World world);

    void initWorldPhysics5(World world);

    void initWorldPhysics6(World world);
};


#endif //GAMEENGINE_WORLDPHYSICS_H
