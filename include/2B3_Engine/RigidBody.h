//
// Created by loicsrz on 14/11/2018.
//

#ifndef GAMEENGINE_RIGIDBODY_H
#define GAMEENGINE_RIGIDBODY_H


#include "Vector3D.h"
#include "Quaternion.h"
#include "Matrix4.h"
#include "Particle.h"
#include <vector>

class RigidBody {

protected:

    // Centre de masse
    Particle * massCenter;
    //Masse totale du rigidBody
    float totalMass;
    // Orientation
    Quaternion *orientation;
    // Rotation
    Vector3D *rotation;
    //
    Matrix4 *transformMatrix;
    //
    Matrix3 *inversedInertieTensor;

    float angularDamping;

    Vector3D *forcesAccum;

    Vector3D *torqueAccum;

    vector<Particle*> bodyParticles;

    vector<Vector3D*> particleObjectPositions;
public:

    /// Début Constructeur/Destructeur
    RigidBody(Particle *massCenter, Quaternion *orientation, Vector3D *rotation, Matrix4 *transformMatrix,
              Matrix3 *inversedInertieTensor, float angularDamping, Vector3D *forcesAccum, Vector3D *torqueAccum);

    RigidBody(Particle *massCenter, Quaternion *orientation, Vector3D *rotation, Matrix4 *transformMatrix,
              Matrix3 *inversedInertieTensor, float angularDamping, Vector3D *forcesAccum, Vector3D *torqueAccum,
              const vector<Particle *> &bodyParticles);

    ~RigidBody();

    /// Fin Constructeur/Destructeur

    void calculDerivedData();

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

    /// Méthode qui ajoute une particule au rigidBody
    void addParticleToBody(Particle * particle);

    ///Méthode qui ajoute les forceAccum des particules du rigidBody au forceAccum du RigidBody
    void updateAllAccum();

    void updateTotalMass();

    void updateVerticesPositions();

    /// Début de l'ensemble des getters et setters de la classe Corps Rigide.
    Particle *getMassCenter();

    void setMassCenter(Particle *massCenter);

    vector<Particle *> &getBodyParticles();

    void setBodyParticles(vector<Particle *> &bodyParticles);

    void setOrientation(Quaternion *orientation);

    void setRotation(Vector3D *rotation);

    float getAngularDamping() const;

    void setAngularDamping(float angularDamping);

    Vector3D *getForcesAccum() const;

    void setForcesAccum(Vector3D *forcesAccum);

    Matrix4 *getTransformMatrix();

    void setTransformMatrix(Matrix4 *transformMatrix);

    Matrix3 *getInversedInertieTensor() const;

    void setInversedInertieTensor(Matrix3 *inversedInertieTensor);

    Vector3D *getTorqueAccum() const;

    void setTorqueAccum(Vector3D *torqueAccum);

    Quaternion *getOrientation() const;

    Vector3D *getRotation() const;

    float getTotalMass() const;

    void setTotalMass(float invertedTotalMass);

    vector<Vector3D *> &getParticleObjectPositions();

    void setParticleObjectPositions( vector<Vector3D *> &particleObjectPositions);

    /// Fin de l'ensemble des getters et setters de la classe Corps Rigide.

protected:

    /// Méthode de mise à jour de la vélocité du Corps Rigide
    void UpdateSpeed(float time, Vector3D *acceleration);

    /// Méthode de mise à jour de la position du Corps Rigide
    void UpdatePosition(float time);


};


#endif //GAMEENGINE_RIGIDBODY_H
