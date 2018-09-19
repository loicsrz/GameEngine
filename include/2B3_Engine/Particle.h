//
// Created by Vince on 29/08/2018.
//
#include "../include/2B3_Engine/Vector3D.h"
#include "Vector3D.h"
#include <cmath>

#ifndef GAMEENGINE_PARTICULE_H
#define GAMEENGINE_PARTICULE_H


class Particle {

    ///Attributs
protected:
    // Position.
    Vector3D* position;
    // Vélocité.
    Vector3D* velocite;
    // Accélération.
    Vector3D* acceleration;
    //Inverse Masse
    float inverseMasse;
    //Damping (forces de frottement)
    float damping;

public:
    /// Début Constructeurs/Destructeur
    Particle();

    Particle(Vector3D* position, Vector3D* velocite, float masse, float damping);

    Particle(Vector3D* position, Vector3D* velocite, float masse);

    Particle(Vector3D *position, Vector3D *velocite, Vector3D *acceleration, float masse, float damping);

    Particle(const Particle& particule);

    virtual ~Particle();

    /// Fin Constructeurs/Destructeur

    // Méthode visant à calculer la position et la vitesse de la prochaine frame.
    void integrateur (float temps);

    /// Début de l'ensemble des getters et setters de la classe Particule.
    float getInverseMasse() const;

    void setInverseMasse(float inverseMasse);

    float getMasse() const;

    void setMasse(float Masse);

    void setPosition(Vector3D *position);

    void setVelocite(Vector3D *velocite);

    void setAcceleration(Vector3D *acceleration);

    float getDamping() const;

    void setDamping(float damping);

    Vector3D *getPosition() const;

    Vector3D *getVelocite() const;

    Vector3D *getAcceleration() const;
    // Fin de l'ensemble des getters et setters de la classe Particle.

protected:
    // Méthode de mise à jour de la vélocité de la particule
    void UpdateVelocite(float temps);

    // Méthode de mise à jour de la position de la particule
    void UpdatePosition(float temps);

};


#endif //GAMEENGINE_PARTICULE_H