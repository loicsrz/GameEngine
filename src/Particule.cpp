//
// Created by Vince on 29/08/2018.
//

#include "../include/2B3_Engine/Particule.h"
#include "../include/2B3_Engine/Vecteur3D.h"

Particule::Particule() {
    this->position = new Vecteur3D(0,0,2);
    this->velocite = new Vecteur3D(0,1,1);
    this->damping = 0.7;
    this->inverseMasse = 1;
    this->acceleration = new Vecteur3D(0,0,0);
}

Particule::Particule(Vecteur3D* position, Vecteur3D* velocite, float Masse, float damping) : position(position), velocite(velocite),
                                                                    inverseMasse(1/Masse),damping(damping) {
    this->acceleration = new Vecteur3D(0,0,0);
}

// Méthode visant à calculer la position et la vitesse de la prochaine frame.
void Particule::integrer(float temps) {
    //TODO : Implémenter l'intégrateur (p(t) = p0 + dp/dt + (dv/dt x t²/2))
}

// Début de l'ensemble des getters et setters de la classe Particule.
float Particule::getInverseMasse() const {
    return inverseMasse;
}

void Particule::setInverseMasse(float inverseMasse) {
    Particule::inverseMasse = inverseMasse;
}

float Particule::getMasse() const {
    return 1/inverseMasse;
}

void Particule::setMasse(float Masse) {
    Particule::inverseMasse = 1/Masse;
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
