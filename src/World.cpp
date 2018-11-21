//
// Created by loicsrz on 17/10/2018.
//
#include "../include/2B3_Engine/World.h"
#include "../include/2B3_Engine/ParticleCable.h"
#include "../include/2B3_Engine/ParticleRod.h"
#include "../include/2B3_Engine/RigidBody.h"

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
void World::clearAccums() {
    for(vector<RigidBody*>::iterator it = getWorldRigidBodies().begin();it != getWorldRigidBodies().end();++it){
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

vector<RigidBody *> &World::getWorldRigidBodies(){
    return worldRigidBodies;
}

void World::setWorldRigidBodies(vector<RigidBody *> &worldRigidBodies) {
    World::worldRigidBodies = worldRigidBodies;
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

    Quaternion* qt =  new Quaternion(1,1,0,0);

    Matrix4 * transformMatrix = new Matrix4();
    transformMatrix = transformMatrix->setOrientation(qt);
    transformMatrix->getMatrix()[3]=massCenter->getPosition()->getX();
    transformMatrix->getMatrix()[7]=massCenter->getPosition()->getY();
    transformMatrix->getMatrix()[11]=massCenter->getPosition()->getZ();

    float coefInert [9];
    coefInert[0] = vertex0->getMass()*vertex0->getPosition()->scalarProduct(new Vector3D(1,0,0))+vertex1->getMass()*vertex1->getPosition()->scalarProduct(new Vector3D(1,0,0))+vertex2->getMass()*vertex2->getPosition()->scalarProduct(new Vector3D(1,0,0));
    coefInert[1] = -(vertex0->getMass()*vertex0->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex0->getPosition()->scalarProduct(new Vector3D(0,1,0))+vertex1->getMass()*vertex1->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex1->getPosition()->scalarProduct(new Vector3D(0,1,0))+vertex2->getMass()*vertex2->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex2->getPosition()->scalarProduct(new Vector3D(0,1,0)));
    coefInert[2] = -(vertex0->getMass()*vertex0->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex0->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex1->getMass()*vertex1->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex1->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex2->getMass()*vertex2->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex2->getPosition()->scalarProduct(new Vector3D(0,0,1)));
    coefInert[3] = -(vertex0->getMass()*vertex0->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex0->getPosition()->scalarProduct(new Vector3D(0,1,0))+vertex1->getMass()*vertex1->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex1->getPosition()->scalarProduct(new Vector3D(0,1,0))+vertex2->getMass()*vertex2->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex2->getPosition()->scalarProduct(new Vector3D(0,1,0)));
    coefInert[4] = vertex0->getMass()*vertex0->getPosition()->scalarProduct(new Vector3D(0,1,0))+vertex1->getMass()*vertex1->getPosition()->scalarProduct(new Vector3D(0,1,0))+vertex2->getMass()*vertex2->getPosition()->scalarProduct(new Vector3D(0,1,0));
    coefInert[5] = -(vertex0->getMass()*vertex0->getPosition()->scalarProduct(new Vector3D(0,1,0))*vertex0->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex1->getMass()*vertex1->getPosition()->scalarProduct(new Vector3D(0,1,0))*vertex1->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex2->getMass()*vertex2->getPosition()->scalarProduct(new Vector3D(0,1,0))*vertex2->getPosition()->scalarProduct(new Vector3D(0,0,1)));
    coefInert[6] = -(vertex0->getMass()*vertex0->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex0->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex1->getMass()*vertex1->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex1->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex2->getMass()*vertex2->getPosition()->scalarProduct(new Vector3D(1,0,0))*vertex2->getPosition()->scalarProduct(new Vector3D(0,0,1)));
    coefInert[7] = -(vertex0->getMass()*vertex0->getPosition()->scalarProduct(new Vector3D(0,1,0))*vertex0->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex1->getMass()*vertex1->getPosition()->scalarProduct(new Vector3D(0,1,0))*vertex1->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex2->getMass()*vertex2->getPosition()->scalarProduct(new Vector3D(0,1,0))*vertex2->getPosition()->scalarProduct(new Vector3D(0,0,1)));
    coefInert[8] = vertex0->getMass()*vertex0->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex1->getMass()*vertex1->getPosition()->scalarProduct(new Vector3D(0,0,1))+vertex2->getMass()*vertex2->getPosition()->scalarProduct(new Vector3D(0,0,1));

    Matrix3 * invertedInertiaMatrix = new Matrix3(coefInert);
    invertedInertiaMatrix = invertedInertiaMatrix->invert();

    vector<Particle*> bodyParticles;
    bodyParticles.push_back(vertex0);
    bodyParticles.push_back(vertex1);
    bodyParticles.push_back(vertex2);

    RigidBody* rb = new RigidBody(massCenter, qt, new Vector3D(0.0f, 0.0f, 0.0f), transformMatrix, invertedInertiaMatrix,0.99,new Vector3D(0.0f,0.0f,0.0f),new Vector3D(0.0f,0.0f,0.0f),bodyParticles);

    worldRigidBodies.push_back(rb);
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