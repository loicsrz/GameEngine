//
// Created by Vince on 29/08/2018.
//

#include "../include/2B3_Engine/Particule.h"
#include "../include/2B3_Engine/Vecteur3D.h"


Particule::Particule() {
    this->position = new Vecteur3D(0, 0, 2);
    this->velocite = new Vecteur3D(0, 1, 0);
    this->damping = 0.5f;
    this->inverseMasse = 1;
    this->acceleration = new Vecteur3D(0, 0, 0);
    this->forcesAccum = new Vecteur3D(0,0,0);
}

Particule::Particule(Vecteur3D *position, Vecteur3D *velocite, float masse, float damping) : position(position),
                                                                                             velocite(velocite),
                                                                                             inverseMasse(1 / masse),
                                                                                             damping(damping) {
    this->acceleration = new Vecteur3D(0, 0, 0);
    this->forcesAccum = new Vecteur3D(0,0,0);
}

Particule::Particule(Vecteur3D *position, Vecteur3D *velocite, float masse) : position(position),
                                                                              velocite(velocite),
                                                                              inverseMasse(1 / masse) {
    this->damping = 0.7f;
    this->acceleration = new Vecteur3D(0,0,0);
    this->forcesAccum = new Vecteur3D(0,0,0);
}

Particule::Particule(Vecteur3D *position, Vecteur3D *velocite, Vecteur3D *acceleration, float masse,
                     float damping) : position(position), velocite(velocite), acceleration(acceleration),
                                      inverseMasse(1 / masse), damping(damping) {
    this->forcesAccum = new Vecteur3D(0,0,0);
}


Particule::Particule(const Particule& particule){
    this->acceleration = particule.acceleration;
    this->velocite = particule.velocite;
    this->position = particule.position;
    this->damping = particule.damping;
    this->inverseMasse = particule.inverseMasse;
    this->forcesAccum = particule.forcesAccum;
}

Particule::~Particule() {
    delete this->position;
    delete this->velocite;
    delete this->acceleration;
    delete this->forcesAccum;
}

// Méthode visant à calculer la position et la vélocité de la prochaine frame.
void Particule::integrateur(float temps) {
    //Lance consécutivement la m-a-j de la position de la particule puis la m-a-j de sa vélocité
    UpdatePosition(temps);
    UpdateVelocite(temps);
}

void Particule::addForce(Vecteur3D * const force) {
    this->forcesAccum->AjoutVecteur(force);
}

void Particule::clearAccumulator(){
    this->forcesAccum->setX(0.0f);
    this->forcesAccum->setY(0.0f);
    this->forcesAccum->setZ(0.0f);
}

// Début de l'ensemble des getters et setters de la classe Particule.
float Particule::getInverseMasse() const {
    return inverseMasse;
}

void Particule::setInverseMasse(float inverseMasse) {
    Particule::inverseMasse = inverseMasse;
}

float Particule::getMasse() const {
    return 1 / inverseMasse;
}

void Particule::setMasse(float Masse) {
    Particule::inverseMasse = 1 / Masse;
}

float Particule::getDamping() const {
    return damping;
}

void Particule::setDamping(float damping) {
    Particule::damping = damping;
}

void Particule::setPosition(Vecteur3D *position) {
    Particule::position = position;
}

void Particule::setVelocite(Vecteur3D *velocite) {
    Particule::velocite = velocite;
}

void Particule::setAcceleration(Vecteur3D *acceleration) {
    Particule::acceleration = acceleration;
}

Vecteur3D *Particule::getPosition() const {
    return position;
}

Vecteur3D *Particule::getVelocite() const {
    return velocite;
}

Vecteur3D *Particule::getAcceleration() const {
    return acceleration;
}
// Fin de l'ensemble des getters et setters de la classe Particule.

void Particule::UpdatePosition(float temps) {
    this->position = this->position->AjoutVecteur(this->velocite->MultiplierScalaire(temps));
}

void Particule::UpdateVelocite(float temps) {
    this->velocite = (this->velocite->MultiplierScalaire(pow(this->damping, temps)))
            ->AjoutVecteur(this->acceleration->MultiplierScalaire(temps));
}




