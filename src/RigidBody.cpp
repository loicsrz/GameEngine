//
// Created by loicsrz on 14/11/2018.
//

#include "../include/2B3_Engine/RigidBody.h"

void RigidBody::CalculDerivedData() {

}

void RigidBody::addForceAtPoint(Vector3D Force, Vector3D position) {



}

void RigidBody::addForceAtBodyPoint(Vector3D Force, Vector3D position) {

}

void RigidBody::addForceAccumulator(Vector3D *force) {
    forcesAccum = this->forcesAccum->addVector(force);
}

void RigidBody::integrator(float time) {

}

void RigidBody::clearAccumulator() {
    this->forcesAccum->setX(0.0f);
    this->forcesAccum->setY(0.0f);
    this->forcesAccum->setZ(0.0f);

}

void RigidBody::addTorqueAccumulator(Vector3D *torque) {
    torqueAccum = this->torqueAccum->addVector(torque);

}
