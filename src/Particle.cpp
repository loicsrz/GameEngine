//
// Created by Vince on 29/08/2018.
//

#include "../include/2B3_Engine/Particle.h"
#include "../include/2B3_Engine/Vector3D.h"


Particle::Particle() {
    this->position = new Vector3D(0, 0, 2);
    this->velocite = new Vector3D(0, 1, 0);
    this->damping = 0.5f;
    this->inverseMasse = 1;
    this->acceleration = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *velocite, float masse, float damping) : position(position),
                                                                                             velocite(velocite),
                                                                                             inverseMasse(1 / masse),
                                                                                             damping(damping) {
    this->acceleration = new Vector3D(0, 0, 0);
}

Particle::Particle(Vector3D *position, Vector3D *velocite, float masse) : position(position),
                                                                              velocite(velocite),
                                                                              inverseMasse(1 / masse) {
    this->damping = 0.7f;
    this->acceleration = new Vector3D(0,0,0);
}

Particle::Particle(Vector3D *position, Vector3D *velocite, Vector3D *acceleration, float masse,
                     float damping) : position(position), velocite(velocite), acceleration(acceleration),
                                      inverseMasse(1 / masse), damping(damping) {}


Particle::Particle(const Particle& particule){
    this->acceleration = particule.acceleration;
    this->velocite = particule.velocite;
    this->position = particule.position;
    this->damping = particule.damping;
    this->inverseMasse = particule.inverseMasse;
}

Particle::~Particle() {
    delete this->position;
    delete this->velocite;
    delete this->acceleration;
}

// Méthode visant à calculer la position et la vélocité de la prochaine frame.
void Particle::integrateur(float temps) {
    //Lance consécutivement la m-a-j de la position de la particule puis la m-a-j de sa vélocité
    UpdatePosition(temps);
    UpdateVelocite(temps);
}

// Début de l'ensemble des getters et setters de la classe Particle.
float Particle::getInverseMasse() const {
    return inverseMasse;
}

void Particle::setInverseMasse(float inverseMasse) {
    Particle::inverseMasse = inverseMasse;
}

float Particle::getMasse() const {
    return 1 / inverseMasse;
}

void Particle::setMasse(float Masse) {
    Particle::inverseMasse = 1 / Masse;
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

void Particle::setVelocite(Vector3D *velocite) {
    Particle::velocite = velocite;
}

void Particle::setAcceleration(Vector3D *acceleration) {
    Particle::acceleration = acceleration;
}

Vector3D *Particle::getPosition() const {
    return position;
}

Vector3D *Particle::getVelocite() const {
    return velocite;
}

Vector3D *Particle::getAcceleration() const {
    return acceleration;
}
// Fin de l'ensemble des getters et setters de la classe Particle.

void Particle::UpdatePosition(float temps) {
    this->position = this->position->AjoutVecteur(this->velocite->MultiplierScalaire(temps));
}

void Particle::UpdateVelocite(float temps) {
    this->velocite = (this->velocite->MultiplierScalaire(pow(this->damping, temps)))
            ->AjoutVecteur(this->acceleration->MultiplierScalaire(temps));
}




