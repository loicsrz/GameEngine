//
// Created by totoa on 22/10/2018.
//

#include "../include/2B3_Engine/WorldPhysics.h"
#include "../include/2B3_Engine/Particle.h"
#include "../include/2B3_Engine/World.h"
#include "../include/2B3_Engine/BungeeSpring.h"
#include "../include/2B3_Engine/GravityGenerator.h"
#include "../include/2B3_Engine/DragGenerator.h"

using namespace std;

void WorldPhysics::particlesIntegrator(vector<Particle *> particles, float deltaTime) {

//    int n = 1;
    for (auto &particle : particles) {
        /*cout << "Particle " << n << " :" << endl;
        cout << "Avant Integration : " << endl;
        cout << "Position : " << endl;
        cout << '\t' << "x : " << (*it)->getPosition()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getPosition()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getPosition()->getZ() << endl;
        cout << "Velocite : " << endl;
        cout << '\t' << "x : " << (*it)->getVelocite()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getVelocite()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getVelocite()->getZ() << endl;
        cout << "Acceleration : " << endl;
        cout << '\t' << "x : " << (*it)->getAcceleration()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getAcceleration()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getAcceleration()->getZ() << endl;*/
        particle->integrator(deltaTime);
        /*cout << "Après Integration : " << endl;
        cout << "Position : " << endl;
        cout << '\t' << "x : " << (*it)->getPosition()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getPosition()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getPosition()->getZ() << endl;
        cout << "Velocite : " << endl;
        cout << '\t' << "x : " << (*it)->getVelocite()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getVelocite()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getVelocite()->getZ() << endl;
        cout << "Acceleration : " << endl;
        cout << '\t' << "x : " << (*it)->getAcceleration()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getAcceleration()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getAcceleration()->getZ() << endl;
        cout << endl;
        n++;*/
    }
}

const vector<ParticleContact *> &WorldPhysics::getContacts() const {
    return contacts;
}

void WorldPhysics::setContacts(const vector<ParticleContact *> &contacts) {
    WorldPhysics::contacts = contacts;
}

void WorldPhysics::searchAndResolveContactsWithGround(World world) {
    vector<Particle*>::iterator iterator;
    vector<float>::iterator separations;
    bool isLastValue = true;
    int currentIndex = 0;
    for (iterator = world.getWorldParticles().begin(); iterator != world.getWorldParticles().end(); iterator++) {

        for (separations = world.getGroundSeparations().begin();
             separations != world.getGroundSeparations().end(); ++separations) {
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

void WorldPhysics::searchContacts(World world){

    vector<Particle*>::iterator iterator;
    vector<Particle*>::iterator iterator1;

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

void WorldPhysics::applyForces(float duration) {
    for(auto it = registerForces.m_register.begin();it != registerForces.m_register.end();it++){
        it->forceGenerator->UpdateForce(it->particle,duration);
    }
}

void WorldPhysics::resolveContacts(float duration) {
    contactResolver.resolveContact(contacts,duration);
}

void WorldPhysics::initFrameContactResolver(int nbIterMax) {
    contactResolver.setIterationsMax(2*nbIterMax);
    contactResolver.setConsumedIterations(0);
}

WorldPhysics::WorldPhysics() {
}

WorldPhysics::~WorldPhysics() {

}

void WorldPhysics::initWorldPhysics1(World world) {
//    ParticleForceGenerator* bs1 = new BungeeSpring();
//    dynamic_cast<BungeeSpring*>(bs1)->setK(2);
//    dynamic_cast<BungeeSpring*>(bs1)->setL0(4);
//    dynamic_cast<BungeeSpring*>(bs1)->setSecondParticle(*(world.getWorldParticles()[1]));
//
//    ParticleForceGenerator* bs2 = new BungeeSpring();
//    dynamic_cast<BungeeSpring*>(bs2)->setK(2);
//    dynamic_cast<BungeeSpring*>(bs2)->setL0(4);
//    dynamic_cast<BungeeSpring*>(bs2)->setSecondParticle(*(world.getWorldParticles()[0]));

    ParticleForceGenerator* grav = new GravityGenerator();
    Vector3D * gravity = new Vector3D(0,-10.0f,0);
    dynamic_cast<GravityGenerator*>(grav)->setGravity(*gravity);

    ParticleForceGenerator* drag = new DragGenerator();
    dynamic_cast<DragGenerator*>(drag)->setK1(1);
    dynamic_cast<DragGenerator*>(drag)->setK2(0);

//    SaveForce sfbs1{world.getWorldParticles()[0],bs1};
//    SaveForce sfbs2{world.getWorldParticles()[1],bs2};
    SaveForce grav1{world.getWorldParticles()[0],grav};
    SaveForce grav2{world.getWorldParticles()[1],grav};
    SaveForce drag1{world.getWorldParticles()[0],drag};
    SaveForce drag2{world.getWorldParticles()[1],grav};

//    registerForces.addRegister(sfbs1);
//    registerForces.addRegister(sfbs2);
    registerForces.addRegister(grav1);
    registerForces.addRegister(grav2);
    registerForces.addRegister(drag1);
    registerForces.addRegister(drag2);
}

const ParticleContactResolver &WorldPhysics::getContactResolver() const {
    return contactResolver;
}

void WorldPhysics::setContactResolver(const ParticleContactResolver &contactResolver) {
    WorldPhysics::contactResolver = contactResolver;
}

void WorldPhysics::erasePhysics() {
    contacts.clear();
    registerForces.clearRegister();
}
