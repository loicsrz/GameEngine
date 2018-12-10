//
// Created by totoa on 22/10/2018.
//

#include "../include/2B3_Engine/WorldPhysics.h"
#include "../include/2B3_Engine/Particle.h"
#include "../include/2B3_Engine/World.h"
#include "../include/2B3_Engine/BungeeSpring.h"
#include "../include/2B3_Engine/GravityGenerator.h"
#include "../include/2B3_Engine/DragGenerator.h"
#include "../include/2B3_Engine/ParticleFloating.h"
#include "../include/2B3_Engine/ParticleAnchoredSpring.h"
#include "../include/2B3_Engine/ParticleStiffSpring.h"
#include "../include/2B3_Engine/ParticleSpring.h"
#include "../include/2B3_Engine/Box.h"

/// Constructeur par défaut
WorldPhysics::WorldPhysics() {
}

/// Destructeur
WorldPhysics::~WorldPhysics() {

}

/// Méthode de réinitialisation de la physique du World
void WorldPhysics::erasePhysics() {
    contacts.clear();
    registerForces.clearRegister();
}

/// Méthode de génération de forces pour toutes les particules concernées par ces dernières
void WorldPhysics::applyForces(float duration) {
    for(auto it = registerForces.m_register.begin();it != registerForces.m_register.end();it++){
        it->forceGenerator->UpdateForce(it->particle,duration);
    }
}

/// Méthode d'intégration permettant de mettre à jour la position, la vitesse et l'accélération des Particle du World
void WorldPhysics::particlesIntegrator(vector<Particle *> particles, float deltaTime) {

    for (auto &particle : particles) {
        particle->integrator(deltaTime);
    }
}

/// Méthode de recherche et résolution des contacts entre les Particle du World et le sol
void WorldPhysics::searchAndResolveContactsWithGround(World world) {
    vector<Particle*>::iterator iterator;
    vector<float>::iterator separations;
    bool isLastValue = true;
    int currentIndex =0;
    for (iterator = world.getWorldParticles().begin(); iterator != world.getWorldParticles().end(); iterator++) {
        isLastValue = true;
        currentIndex = 0;
        for (separations = world.getGroundSeparations().begin();separations != world.getGroundSeparations().end(); separations++) {
            if ((*iterator)->getPosition()->getX() < (*separations)) {
                if ((*iterator)->getPosition()->getY() < world.getGrounds()[currentIndex]) {
                    (*iterator)->getPosition()->setY(world.getGrounds()[currentIndex] + (*iterator)->getRadius());
                }
                isLastValue = false;
                break;
            }
            currentIndex++;
        }
        if (isLastValue) {
            if ((*iterator)->getPosition()->getY() < world.getGrounds()[currentIndex]) {
                (*iterator)->getPosition()->setY(world.getGrounds()[currentIndex] + (*iterator)->getRadius());
            }
        }
    }
}

/// Méthode de recherche et création de tous les contacts présents pour une Frame de jeu
void WorldPhysics::searchContacts(World world){

    vector<Particle*>::iterator iterator;
    vector<Particle*>::iterator iterator1;

    contacts.clear();

    for (iterator = world.getWorldParticles().begin();iterator != world.getWorldParticles().end(); iterator++){

        for (iterator1 = iterator+1 ;iterator1 != world.getWorldParticles().end(); iterator1++){

            ParticleContact* contact = contactGenerator.addContact((*iterator), (*iterator1));
            if(contact != nullptr){
                contacts.push_back(contact);
            }
        }
    }

    // Ajout contacts Rod and cables
    vector<ParticleLink*> links = world.getParticleLinks();
    for(auto it = links.begin();it != links.end();it++){
        ParticleContact* contact = (*it)->addContact();
        if(contact != nullptr){
            contacts.push_back(contact);
        }
    }
}

/// Méthode de résolution des contacts détectés préalablement
void WorldPhysics::resolveContacts(float duration) {
    contactResolver.resolveContact(contacts,duration);
}

/// Méthode de réinitialisation du resolver de contact utilisé à chaque Frame de jeu
void WorldPhysics::initFrameContactResolver(int nbIterMax) {
    contactResolver.setIterationsMax(2*nbIterMax);
    contactResolver.setConsumedIterations(0);
}

/// Méthode d'intégration permettant de mettre à jour les informations des RigidBody du World
void WorldPhysics::rigidBodyIntegrator(vector<Primitive *> objects, float deltaTime) {
    for (auto &object : objects) {
        object->getBody()->integrator(deltaTime);
    }
}

