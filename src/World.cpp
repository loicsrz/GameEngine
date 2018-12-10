//
// Created by loicsrz on 17/10/2018.
//
#include "../include/2B3_Engine/World.h"
#include "../include/2B3_Engine/ParticleCable.h"
#include "../include/2B3_Engine/ParticleRod.h"
#include "../include/2B3_Engine/RigidBody.h"
#include "../include/2B3_Engine/Box.h"
#include "../include/2B3_Engine/BSPNode.h"


///Constructeur par défaut
World::World() {}

///Constructeur de World à partir d'un tableau de Particle
World::World(const vector<Particle*> &worldParticles) : worldParticles(worldParticles) {}

///Destruteur
World::~World() {
    delete root;
}

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
    worldObjects.clear();
    grounds.clear();
}

/// Méthode de réinitialisation des forces accumulées par les Particle du World
void World::clearAccums() {
    for(vector<Primitive*>::iterator it = getWorldObjects().begin();it != getWorldObjects().end();++it){
        (*it)->getBody()->clearAccumulator();
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

vector<Primitive *> &World::getWorldObjects(){
    return worldObjects;
}

void World::setWorldObjects(vector<Primitive *> &worldObjects) {
    World::getWorldObjects() = worldObjects;
}

float World::distanceBetweenParticles(Particle* a, Particle* b)
{
    return (a->getPosition()->substractVector(b->getPosition()))->getNorm();
}

///------------------------------------------------------------------------------------------------------------------

/// Créations des World de démonstration ----------------------------------------------------------------------------
void World::initWorld1() {
    //init world for test 1

    //Init Particles
    auto * massCenter = new Particle(new Vector3D(0.0f, 0.0f, 0.0f),new Vector3D(((float) (rand() % 100 + 1)/5)-10,
                                                                                 ((float) (rand() % 100 + 1)/5)-10,
                                                                                 ((float) (rand() % 100 + 1)/5)-10),
                                                                                        new Vector3D(0.0f,0.0f,0.0f), 1.0f, 1.0f);
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

    RigidBody* rb = new RigidBody(massCenter, qt, new Vector3D(0.0f, 0.0f, 0.0f), transformMatrix, invertedInertiaMatrix,0.99f,new Vector3D(0.0f,0.0f,0.0f),new Vector3D(0.0f,0.0f,0.0f),bodyParticles);

    rb->setParticleObjectPositions(particleObjectPositions);

    Box* box = new Box(rb, nullptr, rb->getMassCenter()->getPosition(), 0.0f, 0.0f, 0.0f, new Sphere(nullptr, nullptr, rb->getMassCenter()->getPosition(), distanceBetweenParticles(rb->getMassCenter(), rb->getBodyParticles()[0])));

    worldObjects.push_back(box);

    Plane * plane1 = new Plane(nullptr, nullptr, new Vector3D(1, 0, 0), -300);
    Plane * plane2 = new Plane(nullptr, nullptr, new Vector3D(-1, 0, 0), -300);
    Plane * plane3 = new Plane(nullptr, nullptr, new Vector3D(0, 1, 0), -300);
    Plane * plane4 = new Plane(nullptr, nullptr, new Vector3D(0, -1, 0), -300);
    Plane * plane5 = new Plane(nullptr, nullptr, new Vector3D(0, 0, 1), -300);
    Plane * plane6 = new Plane(nullptr, nullptr, new Vector3D(0, 0, -1), -300);
    //Walls creation
    walls.push_back(plane1); //Right wall
    walls.push_back(plane2); //Left wall
    walls.push_back(plane3); //Top wall
    walls.push_back(plane4); //Bottom wall
    walls.push_back(plane5); //Front wall
    walls.push_back(plane6); //Back wall

    BSPNode* backNode = new BSPNode(plane6,new Plane(nullptr, nullptr, new Vector3D(0, 0, -1), -299), nullptr, nullptr);
    BSPNode* frontNode = new BSPNode(plane5,new Plane(nullptr, nullptr, new Vector3D(0, 0, 1), -299), nullptr, backNode);
    BSPNode* bottomNode = new BSPNode(plane4,new Plane(nullptr, nullptr, new Vector3D(0, -1, 0), -299), nullptr, frontNode);
    BSPNode* topNode = new BSPNode(plane3,new Plane(nullptr, nullptr, new Vector3D(0, 1, 0), -299), nullptr, bottomNode);
    BSPNode* leftNode = new BSPNode(plane2,new Plane(nullptr, nullptr, new Vector3D(-1, 0, 0), -299), nullptr, topNode);
    root = new BSPNode(plane1,new Plane(nullptr, nullptr, new Vector3D(1, 0, 0), -299), nullptr, leftNode); //Right node

}

void World::initWorld2() {
    //init world for test 2


}

const vector<Plane *> &World::getWalls() const {
    return walls;
}

void World::setWalls(const vector<Plane *> &walls) {
    World::walls = walls;
}

BSPNode *World::getRoot() {
    return root;
}

void World::setRoot(BSPNode *root) {
    World::root = root;
}

///------------------------------------------------------------------------------------------------------------------
