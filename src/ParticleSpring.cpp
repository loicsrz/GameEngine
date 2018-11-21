//
// Created by Vince on 26/09/2018.
//

#include "../include/2B3_Engine/ParticleSpring.h"

///Constructeur par défaut
ParticleSpring::ParticleSpring() {}

///Destructeur
ParticleSpring::~ParticleSpring() {}

///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de ressort classique
void ParticleSpring::UpdateForce(RigidBody * rigidBody, float frame_duration) {
    extremite1->setPosition(rigidBody->getTransformMatrix()->operator*(*(extremite1->getPosition())));
    extremite2->setPosition(rigidBody->getTransformMatrix()->operator*(*(extremite2->getPosition())));
    Vector3D * distance = extremite1->getPosition()->substractVector(extremite2->getPosition());
    float coeff = -K*(distance->getNorm()-l0);
    distance = distance->normalizeVector();
    rigidBody->addForceAtPoint(distance->scalarMultiplier(coeff),extremite1->getPosition());
}

///Getters - Setters -------------------------------------------------------------------------------------------------

float ParticleSpring::getK() const {
    return K;
}

float ParticleSpring::getL0() const {
    return l0;
}

void ParticleSpring::setK(float K) {
    ParticleSpring::K = K;
}

void ParticleSpring::setL0(float l0) {
    ParticleSpring::l0 = l0;
}

Particle *ParticleSpring::getExtremite1() const {
    return extremite1;
}

void ParticleSpring::setExtremite1(Particle *extremite1) {
    ParticleSpring::extremite1 = extremite1;
}

RigidBody *ParticleSpring::getAutreRigidBody() const {
    return AutreRigidBody;
}

void ParticleSpring::setAutreRigidBody(RigidBody *AutreRigidBody) {
    ParticleSpring::AutreRigidBody = AutreRigidBody;
}

Particle *ParticleSpring::getExtremite2() const {
    return extremite2;
}

void ParticleSpring::setExtremite2(Particle *extremite2) {
    ParticleSpring::extremite2 = extremite2;
}
///-------------------------------------------------------------------------------------------------------------------