//
// Created by Vince on 20/09/2018.
//

#include "../include/2B3_Engine/GravityGenerator.h"

///Constructeur par défaut
GravityGenerator::GravityGenerator() {

}

///Destructeur
GravityGenerator::~GravityGenerator() {

}

///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de gravité
void GravityGenerator::UpdateForce(Particle *particle, float frame_duration) {
    if(particle->getMass()==0) return;
    particle->addForce(gravity->scalarMultiplier(particle->getMass()));
}

///Getters-Setters ----------------------------------------------
Vector3D *GravityGenerator::getGravity() const {
    return gravity;
}

void GravityGenerator::setGravity(Vector3D *gravity) {
    GravityGenerator::gravity = gravity;
}
///---------------------------------------------------------------

