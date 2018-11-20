//
// Created by loicsrz on 14/11/2018.
//

#include <cmath>
#include "../include/2B3_Engine/RigidBody.h"
#include "../include/2B3_Engine/Matrix4.h"

/// Début Constructeurs/Destructeur ---------------------------------------------------------------------------------
RigidBody::RigidBody(float invertedMass, float linearDamping, Vector3D *position, Vector3D *velocity,
                     Quaternion *orientation, Vector3D *rotation, Matrix4 *transformMatrix,
                     Matrix3 *inversedInertieTensor, float angularDamping, Vector3D *forcesAccum, Vector3D *torqueAccum)
        : invertedMass(invertedMass), linearDamping(linearDamping), position(position), velocity(velocity),
          orientation(orientation), rotation(rotation), transformMatrix(transformMatrix),
          inversedInertieTensor(inversedInertieTensor), angularDamping(angularDamping), forcesAccum(forcesAccum),
          torqueAccum(torqueAccum) {}

RigidBody::RigidBody(float invertedMass, float linearDamping, Vector3D *position, Vector3D *velocity, Quaternion *orientation,
                     Vector3D *rotation, float angularDamping, Vector3D *forcesAccum, Vector3D *torqueAccum,
                     Matrix4 *transformMatrix, Matrix3 *inversedInertieTensor, vector<Particle*> particles)
                     : invertedMass(invertedMass), linearDamping(linearDamping), position(position), velocity(velocity),
                     orientation(orientation), rotation(rotation), angularDamping(angularDamping), forcesAccum(forcesAccum)
                     , torqueAccum(torqueAccum), transformMatrix(transformMatrix), inversedInertieTensor(inversedInertieTensor),
                     bodyParticles(particles){

}

RigidBody::~RigidBody() {
    delete this->position;
    delete this->velocity;
    delete this->orientation;
    delete this->rotation;
    delete this->forcesAccum;
    delete this->torqueAccum;
    for(vector<Particle*>::iterator it = bodyParticles.begin(); it!= bodyParticles.end(); it++){
        delete *it;
    }
}

/// Fin Constructeurs/Destructeur ---------------------------------------------------------------------------------

/// Méthode de mise à jour de la matrice de transformation du bodySpace vers le worldSpace et de l'inverse de la matrice d'inertie du RigidBody
void RigidBody::calculDerivedData() {

    //Transform matrix update

    Matrix4 * updatedTransformMatrix = new Matrix4();
    updatedTransformMatrix = updatedTransformMatrix->setOrientation(this->orientation);

    updatedTransformMatrix->getMatrix()[3]=this->position->getX();
    updatedTransformMatrix->getMatrix()[7]=this->position->getY();
    updatedTransformMatrix->getMatrix()[11]=this->position->getZ();

    this->transformMatrix = updatedTransformMatrix;

    // Inverted inertia update
    float rotationCoefs[9];
    rotationCoefs[0] = updatedTransformMatrix->getMatrix()[0];
    rotationCoefs[1] = updatedTransformMatrix->getMatrix()[1];
    rotationCoefs[2] = updatedTransformMatrix->getMatrix()[2];
    rotationCoefs[3] = updatedTransformMatrix->getMatrix()[4];
    rotationCoefs[4] = updatedTransformMatrix->getMatrix()[5];
    rotationCoefs[5] = updatedTransformMatrix->getMatrix()[6];
    rotationCoefs[6] = updatedTransformMatrix->getMatrix()[8];
    rotationCoefs[7] = updatedTransformMatrix->getMatrix()[9];
    rotationCoefs[8] = updatedTransformMatrix->getMatrix()[10];

    Matrix3 * transformMatrixRotation = new Matrix3(rotationCoefs);

    inversedInertieTensor = transformMatrixRotation->operator*(*inversedInertieTensor);
    inversedInertieTensor = inversedInertieTensor->operator*(*transformMatrixRotation->invert());

}

/// Méthode visant à calculer les forces s'appliquant à un point (particule) du Corps Rigide
void RigidBody::addForceAtPoint(Vector3D * Force, Vector3D * position) {

    position = transformMatrix->invert()->operator*(*position);
    forcesAccum = forcesAccum->addVector(Force);
    torqueAccum = torqueAccum->addVector(position->vectorialProduct(Force));

}

void RigidBody::addForceAtBodyPoint(Vector3D * Force, Vector3D * position) {

    position = transformMatrix->operator*(*position);
    addForceAtPoint(Force, position);


}

void RigidBody::addParticleToBody(Particle *particle) {
    this->bodyParticles.push_back(particle);
}

/// Méthode d'ajout de force à la force accumulé par le Corps Rigide
void RigidBody::addForceAccumulator(Vector3D *force) {
    forcesAccum = this->forcesAccum->addVector(force);
}

/// Méthode visant à calculer la position et la vélocité de la prochaine frame.
void RigidBody::integrator(float time) {

    Vector3D * acceleration = this->forcesAccum->scalarMultiplier(invertedMass);
    Vector3D * derOrientation = inversedInertieTensor->operator*(*torqueAccum);
    rotation = rotation->scalarMultiplier(powf(angularDamping, time))->addVector(derOrientation->scalarMultiplier(time));
    UpdateSpeed(time, acceleration);
    UpdatePosition(time);
    orientation->UpdateAngularVelocity(rotation,time);
    calculDerivedData();
    clearAccumulator();
}

/// Methode de réinitialisation à 0 de la force accumulé et du torque accumulé par le Corps Rigide
void RigidBody::clearAccumulator() {
    this->forcesAccum->setX(0.0f);
    this->forcesAccum->setY(0.0f);
    this->forcesAccum->setZ(0.0f);

    this->torqueAccum->setX(0.0f);
    this->torqueAccum->setY(0.0f);
    this->torqueAccum->setZ(0.0f);

}

/// Méthode d'ajout de torque au torque accumulé par le Corps Rigide
void RigidBody::addTorqueAccumulator(Vector3D *torque) {
    torqueAccum = this->torqueAccum->addVector(torque);

}

/// Début de l'ensemble des getters et setters de la classe RigidBody ------------------------------------------------

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

Quaternion *RigidBody::getOrientation() const {
    return orientation;
}

Vector3D *RigidBody::getRotation() const {
    return rotation;
}

Matrix3 *RigidBody::getTransformMatrix() const {
    return transformMatrix;
}

void RigidBody::setTransformMatrix(Matrix3 *transformMatrix) {
    RigidBody::transformMatrix = transformMatrix;
}

Matrix3 *RigidBody::getInversedInertieTensor() const {
    return inversedInertieTensor;
}

void RigidBody::setInversedInertieTensor(Matrix3 *inversedInertieTensor) {
    RigidBody::inversedInertieTensor = inversedInertieTensor;
}

/// Fin de l'ensemble des getters et setters de la classe RigidBody ------------------------------------------------


/// Méthode de mise à jour de la vélocité du corps rigide.
void RigidBody::UpdatePosition(float time) {
    this->position = this->position->addVector(this->velocity->scalarMultiplier(time));
}

/// Méthode de mise à jour de la position du corps rigide.
void RigidBody::UpdateSpeed(float time, Vector3D *acceleration) {
    this->velocity = (this->velocity->scalarMultiplier(pow(this->linearDamping, time)))
            ->addVector(acceleration->scalarMultiplier(time));
}