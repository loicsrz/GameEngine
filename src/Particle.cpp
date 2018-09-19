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
}

Particle::Particle(Vector3D *position, Vector3D *speed, float mass, float damping) : position(position),
                                                                                     speed(speed),
                                                                                     invertedMass(1 / mass),
                                                                                     damping(damping) {
    this->acceleration = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *speed, float mass) : position(position),
                                                                      speed(speed),
                                                                      invertedMass(1 / mass) {
    this->damping = 0.7f;
    this->acceleration = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *speed, Vector3D *acceleration, float mass,
                   float damping) : position(position), speed(speed), acceleration(acceleration),
                                    invertedMass(1 / mass), damping(damping) {}


Particle::Particle(const Particle &particle) {
    this->acceleration = particle.acceleration;
    this->speed = particle.speed;
    this->position = particle.position;
    this->damping = particle.damping;
    this->invertedMass = particle.invertedMass;
}

Particle::~Particle() {
    delete this->position;
    delete this->speed;
    delete this->acceleration;
}

// Méthode visant à calculer la position et la vélocité de la prochaine frame.
void Particle::integrator(float time) {
    //Lance consécutivement la m-a-j de la position de la particule puis la m-a-j de sa vélocité
    UpdatePosition(time);
    UpdateSpeed(time);
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

void Particle::setPosition(Vector3D *position) {
    Particle::position = position;
}

void Particle::setSpeed(Vector3D *speed) {
    Particle::speed = speed;
}

void Particle::setAcceleration(Vector3D *acceleration) {
    Particle::acceleration = acceleration;
}

Vector3D *Particle::getPosition() const {
    return position;
}

Vector3D *Particle::getSpeed() const {
    return speed;
}

Vector3D *Particle::getAcceleration() const {
    return acceleration;
}
// Fin de l'ensemble des getters et setters de la classe Particle.

void Particle::UpdatePosition(float time) {
    this->position = this->position->addVector(this->speed->scalarMultiplier(time));
}

void Particle::UpdateSpeed(float time) {
    this->speed = (this->speed->scalarMultiplier(pow(this->damping, time)))
            ->addVector(this->acceleration->scalarMultiplier(time));
}




