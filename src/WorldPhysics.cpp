//
// Created by totoa on 22/10/2018.
//

#include <iostream>
#include "../include/2B3_Engine/WorldPhysics.h"
#include "../include/2B3_Engine/Particle.h"
#include "../include/2B3_Engine/World.h"
#include "../include/2B3_Engine/BungeeSpring.h"
#include "../include/2B3_Engine/GravityGenerator.h"
#include "../include/2B3_Engine/DragGenerator.h"
#include "../include/2B3_Engine/ParticleAnchoredSpring.h"
#include "../include/2B3_Engine/ParticleStiffSpring.h"

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
    int currentIndex =0;
    for (iterator = world.getWorldParticles().begin(); iterator != world.getWorldParticles().end(); iterator++) {
        isLastValue = true;
        currentIndex = 0;
        for (separations = world.getGroundSeparations().begin();separations != world.getGroundSeparations().end(); separations++) {
            cout<<(*separations)<<endl;
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

void WorldPhysics::applyForces(float duration) {
    for(auto it = registerForces.m_register.begin();it != registerForces.m_register.end();it++){
//        cout << "Avant Application des forces : " << endl;
//        cout << "Forces Accum : " << endl;
//        cout << '\t' << "x : " << it->particle->getForcesAccum()->getX() << endl;
//        cout << '\t' << "y : " << it->particle->getForcesAccum()->getY() << endl;
//        cout << '\t' << "z : " << it->particle->getForcesAccum()->getZ() << endl;
//        cout << "Force à appliquer : " << endl;
//        ParticleForceGenerator* pointer = it->forceGenerator;
//        cout << '\t' << "x : " << dynamic_cast<GravityGenerator*>(pointer)->getGravity()->getX() << endl;
//        cout << '\t' << "y : " << dynamic_cast<GravityGenerator*>(pointer)->getGravity()->getY() << endl;
//        cout << '\t' << "z : " << dynamic_cast<GravityGenerator*>(pointer)->getGravity()->getZ() << endl;
//        cout << "Acceleration : " << endl;
//        cout << '\t' << "x : " << it->particle->getForcesAccum()->getX() << endl;
//        cout << '\t' << "y : " << it->particle->getForcesAccum()->getY() << endl;
//        cout << '\t' << "z : " << it->particle->getForcesAccum()->getZ() << endl;
        it->forceGenerator->UpdateForce(it->particle,duration);
//        cout << "Après Application des forces : " << endl;
//        cout << "ForceAccum : " << endl;
//        cout << '\t' << "x : " << it->particle->getForcesAccum()->getX() << endl;
//        cout << '\t' << "y : " << it->particle->getForcesAccum()->getY() << endl;
//        cout << '\t' << "z : " << it->particle->getForcesAccum()->getZ() << endl;
//        cout << "Velocite : " << endl;
//        cout << '\t' << "x : " << it->particle->getForcesAccum()->getX() << endl;
//        cout << '\t' << "y : " << it->particle->getForcesAccum()->getY() << endl;
//        cout << '\t' << "z : " << it->particle->getForcesAccum()->getZ() << endl;
//        cout << "Acceleration : " << endl;
//        cout << '\t' << "x : " << it->particle->getForcesAccum()->getX() << endl;
//        cout << '\t' << "y : " << it->particle->getForcesAccum()->getY() << endl;
//        cout << '\t' << "z : " << it->particle->getForcesAccum()->getZ() << endl;
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
    ParticleForceGenerator* bs1 = new BungeeSpring();
    dynamic_cast<BungeeSpring*>(bs1)->setK(0.01f);
    dynamic_cast<BungeeSpring*>(bs1)->setL0(70.0f);
    dynamic_cast<BungeeSpring*>(bs1)->setSecondParticle(world.getWorldParticles()[1]);

    ParticleForceGenerator* bs2 = new BungeeSpring();
    dynamic_cast<BungeeSpring*>(bs2)->setK(0.01f);
    dynamic_cast<BungeeSpring*>(bs2)->setL0(70.0f);
    dynamic_cast<BungeeSpring*>(bs2)->setSecondParticle(world.getWorldParticles()[0]);

    ParticleForceGenerator* grav = new GravityGenerator();
    Vector3D * gravity = new Vector3D(0,-10.0f,0);
    dynamic_cast<GravityGenerator*>(grav)->setGravity(gravity);

    ParticleForceGenerator* drag = new DragGenerator();
    dynamic_cast<DragGenerator*>(drag)->setK1(0.04f);
    dynamic_cast<DragGenerator*>(drag)->setK2(0);

    SaveForce sfbs1{world.getWorldParticles()[0],bs1};
    SaveForce sfbs2{world.getWorldParticles()[1],bs2};
    SaveForce grav1{world.getWorldParticles()[0],grav};
    SaveForce grav2{world.getWorldParticles()[1],grav};
    SaveForce drag1{world.getWorldParticles()[0],drag};
    SaveForce drag2{world.getWorldParticles()[1],drag};

    registerForces.addRegister(sfbs1);
    registerForces.addRegister(sfbs2);
    registerForces.addRegister(grav1);
    registerForces.addRegister(grav2);
    registerForces.addRegister(drag1);
    registerForces.addRegister(drag2);
}

void WorldPhysics::initWorldPhysics3(World world) {
    ParticleForceGenerator* aps = new ParticleAnchoredSpring();
    dynamic_cast<ParticleAnchoredSpring*>(aps)->setK(0.08f);
    dynamic_cast<ParticleAnchoredSpring*>(aps)->setL0(50.0f);
    dynamic_cast<ParticleAnchoredSpring*>(aps)->setAnchoredPoint(new Vector3D(250.0f,100.0f,0.0f));

    ParticleForceGenerator* grav = new GravityGenerator();
    Vector3D * gravity = new Vector3D(0,-10.0f,0);
    dynamic_cast<GravityGenerator*>(grav)->setGravity(gravity);

    ParticleForceGenerator* drag = new DragGenerator();
    dynamic_cast<DragGenerator*>(drag)->setK1(0.1f);
    dynamic_cast<DragGenerator*>(drag)->setK2(0.04f);

    SaveForce sfaps{world.getWorldParticles()[0],aps};
    SaveForce grav1{world.getWorldParticles()[0],grav};
    SaveForce drag1{world.getWorldParticles()[0],drag};

    registerForces.addRegister(sfaps);
    registerForces.addRegister(grav1);
    registerForces.addRegister(drag1);
}

void WorldPhysics::initWorldPhysics4(World world) {
    ParticleForceGenerator* ss1 = new ParticleStiffSpring();
    dynamic_cast<ParticleStiffSpring*>(ss1)->setK(0.20f);
    dynamic_cast<ParticleStiffSpring*>(ss1)->setDamping(0.8f);
    dynamic_cast<ParticleStiffSpring*>(ss1)->setAnchor(new Vector3D(250.0f,100.0f,0.0f));

    ParticleForceGenerator* grav = new GravityGenerator();
    Vector3D * gravity = new Vector3D(0,-10.0f,0);
    dynamic_cast<GravityGenerator*>(grav)->setGravity(gravity);

    ParticleForceGenerator* drag = new DragGenerator();
    dynamic_cast<DragGenerator*>(drag)->setK1(0.02f);
    dynamic_cast<DragGenerator*>(drag)->setK2(0.0f);

    SaveForce sfss1{world.getWorldParticles()[0],ss1};
    SaveForce grav1{world.getWorldParticles()[0],grav};
    SaveForce drag1{world.getWorldParticles()[0],drag};

    registerForces.addRegister(sfss1);
    registerForces.addRegister(grav1);
    registerForces.addRegister(drag1);
}

void WorldPhysics::initWorldPhysics5(World world) {
    ParticleForceGenerator* bs1 = new BungeeSpring();
    dynamic_cast<BungeeSpring*>(bs1)->setK(0.01f);
    dynamic_cast<BungeeSpring*>(bs1)->setL0(100.0f);
    dynamic_cast<BungeeSpring*>(bs1)->setSecondParticle(world.getWorldParticles()[2]);

    ParticleForceGenerator* bs2 = new BungeeSpring();
    dynamic_cast<BungeeSpring*>(bs2)->setK(0.01f);
    dynamic_cast<BungeeSpring*>(bs2)->setL0(100.0f);
    dynamic_cast<BungeeSpring*>(bs2)->setSecondParticle(world.getWorldParticles()[2]);

    ParticleForceGenerator* bs3 = new BungeeSpring();
    dynamic_cast<BungeeSpring*>(bs3)->setK(0.01f);
    dynamic_cast<BungeeSpring*>(bs3)->setL0(100.0f);
    dynamic_cast<BungeeSpring*>(bs3)->setSecondParticle(world.getWorldParticles()[2]);

    ParticleForceGenerator* bs4 = new BungeeSpring();
    dynamic_cast<BungeeSpring*>(bs4)->setK(0.01f);
    dynamic_cast<BungeeSpring*>(bs4)->setL0(100.0f);
    dynamic_cast<BungeeSpring*>(bs4)->setSecondParticle(world.getWorldParticles()[2]);

    ParticleForceGenerator* grav = new GravityGenerator();
    Vector3D * gravity = new Vector3D(0,-10.0f,0);
    dynamic_cast<GravityGenerator*>(grav)->setGravity(gravity);

    ParticleForceGenerator* drag = new DragGenerator();
    dynamic_cast<DragGenerator*>(drag)->setK1(0.02f);
    dynamic_cast<DragGenerator*>(drag)->setK2(0);

    SaveForce sfbs1{world.getWorldParticles()[0],bs1};
    SaveForce sfbs2{world.getWorldParticles()[1],bs2};
    SaveForce sfbs3{world.getWorldParticles()[3],bs3};
    SaveForce sfbs4{world.getWorldParticles()[4],bs4};

    SaveForce grav1{world.getWorldParticles()[0],grav};
    SaveForce grav2{world.getWorldParticles()[1],grav};
    SaveForce grav3{world.getWorldParticles()[2],grav};
    SaveForce grav4{world.getWorldParticles()[3],grav};
    SaveForce grav5{world.getWorldParticles()[4],grav};

    SaveForce drag1{world.getWorldParticles()[0],drag};
    SaveForce drag2{world.getWorldParticles()[1],drag};
    SaveForce drag3{world.getWorldParticles()[2],drag};
    SaveForce drag4{world.getWorldParticles()[3],drag};
    SaveForce drag5{world.getWorldParticles()[4],drag};

    registerForces.addRegister(sfbs1);
    registerForces.addRegister(sfbs2);
    registerForces.addRegister(sfbs3);
    registerForces.addRegister(sfbs4);

    registerForces.addRegister(grav1);
    registerForces.addRegister(grav2);
    registerForces.addRegister(grav3);
    registerForces.addRegister(grav4);
    registerForces.addRegister(grav5);

    registerForces.addRegister(drag1);
    registerForces.addRegister(drag2);
    registerForces.addRegister(drag3);
    registerForces.addRegister(drag4);
    registerForces.addRegister(drag5);
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