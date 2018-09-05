//
// Created by Vince on 29/08/2018.
//

#include "../include/2B3_Engine/Particule.h"

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
// Fin de l'ensemble des getters et setters de la classe Particule.
