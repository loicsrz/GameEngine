//
// Created by loicsrz on 17/10/2018.
//
#include "../include/2B3_Engine/World.h"
#include "../include/2B3_Engine/ParticleCable.h"

vector<Particle*> &World::getWorldParticles() {
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


vector<ParticleLink*> World::getParticleLinks() {
    return particleLinks;
}

void World::initWorld1() {
    //init world for test 1

    //Init ground and separations
    groundSeparations.push_back(150.0f);
    groundSeparations.push_back(300.0f);

    grounds.push_back(100.0f);
    grounds.push_back(0.0f);
    grounds.push_back(-200.0f);

    //Init linkedParticles
    Vector3D* positionA = new Vector3D(-0.5f,0.51f,0.0f);
    Vector3D* speedA = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accA = new Vector3D(0.0f,0.0f,0.0f);
    Particle* a = new Particle();
    a->setDamping(0.99);
    a->setInvertedMass(10);
    a->setPosition(positionA);
    a->setVelocity(speedA);
    a->setAcceleration(accA);
    a->setRadius(5.0f);

    Vector3D* positionB = new Vector3D(400.0f,100.0f,0.0f);

    Vector3D* speedB = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accB = new Vector3D(0.0f,0.0f,0.0f);
    Particle* b = new Particle();
    b->setDamping(0.99);
    b->setInvertedMass(10);
    b->setPosition(positionB);
    b->setVelocity(speedB);
    b->setAcceleration(accB);
    b->setRadius(5.0f);

    worldParticles.push_back(a);
    worldParticles.push_back(b);

    //Init special links
//    ParticleLink* linkAB = new ParticleCable(10,0.5);
}

void World::eraseWorld() {
    worldParticles.clear();
    particleLinks.clear();
    groundSeparations.clear();
    grounds.clear();
}

vector<float> &World::getGroundSeparations()  {
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

void World::clearForceAccums() {
    for(vector<Particle*>::iterator it = worldParticles.begin();it != worldParticles.end();++it){
        (*it)->clearAccumulator();
    }
}
