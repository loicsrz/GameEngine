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
    Quaternion *orientation;
    // Rotation
    Vector3D *rotation;
    //
    //Matrix3 transformMatrix;
    //
    //
    // Matrix3 inversedInertieTensor
    float angularDamping;

    Vector3D *forcesAccum;

    Vector3D *torqueAccum;
public:

    /// Début Constructeur/Destructeur
    RigidBody(float invertedMass, float linearDamping, Vector3D *position, Vector3D *velocity, Quaternion *orientation,
            Vector3D *rotation, float angularDamping, Vector3D *forcesAccum, Vector3D *torqueAccum);

    ~RigidBody();

    /// Fin Constructeur/Destructeur

    void CalculDerivedData();

    /// Méthode visant à calculer les forces s'appliquant à un point (particule) du Corps Rigide.
    void addForceAtPoint(Vector3D* Force, Vector3D* position);

    void addForceAtBodyPoint(Vector3D* Force, Vector3D* position);

    /// Méthode visant à calculer la position et la vitesse de la prochaine frame.
    void integrator(float time);

    /// Méthode d'ajout de force à la force accumulé par le Corps Rigide
    void addForceAccumulator(Vector3D * force);

    /// Méthode d'ajout de torque au torque accumulé par le Corps Rigide
    void addTorqueAccumulator(Vector3D * torque);

    /// Methode de réinitialisation à 0 de la force accumulé et du torque accumulé par le Corps Rigide
    void clearAccumulator();


    /// Début de l'ensemble des getters et setters de la classe Corps Rigide.
    void setOrientation(Quaternion *orientation);

    void setRotation(Vector3D *rotation);

    float getInvertedMass() const;

    void setInvertedMass(float invertedMass);

    float getLinearDamping() const;

    void setLinearDamping(float linearDamping);

    Vector3D *getPosition() const;

    void setPosition(Vector3D *position);

    Vector3D *getVelocity() const;

    void setVelocity(Vector3D *velocity);

    float getAngularDamping() const;

    void setAngularDamping(float angularDamping);

    Vector3D *getForcesAccum() const;

    void setForcesAccum(Vector3D *forcesAccum);

    Vector3D *getTorqueAccum() const;

    void setTorqueAccum(Vector3D *torqueAccum);

    /// Fin de l'ensemble des getters et setters de la classe Corps Rigide.

protected:

    /// Méthode de mise à jour de la vélocité du Corps Rigide
    void UpdateSpeed(float time, Vector3D *acceleration);

    /// Méthode de mise à jour de la position du Corps Rigide
    void UpdatePosition(float time);


};


#endif //GAMEENGINE_RIGIDBODY_H
