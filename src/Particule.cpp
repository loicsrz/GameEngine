//
// Created by Vince on 29/08/2018.
//

#include "../include/2B3_Engine/Particule.h"

Particule::Particule(float position, float velocite, float Masse) : position(position), velocite(velocite),
                                                                    inverseMasse(1/Masse) {}

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
// Fin de l'ensemble des getters et setters de la classe Particule.
