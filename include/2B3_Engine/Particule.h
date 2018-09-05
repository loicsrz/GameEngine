//
// Created by Vince on 29/08/2018.
//
#include "../include/2B3_Engine/Vecteur3D.h"
#include "Vecteur3D.h"
#include <cmath>

#ifndef GAMEENGINE_PARTICULE_H
#define GAMEENGINE_PARTICULE_H


class Particule {
public:
    Particule();

    Particule(Vecteur3D* position, Vecteur3D* velocite, float masse, float damping);

    Particule(Vecteur3D *position, Vecteur3D *velocite, Vecteur3D *acceleration, float masse, float damping);

    virtual ~Particule();

protected:
    // Position.
    Vecteur3D* position;
    // Vélocité.
    Vecteur3D* velocite;
    // Accélération.
    Vecteur3D* acceleration;
    //Inverse Masse
    float inverseMasse;
    //Damping (forces de frottement)
    float damping;

public:
    // Méthode visant à calculer la position et la vitesse de la prochaine frame.
    void integrateur (float temps);

    // Début de l'ensemble des getters et setters de la classe Particule.
    float getInverseMasse() const;

    void setInverseMasse(float inverseMasse);

    float getMasse() const;

    void setMasse(float Masse);

    void setPosition(Vecteur3D *position);

    void setVelocite(Vecteur3D *velocite);

    void setAcceleration(Vecteur3D *acceleration);

    float getDamping() const;

    void setDamping(float damping);

    Vecteur3D *getPosition() const;

    Vecteur3D *getVelocite() const;

    Vecteur3D *getAcceleration() const;
    // Fin de l'ensemble des getters et setters de la classe Particule.

protected:
    void UpdateVelocite(float temps);

    void UpdatePosition(float temps);

};


#endif //GAMEENGINE_PARTICULE_H