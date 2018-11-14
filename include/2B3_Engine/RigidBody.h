//
// Created by loicsrz on 14/11/2018.
//

#ifndef GAMEENGINE_RIGIDBODY_H
#define GAMEENGINE_RIGIDBODY_H


#include "Vector3D.h"
#include "Quaternion.h"

class RigidBody {

protected:
    //Inverse Masse
    float invertedMass;
    //Damping (forces de frottement)
    float linearDamping;
    // Position.
    Vector3D *position;
    // Vélocité.
    Vector3D *velocity;
    // Orientation
    Quaternion orientation;
    // Rotation
    Vector3D rotation;
    //
    //Matrix3 transformMatrix;
    //
    //Matrix3 inverseInertieTensor;

    float angularDamping;

    Vector3D *forcesAccum;

    Vector3D *torqueAccum;


public:

    void CalculDerivedData();

    void addForceAtPoint(Vector3D Force, Vector3D position);

    void addForceAtBodyPoint(Vector3D Force, Vector3D position);

    /// Méthode visant à calculer la position et la vitesse de la prochaine frame.
    void integrator(float time);

    /// Méthode d'ajout de force à la force accumulée par la Particle
    void addForceAccumulator(Vector3D * force);

    void addTorqueAccumulator(Vector3D * torque);

    /// Methode de réinitialisation à 0 de la force accumulée par la Particle
    void clearAccumulator();
};


#endif //GAMEENGINE_RIGIDBODY_H
