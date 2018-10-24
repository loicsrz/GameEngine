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
///------------------------------------------------------------------------------------------------------------------

/// Génération de la physique de chacun des World de démonstration --------------------------------------------------
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

void WorldPhysics::initWorldPhysics2(World world) {
    ParticleForceGenerator* bs1 = new ParticleFloating();
    dynamic_cast<ParticleFloating*>(bs1)->setDepth(10.0f);
    dynamic_cast<ParticleFloating*>(bs1)->setLiquidDensity(1000.0f);
    dynamic_cast<ParticleFloating*>(bs1)->setVolume(0.012f);
    dynamic_cast<ParticleFloating*>(bs1)->setLiquidLevel(100.0f);


    ParticleForceGenerator* grav = new GravityGenerator();
    Vector3D * gravity = new Vector3D(0,-10.0f,0);
    dynamic_cast<GravityGenerator*>(grav)->setGravity(gravity);

    ParticleForceGenerator* drag = new DragGenerator();
    dynamic_cast<DragGenerator*>(drag)->setK1(1.5f);
    dynamic_cast<DragGenerator*>(drag)->setK2(0.04f);

    SaveForce sfbs1{world.getWorldParticles()[0],bs1};
    SaveForce grav1{world.getWorldParticles()[0],grav};
    SaveForce drag1{world.getWorldParticles()[0],drag};

    registerForces.addRegister(sfbs1);
    registerForces.addRegister(grav1);
    registerForces.addRegister(drag1);
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

}

void WorldPhysics::initWorldPhysics6(World world) {
    ParticleForceGenerator* ps1 = new ParticleSpring();
    dynamic_cast<ParticleSpring*>(ps1)->setK(0.01f);
    dynamic_cast<ParticleSpring*>(ps1)->setL0(16.0f);
    dynamic_cast<ParticleSpring*>(ps1)->setSecondParticle(world.getWorldParticles()[0]);

    ParticleForceGenerator* ps2 = new ParticleSpring();
    dynamic_cast<ParticleSpring*>(ps2)->setK(0.01f);
    dynamic_cast<ParticleSpring*>(ps2)->setL0(16.0f);
    dynamic_cast<ParticleSpring*>(ps2)->setSecondParticle(world.getWorldParticles()[0]);

    ParticleForceGenerator* bs3 = new BungeeSpring();
    dynamic_cast<BungeeSpring*>(bs3)->setK(0.01f);
    dynamic_cast<BungeeSpring*>(bs3)->setL0(16.0f);
    dynamic_cast<BungeeSpring*>(bs3)->setSecondParticle(world.getWorldParticles()[0]);

    ParticleForceGenerator* bs4 = new BungeeSpring();
    dynamic_cast<BungeeSpring*>(bs4)->setK(0.01f);
    dynamic_cast<BungeeSpring*>(bs4)->setL0(16.0f);
    dynamic_cast<BungeeSpring*>(bs4)->setSecondParticle(world.getWorldParticles()[0]);

    ParticleForceGenerator* gravP = new GravityGenerator();
    Vector3D * gravity = new Vector3D(0,-10.0f,0);
    dynamic_cast<GravityGenerator*>(gravP)->setGravity(gravity);

    ParticleForceGenerator* gravS = new GravityGenerator();
    gravity = new Vector3D(0,-0.001f,0);
    dynamic_cast<GravityGenerator*>(gravS)->setGravity(gravity);

    ParticleForceGenerator* drag = new DragGenerator();
    dynamic_cast<DragGenerator*>(drag)->setK1(0.05f);
    dynamic_cast<DragGenerator*>(drag)->setK2(0.04f);

    SaveForce sfps1{world.getWorldParticles()[1],ps1};
    SaveForce sfps2{world.getWorldParticles()[2],ps2};
    SaveForce sfbs3{world.getWorldParticles()[3],bs3};
    SaveForce sfbs4{world.getWorldParticles()[4],bs4};

    SaveForce grav1{world.getWorldParticles()[0],gravP};
    SaveForce grav2{world.getWorldParticles()[1],gravS};
    SaveForce grav3{world.getWorldParticles()[2],gravS};
    SaveForce grav4{world.getWorldParticles()[3],gravS};
    SaveForce grav5{world.getWorldParticles()[4],gravS};

    SaveForce drag1{world.getWorldParticles()[0],drag};
    SaveForce drag2{world.getWorldParticles()[1],drag};
    SaveForce drag3{world.getWorldParticles()[2],drag};
    SaveForce drag4{world.getWorldParticles()[3],drag};
    SaveForce drag5{world.getWorldParticles()[4],drag};

    registerForces.addRegister(sfps1);
    registerForces.addRegister(sfps2);
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
///------------------------------------------------------------------------------------------------------------------