//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_WORLD_H
#define GAMEENGINE_WORLD_H

#include <vector>
#include "Particle.h"
#include "ParticleLink.h"
#include "RigidBody.h"

/// Classe World
    /// Classe qui contient tout ce qui appartient au monde en terme d'objet et de structure
class World {

protected:
    vector<Particle*> worldParticles;
    vector<RigidBody*> worldRigidBodies;
    vector<float> grounds;
    vector<float> groundSeparations;
    vector<ParticleLink*> particleLinks;

public:
    ///Constructeur par défaut
    World();

    ///Constructeur de World à partir d'un tableau de Particle
    World(const vector<Particle*> &worldParticles);

    ///Destruteur
    virtual ~World();

    /// Méthode d'ajout d'une Particle au World
    void addParticleToWorld(Particle* particle);

    /// Méthode de retrait d'une Particle au World
    void eraseParticle(Particle* particle);

    /// Méthode de réinitialisation du World
    void eraseWorld();

    /// Méthode de réinitialisation des forces accumulées par les Particle du World
    void clearAccums();

    /// Getters - Setters -----------------------------------------------------
    vector<Particle*> &getWorldParticles();

    void setWorldParticles(const vector<Particle*> &worldParticles);

    vector<float> &getGroundSeparations() ;

    void setGroundSeparations(const vector<float> &groundSeparations);

    vector<float> &getGrounds() ;

    void setGrounds(const vector<float> &grounds);

    vector<ParticleLink*> getParticleLinks();

    vector<RigidBody *> &getWorldRigidBodies();

    void setWorldRigidBodies(vector<RigidBody *> &worldRigidBodies);

    float distanceBetweenParticles(Particle* a, Particle* b);
    ///-------------------------------------------------------------------------

    /// Créations des World de démonstration -----------------------------------
    void initWorld1();

    void initWorld2();

    void initWorld3();

    void initWorld4();

    void initWorld5();

    void initWorld6();
    ///-------------------------------------------------------------------------
};


#endif //GAMEENGINE_WORLD_H
