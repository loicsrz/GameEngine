//
// Created by loicsrz on 14/11/2018.
//

#include "../include/2B3_Engine/RigidBody.h"

void RigidBody::CalculDerivedData() {

}

void RigidBody::addForceAtPoint(Vector3D * Force, Vector3D * position) {

    // TODO : convertir la position en coordonnées relatives au centre de masse
    forcesAccum = forcesAccum->addVector(Force);
    torqueAccum = torqueAccum->addVector(position->vectorialProduct(Force));


}

void RigidBody::addForceAtBodyPoint(Vector3D * Force, Vector3D * position) {

    // TODO : convertir la position en coordonnées relatives au repère du monde
    addForceAtPoint(Force, position);


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

float RigidBody::getInvertedMass() const {
    return invertedMass;
}

void RigidBody::setInvertedMass(float invertedMass) {
    RigidBody::invertedMass = invertedMass;
}

float RigidBody::getLinearDamping() const {
    return linearDamping;
}

void RigidBody::setLinearDamping(float linearDamping) {
    RigidBody::linearDamping = linearDamping;
}

Vector3D *RigidBody::getPosition() const {
    return position;
}

void RigidBody::setPosition(Vector3D *position) {
    RigidBody::position = position;
}

Vector3D *RigidBody::getVelocity() const {
    return velocity;
}

void RigidBody::setVelocity(Vector3D *velocity) {
    RigidBody::velocity = velocity;
}

float RigidBody::getAngularDamping() const {
    return angularDamping;
}

void RigidBody::setAngularDamping(float angularDamping) {
    RigidBody::angularDamping = angularDamping;
}

Vector3D *RigidBody::getForcesAccum() const {
    return forcesAccum;
}

void RigidBody::setForcesAccum(Vector3D *forcesAccum) {
    RigidBody::forcesAccum = forcesAccum;
}

Vector3D *RigidBody::getTorqueAccum() const {
    return torqueAccum;
}

void RigidBody::setTorqueAccum(Vector3D *torqueAccum) {
    RigidBody::torqueAccum = torqueAccum;
}

void RigidBody::setOrientation(Quaternion *orientation) {
    RigidBody::orientation = orientation;
}

void RigidBody::setRotation(Vector3D *rotation) {
    RigidBody::rotation = rotation;
}
