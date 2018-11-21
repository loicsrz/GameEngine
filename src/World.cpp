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
    worldRigidBodies.clear();
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

float World::distanceBetweenParticles(Particle* a, Particle* b)
{
    return (a->getPosition()->substractVector(b->getPosition()))->getNorm();
}

///------------------------------------------------------------------------------------------------------------------

/// Créations des World de démonstration ----------------------------------------------------------------------------
void World::initWorld1() {
    //init world for test 1

    //Init ground
    grounds.push_back(-13.0f);

    //Init Particles
    auto * massCenter = new Particle(new Vector3D(-200.0f, 10.0f, 0.0f),new Vector3D(1.0f,0.5f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex0 = new Particle(new Vector3D(massCenter->getPosition()->getX()-10.0f, massCenter->getPosition()->getY()-20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1 = new Particle(new Vector3D(massCenter->getPosition()->getX()+10.0f, massCenter->getPosition()->getY()-20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex2 = new Particle(new Vector3D(massCenter->getPosition()->getX()+10.0f, massCenter->getPosition()->getY()+20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex3 = new Particle(new Vector3D(massCenter->getPosition()->getX()-10.0f, massCenter->getPosition()->getY()+20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);

    auto * vertex4 = new Particle(new Vector3D(massCenter->getPosition()->getX()-10.0f, massCenter->getPosition()->getY()-20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex5 = new Particle(new Vector3D(massCenter->getPosition()->getX()+10.0f, massCenter->getPosition()->getY()-20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex6 = new Particle(new Vector3D(massCenter->getPosition()->getX()+10.0f, massCenter->getPosition()->getY()+20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex7 = new Particle(new Vector3D(massCenter->getPosition()->getX()-10.0f, massCenter->getPosition()->getY()+20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);

    vector<Particle*> bodyParticles;
    bodyParticles.push_back(vertex0);
    bodyParticles.push_back(vertex1);
    bodyParticles.push_back(vertex2);
    bodyParticles.push_back(vertex3);
    bodyParticles.push_back(vertex4);
    bodyParticles.push_back(vertex5);
    bodyParticles.push_back(vertex6);
    bodyParticles.push_back(vertex7);

    vector<Vector3D*> particleObjectPositions;

    float x;
    float y;
    float z;

    for(Particle * &particle : bodyParticles){
        x = particle->getPosition()->getX() - massCenter->getPosition()->getX();
        y = particle->getPosition()->getY() - massCenter->getPosition()->getY();
        z = particle->getPosition()->getZ() - massCenter->getPosition()->getZ();
        particleObjectPositions.push_back(new Vector3D(x,y,z));
    }

    float totalMass = 0.0f;
    totalMass += massCenter->getMass();
    for(Particle* &particle : bodyParticles){
        totalMass += particle->getMass();
    }


    Quaternion* qt =  new Quaternion(1,0,0,0);
    qt->normalize();
    Matrix4 * transformMatrix = new Matrix4();
    transformMatrix = transformMatrix->setOrientation(qt);
    transformMatrix->setValue(3, massCenter->getPosition()->getX());
    transformMatrix->setValue(7, massCenter->getPosition()->getY());
    transformMatrix->setValue(11, massCenter->getPosition()->getZ());
    transformMatrix->toString();

    vector<float> coefInert;
    for (int i = 0; i < 9; ++i) {
        coefInert.push_back(0.0f);
    }
    coefInert[0] = (1.0f/12.0f)*totalMass*(40.0f*40.0f+40.0f*40.0f);
    coefInert[1] = 0 ;
    coefInert[2] = 0 ;
    coefInert[3] = 0 ;
    coefInert[4] = (1.0f/12.0f)*totalMass*(20.0f*20.0f+40.0f*40.0f);
    coefInert[5] = 0 ;
    coefInert[6] = 0 ;
    coefInert[7] = 0 ;
    coefInert[8] = (1.0f/12.0f)*totalMass*(20.0f*20.0f+40.0f*40.0f);
    Matrix3 * invertedInertiaMatrix = new Matrix3(coefInert);
    invertedInertiaMatrix = invertedInertiaMatrix->invert();



    RigidBody* rb = new RigidBody(massCenter, qt, new Vector3D(0.0f, 0.0f, 0.09f), transformMatrix, invertedInertiaMatrix,0.99,new Vector3D(0.0f,0.0f,0.0f),new Vector3D(0.0f,0.0f,0.0f),bodyParticles);

    rb->setParticleObjectPositions(particleObjectPositions);

    worldRigidBodies.push_back(rb);
}

void World::initWorld2() {
    //init world for test 2

    //Init ground
    grounds.push_back(-13.0f);

    //Init First car
    auto * massCenter1 = new Particle(new Vector3D(-200.0f, 10.0f, 0.0f),new Vector3D(2.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_0 = new Particle(new Vector3D(massCenter1->getPosition()->getX()-10.0f, massCenter1->getPosition()->getY()-20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_1 = new Particle(new Vector3D(massCenter1->getPosition()->getX()+10.0f, massCenter1->getPosition()->getY()-20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_2 = new Particle(new Vector3D(massCenter1->getPosition()->getX()+10.0f, massCenter1->getPosition()->getY()+20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_3 = new Particle(new Vector3D(massCenter1->getPosition()->getX()-10.0f, massCenter1->getPosition()->getY()+20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);

    auto * vertex1_4 = new Particle(new Vector3D(massCenter1->getPosition()->getX()-10.0f, massCenter1->getPosition()->getY()-20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_5 = new Particle(new Vector3D(massCenter1->getPosition()->getX()+10.0f, massCenter1->getPosition()->getY()-20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_6 = new Particle(new Vector3D(massCenter1->getPosition()->getX()+10.0f, massCenter1->getPosition()->getY()+20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex1_7 = new Particle(new Vector3D(massCenter1->getPosition()->getX()-10.0f, massCenter1->getPosition()->getY()+20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);

    //Init Second car
    auto * massCenter2 = new Particle(new Vector3D(200.0f, 10.0f, 30.0f),new Vector3D(-2.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex2_0 = new Particle(new Vector3D(massCenter2->getPosition()->getX()-10.0f, massCenter2->getPosition()->getY()-20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex2_1 = new Particle(new Vector3D(massCenter2->getPosition()->getX()+10.0f, massCenter2->getPosition()->getY()-20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex2_2 = new Particle(new Vector3D(massCenter2->getPosition()->getX()+10.0f, massCenter2->getPosition()->getY()+20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex2_3 = new Particle(new Vector3D(massCenter2->getPosition()->getX()-10.0f, massCenter2->getPosition()->getY()+20.0f,
                                               -20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);

    auto * vertex2_4 = new Particle(new Vector3D(massCenter2->getPosition()->getX()-10.0f, massCenter2->getPosition()->getY()-20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex2_5 = new Particle(new Vector3D(massCenter2->getPosition()->getX()+10.0f, massCenter2->getPosition()->getY()-20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex2_6 = new Particle(new Vector3D(massCenter2->getPosition()->getX()+10.0f, massCenter2->getPosition()->getY()+20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
    auto * vertex2_7 = new Particle(new Vector3D(massCenter2->getPosition()->getX()-10.0f, massCenter2->getPosition()->getY()+20.0f,
                                               20.0f),new Vector3D(0.0f,0.0f,0.0f), new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);

    vector<Particle*> bodyParticles1;
    bodyParticles1.push_back(vertex1_0);
    bodyParticles1.push_back(vertex1_1);
    bodyParticles1.push_back(vertex1_2);
    bodyParticles1.push_back(vertex1_3);
    bodyParticles1.push_back(vertex1_4);
    bodyParticles1.push_back(vertex1_5);
    bodyParticles1.push_back(vertex1_6);
    bodyParticles1.push_back(vertex1_7);

    vector<Particle*> bodyParticles2;
    bodyParticles2.push_back(vertex2_0);
    bodyParticles2.push_back(vertex2_1);
    bodyParticles2.push_back(vertex2_2);
    bodyParticles2.push_back(vertex2_3);
    bodyParticles2.push_back(vertex2_4);
    bodyParticles2.push_back(vertex2_5);
    bodyParticles2.push_back(vertex2_6);
    bodyParticles2.push_back(vertex2_7);

    vector<Vector3D*> particleObjectPositions1;
    vector<Vector3D*> particleObjectPositions2;

    float x;
    float y;
    float z;

    for(Particle * &particle : bodyParticles1){
        x = particle->getPosition()->getX() - massCenter1->getPosition()->getX();
        y = particle->getPosition()->getY() - massCenter1->getPosition()->getY();
        z = particle->getPosition()->getZ() - massCenter1->getPosition()->getZ();
        particleObjectPositions1.push_back(new Vector3D(x,y,z));
    }

    for(Particle * &particle : bodyParticles2){
        x = particle->getPosition()->getX() - massCenter2->getPosition()->getX();
        y = particle->getPosition()->getY() - massCenter2->getPosition()->getY();
        z = particle->getPosition()->getZ() - massCenter2->getPosition()->getZ();
        particleObjectPositions2.push_back(new Vector3D(x,y,z));
    }

    float totalMass1 = 0.0f;
    totalMass1 += massCenter1->getMass();
    for(Particle* &particle : bodyParticles1){
        totalMass1 += particle->getMass();
    }

    float totalMass2 = 0.0f;
    totalMass2 += massCenter2->getMass();
    for(Particle* &particle : bodyParticles2){
        totalMass2 += particle->getMass();
    }


    Quaternion* qt1 =  new Quaternion(1,0,0,0);

    Quaternion* qt2 =  new Quaternion(1,0,0,0);

    Matrix4 * transformMatrix1 = new Matrix4();
    transformMatrix1 = transformMatrix1->setOrientation(qt1);
    transformMatrix1->setValue(3, massCenter1->getPosition()->getX());
    transformMatrix1->setValue(7, massCenter1->getPosition()->getY());
    transformMatrix1->setValue(11, massCenter1->getPosition()->getZ());

    Matrix4 * transformMatrix2 = new Matrix4();
    transformMatrix2 = transformMatrix2->setOrientation(qt2);
    transformMatrix2->setValue(3, massCenter2->getPosition()->getX());
    transformMatrix2->setValue(7, massCenter2->getPosition()->getY());
    transformMatrix2->setValue(11, massCenter2->getPosition()->getZ());

    vector<float> coefInert;
    for (int i = 0; i < 9; ++i) {
        coefInert.push_back(0.0f);
    }
    coefInert[0] = (1.0f/12.0f)*totalMass1*(40.0f*40.0f+40.0f*40.0f);
    coefInert[1] = 0 ;
    coefInert[2] = 0 ;
    coefInert[3] = 0 ;
    coefInert[4] = (1.0f/12.0f)*totalMass1*(20.0f*20.0f+40.0f*40.0f);
    coefInert[5] = 0 ;
    coefInert[6] = 0 ;
    coefInert[7] = 0 ;
    coefInert[8] = (1.0f/12.0f)*totalMass1*(20.0f*20.0f+40.0f*40.0f);
    Matrix3 * invertedInertiaMatrix1 = new Matrix3(coefInert);
    invertedInertiaMatrix1 = invertedInertiaMatrix1->invert();

    coefInert[0] = (1.0f/12.0f)*totalMass2*(40.0f*40.0f+40.0f*40.0f);
    coefInert[1] = 0 ;
    coefInert[2] = 0 ;
    coefInert[3] = 0 ;
    coefInert[4] = (1.0f/12.0f)*totalMass2*(20.0f*20.0f+40.0f*40.0f);
    coefInert[5] = 0 ;
    coefInert[6] = 0 ;
    coefInert[7] = 0 ;
    coefInert[8] = (1.0f/12.0f)*totalMass2*(20.0f*20.0f+40.0f*40.0f);
    Matrix3 * invertedInertiaMatrix2 = new Matrix3(coefInert);
    invertedInertiaMatrix2 = invertedInertiaMatrix2->invert();

    RigidBody* rb1 = new RigidBody(massCenter1, qt1, new Vector3D(0.0f, 0.0f, 0.0f), transformMatrix1, invertedInertiaMatrix1,0.99,new Vector3D(0.0f,0.0f,0.0f),new Vector3D(0.0f,0.0f,0.0f),bodyParticles1);

    RigidBody* rb2 = new RigidBody(massCenter2, qt2, new Vector3D(0.0f, 0.0f, 0.0f), transformMatrix2, invertedInertiaMatrix2,0.99,new Vector3D(0.0f,0.0f,0.0f),new Vector3D(0.0f,0.0f,0.0f),bodyParticles2);

    rb1->setParticleObjectPositions(particleObjectPositions1);

    rb2->setParticleObjectPositions(particleObjectPositions2);

    worldRigidBodies.push_back(rb1);

    worldRigidBodies.push_back(rb2);
}


///------------------------------------------------------------------------------------------------------------------