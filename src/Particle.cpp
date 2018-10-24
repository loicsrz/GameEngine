//
// Created by Vince on 29/08/2018.
//

#include "../include/2B3_Engine/Particle.h"

/// Début Constructeurs/Destructeur ---------------------------------------------------------------------------------
Particle::Particle() {
    this->position = new Vector3D(0, 0, 2);
    this->velocity = new Vector3D(0, 1, 0);
    this->damping = 0.5f;
    this->invertedMass = 1;
    this->acceleration = new Vector3D(0, 0, 0);
    this->forcesAccum = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *velocity, float mass, float damping) : position(position),
                                                                                     velocity(velocity),
                                                                                     invertedMass(1 / mass),
                                                                                     damping(damping) {
    this->acceleration = new Vector3D(0, 0, 0);
    this->forcesAccum = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *velocity, float mass) : position(position),
                                                                      velocity(velocity),
                                                                      invertedMass(1 / mass) {
    this->damping = 0.7f;
    this->acceleration = new Vector3D(0, 0, 0);
    this->forcesAccum = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *velocity, Vector3D *acceleration, float mass,
                   float damping) : position(position), velocity(velocity), acceleration(acceleration),
                                    invertedMass(1 / mass), damping(damping) {
    this->forcesAccum = new Vector3D(0, 0, 0);
}


Particle::Particle(const Particle &particle) {
    this->acceleration = particle.acceleration;
    this->velocity = particle.velocity;
    this->position = particle.position;
    this->damping = particle.damping;
    this->invertedMass = particle.invertedMass;
    this->forcesAccum = new Vector3D(0, 0, 0);
}

Particle::~Particle() {
    delete this->position;
    delete this->velocity;
    delete this->acceleration;
    this->forcesAccum = new Vector3D(0, 0, 0);
}
/// Fin Constructeurs/Destructeur -----------------------------------------------------------------------------------

/// Méthode visant à calculer la position et la vélocité de la prochaine frame.
void Particle::integrator(float time) {
    //Lance consécutivement la m-a-j de la position de la particule puis la m-a-j de sa vélocité
    this->acceleration = this->forcesAccum->scalarMultiplier(invertedMass);
    UpdatePosition(time);
    UpdateSpeed(time);
}

/// Méthode d'ajout de force à la force accumulée par la Particle
void Particle::addForce(Vector3D * force) {
    forcesAccum = this->forcesAccum->addVector(force);
}

/// Methode de réinitialisation à 0 de la force accumulée par la Particle
void Particle::clearAccumulator() {
    this->forcesAccum->setX(0.0f);
    this->forcesAccum->setY(0.0f);
    this->forcesAccum->setZ(0.0f);
}

/// Début de l'ensemble des getters et setters de la classe Particle ------------------------------------------------
float Particle::getInvertedMass() const {
    return invertedMass;
}

void Particle::setInvertedMass(float invertedMass) {
    Particle::invertedMass = invertedMass;
}

float Particle::getMass() const {
    return 1 / invertedMass;
}

void Particle::setMass(float Mass) {
    Particle::invertedMass = 1 / Mass;
}

float Particle::getDamping() const {
    return damping;
}

void Particle::setDamping(float damping) {
    Particle::damping = damping;
}

Vector3D *Particle::getPosition() const {
    return position;
}

void Particle::setPosition(Vector3D *position) {
    Particle::position = position;
}

Vector3D *Particle::getVelocity() const {
    return velocity;
}

void Particle::setVelocity(Vector3D *velocity) {
    Particle::velocity = velocity;
}

Vector3D *Particle::getAcceleration() const {
    return acceleration;
}

void Particle::setAcceleration(Vector3D *acceleration) {
    Particle::acceleration = acceleration;
}

Vector3D *Particle::getForcesAccum() const {
    return forcesAccum;
}

void Particle::setForcesAccum(Vector3D *forcesAccum) {
    Particle::forcesAccum = forcesAccum;
}

float Particle::getRadius() const {
    return radius;
}

void Particle::setRadius(float radius) {
    Particle::radius = radius;
}
/// Fin de l'ensemble des getters et setters de la classe Particle ----------------------------------------------------

/// Méthode de mise à jour de la vélocité de la particule
void Particle::UpdatePosition(float time) {
    this->position = this->position->addVector(this->velocity->scalarMultiplier(time));
}

/// Méthode de mise à jour de la position de la particule
void Particle::UpdateSpeed(float time) {
    this->velocity = (this->velocity->scalarMultiplier(pow(this->damping, time)))
            ->addVector(this->acceleration->scalarMultiplier(time));
}






