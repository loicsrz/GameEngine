//
// Created by loicsrz on 14/11/2018.
//

#include <cmath>
#include <iostream>
#include "../include/2B3_Engine/RigidBody.h"
#include "../include/2B3_Engine/Matrix4.h"

/// Début Constructeurs/Destructeur ---------------------------------------------------------------------------------
RigidBody::RigidBody(Particle *massCenter, Quaternion *orientation, Vector3D *rotation, Matrix4 *transformMatrix,
                     Matrix3 *inversedInertieTensor, float angularDamping, Vector3D *forcesAccum, Vector3D *torqueAccum)
        : massCenter(massCenter), orientation(orientation), rotation(rotation), transformMatrix(transformMatrix),
          inversedInertieTensor(inversedInertieTensor), angularDamping(angularDamping), forcesAccum(forcesAccum),
          torqueAccum(torqueAccum) {
    totalMass = 0.0f;
}

RigidBody::RigidBody(Particle *massCenter, Quaternion *orientation, Vector3D *rotation, Matrix4 *transformMatrix,
                     Matrix3 *inversedInertieTensor, float angularDamping, Vector3D *forcesAccum, Vector3D *torqueAccum,
                     const vector<Particle *> &bodyParticles) : massCenter(massCenter), orientation(orientation),
                                                                rotation(rotation), transformMatrix(transformMatrix),
                                                                inversedInertieTensor(inversedInertieTensor),
                                                                angularDamping(angularDamping),
                                                                forcesAccum(forcesAccum), torqueAccum(torqueAccum),
                                                                bodyParticles(bodyParticles) {
    updateTotalMass();
}

RigidBody::~RigidBody() {
    delete this->massCenter;
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

    updatedTransformMatrix->setValue(3, this->massCenter->getPosition()->getX());
    updatedTransformMatrix->setValue(7, this->massCenter->getPosition()->getY());
    updatedTransformMatrix->setValue(11, this->massCenter->getPosition()->getZ());

    this->transformMatrix = updatedTransformMatrix;
    // Inverted inertia update
    vector<float> rotationCoefs;
    for (int i = 0; i < 9; ++i) {
        rotationCoefs.push_back(0.0f);
    }
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
    updateTotalMass();
}

/// Méthode d'ajout de force à la force accumulé par le Corps Rigide
void RigidBody::addForceAccumulator(Vector3D *force) {
    forcesAccum = this->forcesAccum->addVector(force);
}

/// Méthode visant à calculer la position et la vélocité de la prochaine frame.
void RigidBody::integrator(float time) {
    Vector3D * acceleration = this->forcesAccum->scalarMultiplier(massCenter->getInvertedMass());
    Vector3D * derOrientation = inversedInertieTensor->operator*(*torqueAccum);
    rotation = rotation->scalarMultiplier(powf(angularDamping, time))->addVector(derOrientation->scalarMultiplier(time));
    UpdateSpeed(time, acceleration);
    UpdatePosition(time);
    orientation->UpdateAngularVelocity(rotation,time);
    calculDerivedData();
    updateVerticesPositions();
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

    massCenter->clearAccumulator();
    for(Particle* &particle : bodyParticles){
        particle->clearAccumulator();
    }

}

/// Méthode d'ajout de torque au torque accumulé par le Corps Rigide
void RigidBody::addTorqueAccumulator(Vector3D *torque) {
    torqueAccum = this->torqueAccum->addVector(torque);

}

/// Début de l'ensemble des getters et setters de la classe RigidBody ------------------------------------------------

Particle *RigidBody::getMassCenter(){
    return massCenter;
}

void RigidBody::setMassCenter(Particle *massCenter) {
    RigidBody::massCenter = massCenter;
}

vector<Particle *> &RigidBody::getBodyParticles() {
    return bodyParticles;
}

void RigidBody::setBodyParticles(vector<Particle *> &bodyParticles) {
    RigidBody::bodyParticles = bodyParticles;
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

Matrix4 *RigidBody::getTransformMatrix() {
    return transformMatrix;
}

void RigidBody::setTransformMatrix(Matrix4 *transformMatrix) {
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
    this->massCenter->setPosition(this->massCenter->getPosition()->addVector(this->massCenter->getVelocity()->scalarMultiplier(time)));
//    cout<<"mass center position before : "<<endl;
//    cout<<"position X : "<<massCenter->getPosition()->getX()<<endl;
//    cout<<"position Y : "<<massCenter->getPosition()->getY()<<endl;
//    cout<<"position Z : "<<massCenter->getPosition()->getZ()<<endl;
}

/// Méthode de mise à jour de la position du corps rigide.
void RigidBody::UpdateSpeed(float time, Vector3D *acceleration) {
    this->massCenter->setVelocity((this->massCenter->getVelocity()->scalarMultiplier(pow(this->massCenter->getDamping(), time)))
                                          ->addVector(acceleration->scalarMultiplier(time)));
}

void RigidBody::updateAllAccum() {
//    cout<<"forceAccum before : "<<endl;
//    cout<<"force X : "<<forcesAccum->getX()<<endl;
//    cout<<"force Y : "<<forcesAccum->getY()<<endl;
//    cout<<"force Z : "<<forcesAccum->getZ()<<endl;
//    cout<<"mass center : "<<endl;
//    cout<<"mass X : "<<massCenter->getForcesAccum()->getX()<<endl;
//    cout<<"mass Y : "<<massCenter->getForcesAccum()->getY()<<endl;
//    cout<<"mass Z : "<<massCenter->getForcesAccum()->getZ()<<endl;
    forcesAccum = forcesAccum->addVector(massCenter->getForcesAccum());
    for(Particle* &particle : bodyParticles){
        forcesAccum = forcesAccum->addVector(particle->getForcesAccum());
        if(particle->getPosition()->getNorm() != 0){
            torqueAccum = torqueAccum->addVector(particle->getPosition()->vectorialProduct(particle->getForcesAccum()));
        }

    }
}

float RigidBody::getTotalMass() const {
    return totalMass;
}

void RigidBody::setTotalMass(float invertedTotalMass) {
    RigidBody::totalMass = totalMass;
}

void RigidBody::updateTotalMass() {
    totalMass = 0.0f;
    for(Particle* &particle : bodyParticles){
        totalMass += particle->getMass();
    }
    totalMass += massCenter->getMass();
}

vector<Vector3D *> &RigidBody::getParticleObjectPositions() {
    return particleObjectPositions;
}

void RigidBody::setParticleObjectPositions( vector<Vector3D *> &particleObjectPositions) {
    RigidBody::particleObjectPositions = particleObjectPositions;
}

void RigidBody::updateVerticesPositions() {
    vector<Vector3D*>::iterator it = particleObjectPositions.begin();
    for(Particle* &particle : bodyParticles){
        particle->setPosition((*transformMatrix)*(**it));
        it++;
    }
    cout << "----------BODY PARTICLES-----------" << endl;
    for (Particle * &particle : bodyParticles) {
        particle->getPosition()->toString();
    }

    Vector3D * test = *(transformMatrix->invert())**(bodyParticles[0]->getPosition());
//    cout<<"v1 position : "<<endl;
//    cout<<"v1 X : "<<test->getX()<<endl;
//    cout<<"v1 Y : "<<test->getY()<<endl;
//    cout<<"v1 Z : "<<test->getZ()<<endl;
}
