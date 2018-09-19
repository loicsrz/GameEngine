//
// Created by Vince on 29/08/2018.
//

#include "../include/2B3_Engine/Particle.h"

Particle::Particle() {
    this->position = new Vector3D(0, 0, 2);
    this->speed = new Vector3D(0, 1, 0);
    this->damping = 0.5f;
    this->invertedMass = 1;
    this->acceleration = new Vector3D(0, 0, 0);
    this->forcesAccum = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *speed, float mass, float damping) : position(position),
                                                                                     speed(speed),
                                                                                     invertedMass(1 / mass),
                                                                                     damping(damping) {
    this->acceleration = new Vector3D(0, 0, 0);
    this->forcesAccum = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *speed, float mass) : position(position),
                                                                      speed(speed),
                                                                      invertedMass(1 / mass) {
    this->damping = 0.7f;
    this->acceleration = new Vector3D(0, 0, 0);
    this->forcesAccum = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *speed, Vector3D *acceleration, float mass,
                   float damping) : position(position), speed(speed), acceleration(acceleration),
                                    invertedMass(1 / mass), damping(damping) {
    this->forcesAccum = new Vector3D(0, 0, 0);
}


Particle::Particle(const Particle &particle) {
    this->acceleration = particle.acceleration;
    this->speed = particle.speed;
    this->position = particle.position;
    this->damping = particle.damping;
    this->invertedMass = particle.invertedMass;
    this->forcesAccum = new Vector3D(0, 0, 0);
}

Particle::~Particle() {
    delete this->position;
    delete this->speed;
    delete this->acceleration;
    this->forcesAccum = new Vector3D(0, 0, 0);
}

// Méthode visant à calculer la position et la vélocité de la prochaine frame.
void Particle::integrator(float time) {
    //Lance consécutivement la m-a-j de la position de la particule puis la m-a-j de sa vélocité
    UpdatePosition(time);
    UpdateSpeed(time);
}

void Particle::addForce(Vector3D *const force) {
    this->forcesAccum->addVector(force);
}

void Particle::clearAccumulator() {
    this->forcesAccum->setX(0.0f);
    this->forcesAccum->setY(0.0f);
    this->forcesAccum->setZ(0.0f);
}

// Début de l'ensemble des getters et setters de la classe Particle.
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

Vector3D *Particle::getSpeed() const {
    return speed;
}

void Particle::setSpeed(Vector3D *speed) {
    Particle::speed = speed;
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
// Fin de l'ensemble des getters et setters de la classe Particle.

void Particle::UpdatePosition(float time) {
    this->position = this->position->addVector(this->speed->scalarMultiplier(time));
}

void Particle::UpdateSpeed(float time) {
    this->speed = (this->speed->scalarMultiplier(pow(this->damping, time)))
            ->addVector(this->acceleration->scalarMultiplier(time));
}




