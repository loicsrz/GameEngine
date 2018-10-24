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
    groundSeparations.clear();
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

///------------------------------------------------------------------------------------------------------------------

/// Créations des World de démonstration ----------------------------------------------------------------------------
void World::initWorld1() {
    //init world for test 1

    //Init ground
    grounds.push_back(-200.0f);

    //Init Particles
    Vector3D* positionA = new Vector3D(-0.5f,0.0f,0.0f);
    Vector3D* speedA = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accA = new Vector3D(0.0f,0.0f,0.0f);
    Particle* a = new Particle();
    a->setDamping(0.99f);
    a->setInvertedMass(1);
    a->setPosition(positionA);
    a->setVelocity(speedA);
    a->setAcceleration(accA);
    a->setRadius(5.0f);

    Vector3D* positionB = new Vector3D(400.0f,0.0f,0.0f);
    Vector3D* speedB = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accB = new Vector3D(0.0f,0.0f,0.0f);
    Particle* b = new Particle();
    b->setDamping(0.99f);
    b->setInvertedMass(1);
    b->setPosition(positionB);
    b->setVelocity(speedB);
    b->setAcceleration(accB);
    b->setRadius(5.0f);

    worldParticles.push_back(a);
    worldParticles.push_back(b);
}

void World::initWorld2() {
    //init world for test 1

    //Init ground
    grounds.push_back(0.0f);

    //Init Particle
    Vector3D* positionA = new Vector3D(-0.5f,50.0f,0.0f);
    Vector3D* speedA = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accA = new Vector3D(0.0f,0.0f,0.0f);
    Particle* a = new Particle();
    a->setDamping(0.99);
    a->setInvertedMass(1);
    a->setPosition(positionA);
    a->setVelocity(speedA);
    a->setAcceleration(accA);
    a->setRadius(5.0f);

    worldParticles.push_back(a);
}

void World::initWorld3() {
    //init world for test 3

    //Init ground
    grounds.push_back(-200.0f);

    //Init Particle
    Vector3D* positionA = new Vector3D(50.0f,150.0f,0.0f);
    Vector3D* speedA = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accA = new Vector3D(0.0f,0.0f,0.0f);
    Particle* a = new Particle();
    a->setDamping(0.99f);
    a->setInvertedMass(1);
    a->setPosition(positionA);
    a->setVelocity(speedA);
    a->setAcceleration(accA);
    a->setRadius(5.0f);

    worldParticles.push_back(a);
}

void World::initWorld4() {
    //init world for test 4

    //Init ground
    grounds.push_back(-200.0f);

    //Init Particle
    Vector3D* positionA = new Vector3D(250.0f,50.0f,0.0f);
    Vector3D* speedA = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accA = new Vector3D(0.0f,0.0f,0.0f);
    Particle* a = new Particle();
    a->setDamping(0.99f);
    a->setInvertedMass(1);
    a->setPosition(positionA);
    a->setVelocity(speedA);
    a->setAcceleration(accA);
    a->setRadius(5.0f);

    worldParticles.push_back(a);
}

void World::initWorld5() {
    //Init ground and separations

    grounds.push_back(0.0f);

    //Init Particles
    Vector3D* positionA = new Vector3D(80.0f,5.0f,0.0f);
    Vector3D* speedA = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accA = new Vector3D(0.0f,0.0f,0.0f);
    Particle* a = new Particle();
    a->setDamping(0.99f);
    a->setInvertedMass(1);
    a->setPosition(positionA);
    a->setVelocity(speedA);
    a->setAcceleration(accA);
    a->setRadius(5.0f);

    Vector3D* positionB = new Vector3D(180.0f,5.0f,0.0f);
    Vector3D* speedB = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accB = new Vector3D(0.0f,0.0f,0.0f);
    Particle* b = new Particle();
    b->setDamping(0.99f);
    b->setInvertedMass(1);
    b->setPosition(positionB);
    b->setVelocity(speedB);
    b->setAcceleration(accB);
    b->setRadius(5.0f);

    worldParticles.push_back(a);
    worldParticles.push_back(b);

    ParticleLink* linkAB = new ParticleRod(100,0.05f);
    linkAB->setParticles(a,b);

    particleLinks.push_back(linkAB);
}

void World::initWorld6() {
//init world for test 5

    //Init ground and separations
    groundSeparations.push_back(150.0f);
    groundSeparations.push_back(300.0f);

    grounds.push_back(0.0f);
    grounds.push_back(-100.0f);
    grounds.push_back(-200.0f);

    //Init Particles
    Vector3D* positionA = new Vector3D(10.0f,20.0f,0.0f);
    Vector3D* speedA = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accA = new Vector3D(0.0f,0.0f,0.0f);
    Particle* a = new Particle();
    a->setDamping(0.99f);
    a->setInvertedMass(1);
    a->setPosition(positionA);
    a->setVelocity(speedA);
    a->setAcceleration(accA);
    a->setRadius(5.0f);

    Vector3D* positionB = new Vector3D(30.0f,20.0f,0.0f);
    Vector3D* speedB = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accB = new Vector3D(0.0f,0.0f,0.0f);
    Particle* b = new Particle();
    b->setDamping(0.99f);
    b->setInvertedMass(1);
    b->setPosition(positionB);
    b->setVelocity(speedB);
    b->setAcceleration(accB);
    b->setRadius(5.0f);

    Vector3D* positionC = new Vector3D(20.0f,20.0f,0.0f);
    Vector3D* speedC = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accC = new Vector3D(0.0f,0.0f,0.0f);
    Particle* c = new Particle();
    c->setDamping(1.0f);
    c->setInvertedMass(1);
    c->setPosition(positionC);
    c->setVelocity(speedC);
    c->setAcceleration(accC);
    c->setRadius(5.0f);

    Vector3D* positionD = new Vector3D(40.0f,27.0f,0.0f);
    Vector3D* speedD = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accD = new Vector3D(0.0f,0.0f,0.0f);
    Particle* d = new Particle();
    d->setDamping(0.99f);
    d->setInvertedMass(1);
    d->setPosition(positionD);
    d->setVelocity(speedD);
    d->setAcceleration(accD);
    d->setRadius(5.0f);

    Vector3D* positionE = new Vector3D(35.0f,40.0f,0.0f);
    Vector3D* speedE = new Vector3D(0.0f,0.0f,0.0f);
    Vector3D* accE = new Vector3D(0.0f,0.0f,0.0f);
    Particle* e = new Particle();
    e->setDamping(0.99f);
    e->setInvertedMass(1);
    e->setPosition(positionE);
    e->setVelocity(speedE);
    e->setAcceleration(accE);
    e->setRadius(5.0f);

    worldParticles.push_back(a);
    worldParticles.push_back(b);
    worldParticles.push_back(c);
    worldParticles.push_back(d);
    worldParticles.push_back(e);

    //Init special links
    ParticleLink* linkAB = new ParticleCable(100,0.05f);
    linkAB->setParticles(a,b);

    ParticleLink* linkAC = new ParticleCable(100,0.05f);
    linkAC->setParticles(a,c);

    ParticleLink* linkAD = new ParticleCable(100,0.05f);
    linkAD->setParticles(a,d);

    ParticleLink* linkAE = new ParticleCable(100,0.05f);
    linkAE->setParticles(a,e);

    particleLinks.push_back(linkAB);
    particleLinks.push_back(linkAC);
    particleLinks.push_back(linkAD);
    particleLinks.push_back(linkAE);
}
///------------------------------------------------------------------------------------------------------------------