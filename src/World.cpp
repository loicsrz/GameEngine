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

const int *World::getGroundX() const {
    return groundX;
}

const int *World::getGroundY() const {
    return groundY;
}

vector<ParticleLink*> World::getParticleLink() {
    return particleLinks;
}

void World::initWorld1() {
    //init world for test 1

    //Init ground
    groundX[0]=10;
    groundX[1]=20;

    groundY[0]=30;
    groundY[1]=20;
    groundY[2]=10;

    //Init particles
    Vector3D* positionA = new Vector3D(2,31,1);
    Particle* a = new Particle();
    a->setDamping(0.99);
    a->setInvertedMass(1);
    a->setPosition(positionA);
    a->setRadius(1);

    Vector3D* positionB = new Vector3D(0,31,1);
    Particle* b = new Particle();
    b->setDamping(0.99);
    b->setInvertedMass(1);
    b->setPosition(positionB);
    b->setRadius(1);

    worldParticles.push_back(a);
    worldParticles.push_back(b);

    //Init special links
//    ParticleLink* linkAB = new ParticleCable(10,0.5);
}
