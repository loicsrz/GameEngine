//
// Created by loicsrz on 17/10/2018.
//
#include "../include/2B3_Engine/World.h"
#include "../include/2B3_Engine/ParticleCable.h"
#include "../include/2B3_Engine/ParticleRod.h"

///Constructeur par défaut
World::World() {}

///Constructeur de World à partir d'un tableau de Particle
World::World(const vector<Particle*> &worldParticles) : worldParticles(worldParticles) {}

///Destruteur
World::~World() {}

/// Méthode d'ajout d'une Particle au World
void World::addParticleToWorld(Particle *particle) {
    worldParticles.push_back(particle);
}

/// Méthode de retrait d'une Particle au World
void World::eraseParticle(Particle *particle) {
    vector<Particle*>::iterator it;
    for(it = worldParticles.begin();it!=worldParticles.end();it++){
        if(*it==particle){
            worldParticles.erase(it);
            break;
        }
    }
}

/// Méthode de réinitialisation du World
void World::eraseWorld() {
    worldParticles.clear();
    particleLinks.clear();
    grounds.clear();
}

/// Méthode de réinitialisation des forces accumulées par les Particle du World
void World::clearForceAccums() {
    for(vector<Particle*>::iterator it = worldParticles.begin();it != worldParticles.end();++it){
        (*it)->clearAccumulator();
    }
}

/// Getters - Setters -----------------------------------------------------------------------------------------------

vector<Particle*> &World::getWorldParticles() {
    return worldParticles;
}

void World::setWorldParticles(const vector<Particle*> &worldParticles) {
    World::worldParticles = worldParticles;
}

vector<ParticleLink*> World::getParticleLinks() {
    return particleLinks;
}

vector<float> &World::getGroundSeparations() {
    return groundSeparations;
}

void World::setGroundSeparations(const vector<float> &groundSeparations) {
    World::groundSeparations = groundSeparations;
}

vector<float> &World::getGrounds()  {
    return grounds;
}

void World::setGrounds(const vector<float> &grounds) {
    World::grounds = grounds;
}

///------------------------------------------------------------------------------------------------------------------

/// Créations des World de démonstration ----------------------------------------------------------------------------
void World::initWorld1() {
    //init world for test 1

    //Init ground
    grounds.push_back(-13.0f);

    //Init Particles
    auto * massCenter = new Particle(new Vector3D(0.0f, 2.0f, 0.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex0 = new Particle(new Vector3D(massCenter->getPosition()->getX()-20.0f, massCenter->getPosition()->getY()-15.0f,
            0.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1 = new Particle(new Vector3D(massCenter->getPosition()->getX()+5.0f, massCenter->getPosition()->getY()+25.0f,
            0.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex2 = new Particle(new Vector3D(massCenter->getPosition()->getX()+20.0f, massCenter->getPosition()->getY()-15.0f,
            0.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);


    worldParticles.push_back(massCenter);
    worldParticles.push_back(vertex0);
    worldParticles.push_back(vertex1);
    worldParticles.push_back(vertex2);
}

void World::initWorld2() {
    //init world for test 2

    //Init First car
    auto * massCenter1 = new Particle(new Vector3D(0.0f, 2.0f, 0.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_0 = new Particle(new Vector3D(massCenter1->getPosition()->getX()-20.0f, massCenter1->getPosition()->getY()-15.0f,
                                               0.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_1 = new Particle(new Vector3D(massCenter1->getPosition()->getX()+5.0f, massCenter1->getPosition()->getY()+25.0f,
                                               0.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_2 = new Particle(new Vector3D(massCenter1->getPosition()->getX()+20.0f, massCenter1->getPosition()->getY()-15.0f,
                                               0.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_3 = new Particle(new Vector3D(massCenter1->getPosition()->getX()+20.0f, massCenter1->getPosition()->getY()-15.0f,
                                                 0.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);

    worldParticles.push_back(massCenter1);
    worldParticles.push_back(vertex1_0);
    worldParticles.push_back(vertex1_1);
    worldParticles.push_back(vertex1_2);
    worldParticles.push_back(vertex1_3);
}
///------------------------------------------------------------------------------------------------------------------