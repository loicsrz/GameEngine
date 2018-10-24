//
// Created by totoa on 19/09/2018.
//

#include <math.h>
#include "../include/2B3_Engine/DragGenerator.h"

///Constructeur par défaut
DragGenerator::DragGenerator() {}

///Destructeur
DragGenerator::~DragGenerator() {}

///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de type draging
void DragGenerator::UpdateForce(Particle *particle, float frame_duration) {
    float speed = particle->getVelocity()->getNorm();
    Vector3D* dragVector = particle->getVelocity();
    dragVector = dragVector->normalizeVector();
    dragVector = dragVector->scalarMultiplier(-1.0f);

    float drag = this->k1*speed + this->k2*pow(speed,2);
    dragVector = dragVector->scalarMultiplier(drag);
    particle->addForce(dragVector);
}

///Getters-Setters ----------------------------------------
float DragGenerator::getK1() const {
    return k1;
}

void DragGenerator::setK1(float k1) {
    DragGenerator::k1 = k1;
}

float DragGenerator::getK2() const {
    return k2;
}

void DragGenerator::setK2(float k2) {
    DragGenerator::k2 = k2;
}
///--------------------------------------------------------
