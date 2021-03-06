//
// Created by Vince on 29/08/2018.
//
#include "../include/2B3_Engine/Vector3D.h"
#include "Vector3D.h"
#include <cmath>

#ifndef GAMEENGINE_PARTICULE_H
#define GAMEENGINE_PARTICULE_H

/// Classe Particle
    /// Classe qui contient tous les éléments relatifs à une particule du monde
class Particle {

    ///Attributs
protected:
    // Position.
    Vector3D *position;
    // Vélocité.
    Vector3D *velocity;
    // Accélération.
    Vector3D *acceleration;
    //Inverse Masse
    float invertedMass;
    //Damping (forces de frottement)
    float damping;
    // radius
    float radius;

    Vector3D *forcesAccum;

public:
    /// Début Constructeurs/Destructeur
    Particle();

    Particle(Vector3D *position, Vector3D *velocity, float mass, float damping);

    Particle(Vector3D *position, Vector3D *velocity, float mass);

    Particle(Vector3D *position, Vector3D *velocity, Vector3D *acceleration, float mass, float damping);

    Particle(const Particle &particle);

    virtual ~Particle();

    /// Fin Constructeurs/Destructeur

    /// Méthode visant à calculer la position et la vitesse de la prochaine frame.
    void integrator(float time);

    /// Méthode d'ajout de force à la force accumulée par la Particle
    void addForce(Vector3D * force);

    /// Methode de réinitialisation à 0 de la force accumulée par la Particle
    void clearAccumulator();

    /// Début de l'ensemble des getters et setters de la classe Particule.
    float getInvertedMass() const;

    void setInvertedMass(float invertedMass);

    float getMass() const;

    void setMass(float Mass);

    void setPosition(Vector3D *position);

    void setVelocity(Vector3D *velocity);

    void setAcceleration(Vector3D *acceleration);

    float getDamping() const;

    void setDamping(float damping);

    Vector3D *getPosition() const;

    Vector3D *getVelocity() const;

    Vector3D *getAcceleration() const;

    Vector3D *getForcesAccum() const;

    void setForcesAccum(Vector3D *forcesAccum);

    float getRadius() const;

    void setRadius(float radius);

    /// Fin de l'ensemble des getters et setters de la classe Particle.

protected:
    /// Méthode de mise à jour de la vélocité de la particule
    void UpdateSpeed(float time);

    /// Méthode de mise à jour de la position de la particule
    void UpdatePosition(float time);

};


#endif //GAMEENGINE_PARTICULE_H