//
// Created by Vince on 29/08/2018.
//

#include "Particule.h"

void Particule::integrer(float temps) {
    //TODO : Implémenter l'intégrateur (p(t) = p0 + dp/dt + (dv/dt x t²/2))
}

float Particule::getInverseMasse() const {
    return inverseMasse;
}

void Particule::setInverseMasse(float inverseMasse) {
    Particule::inverseMasse = inverseMasse;
}