///Méthode de mise à jour des forceAccum de tous les rigidBody
void WorldPhysics::updateAllRigidBodiesAccum(vector<Primitive *> objects) {
    for(Primitive* &object : objects){
        object->getBody()->updateAllAccum();
    }
}

void WorldPhysics::generateContacts(Primitive *prim1, Primitive *prim2) {

    float equation;
    Plane * plane = dynamic_cast<Plane*>(prim1);
    Box * box = dynamic_cast<Box*>(prim2);
    for (Vector3D * & corner : box->getAllCorners())
    {
        equation = plane->getPerpendicularAngle()->getX()*corner->getX()+plane->getPerpendicularAngle()->getY()*corner->getY()
                + plane->getPerpendicularAngle()->getZ()*corner->getZ() + plane->getOffset();
        if(equation < 0)
        {
            Contact * contact = new Contact(corner,plane->getPerpendicularAngle(),equation);
            data->Addcontact(contact);
            break;
        }
    }
}

void WorldPhysics::contactType() {
    if(data->getContacts().size() == 1)
    {
        cout << "Sommet - Face" << endl;
    }
    else if (data->getContacts().size() == 2)
    {
        cout << "Arête - Face" << endl;
    }
    else if (data->getContacts().size() == 4)
    {
        cout << "Face - Face" << endl;
    }
    else
    {
        cout << "No contact" << endl;
    }

}


/// Getters - Setters -----------------------------------------------------------------------------------------------

const vector<ParticleContact *> &WorldPhysics::getContacts() const {
    return contacts;
}

void WorldPhysics::setContacts(const vector<ParticleContact *> &contacts) {
    WorldPhysics::contacts = contacts;
}

const ParticleContactResolver &WorldPhysics::getContactResolver() const {
    return contactResolver;
}

void WorldPhysics::setContactResolver(const ParticleContactResolver &contactResolver) {
    WorldPhysics::contactResolver = contactResolver;
}

const vector<pair<Primitive *, Primitive *>> &WorldPhysics::getPotentialCollisions() const {
    return potentialCollisions;
}

void WorldPhysics::setPotentialCollisions(const vector<pair<Primitive *, Primitive *>> &potentialCollisions) {
    WorldPhysics::potentialCollisions = potentialCollisions;
}

CollisionData *WorldPhysics::getData() const {
    return data;
}

void WorldPhysics::setData(CollisionData *data) {
    WorldPhysics::data = data;
}
///------------------------------------------------------------------------------------------------------------------

/// Génération de la physique de chacun des World de démonstration --------------------------------------------------
void WorldPhysics::initWorldPhysics1(World world) {
//    ParticleForceGenerator* grav = new GravityGenerator();
//    Vector3D * gravity = new Vector3D(0,-0.003f,0);
//    dynamic_cast<GravityGenerator*>(grav)->setGravity(gravity);
//
////    ParticleForceGenerator* drag = new DragGenerator();
////    dynamic_cast<DragGenerator*>(drag)->setK1(0.04f);
////    dynamic_cast<DragGenerator*>(drag)->setK2(0);
//
//    SaveForce grav1{world.getWorldObjects()[0]->getBody()->getMassCenter(),grav};
//
//    registerForces.addRegister(grav1);

}

void WorldPhysics::initWorldPhysics2(World world) {
    //Empty
}

void WorldPhysics::searchAllPotentialContacts(vector<Primitive *> objects, BSPNode * root) {
    BSPNode * currentNode = root;
    Sphere * currentSphere;
    for(Primitive* & object : objects){
        Box * box = dynamic_cast<Box *>(object);
        currentSphere = box->getSphere();
        while(currentNode->getBack() != nullptr){
            Plane * collider = currentNode->getCollider();
            float distance = abs(collider->getPerpendicularAngle()->scalarProduct(currentSphere->getCenter())+collider->getOffset());
            distance = distance / sqrtf(powf(collider->getPerpendicularAngle()->getX(),2)+powf(collider->getPerpendicularAngle()->getY(),2)+powf(collider->getPerpendicularAngle()->getZ(),2));
            if(currentSphere->getRadius()<distance){
                potentialCollisions.push_back(pair<Primitive *, Primitive *>(object,currentNode->getPlane()));
            }

            currentNode = currentNode->getBack();
        }

        currentNode = root;
    }
}

void WorldPhysics::generateAllContacts() {
    for(pair<Primitive*, Primitive*> &potentialCollision : potentialCollisions){
        generateContacts(potentialCollision.first,potentialCollision.second);
    }
}

void WorldPhysics::resetAllCollisions() {
    data->resetCollisionData();
    potentialCollisions.clear();
}






///------------------------------------------------------------------------------------------------------------------