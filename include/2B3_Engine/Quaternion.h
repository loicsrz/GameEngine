//
// Created by loicsrz on 07/11/2018.
//


#ifndef GAMEENGINE_QUATERNION_H
#define GAMEENGINE_QUATERNION_H

class Vector3D;
#include "Vector3D.h"

///Classe Quaternion
class Quaternion {

    ///Attributs
protected:
    float r;
    float i;
    float j;
    float k;

    ///Méthodes
public:

    ///Costructeurs - Destructeur
    Quaternion(float r, float i, float j, float k);

    ~Quaternion();

    ///Méthode de normalisation d'un quaternion
    void normalize();

    ///Méthode de conversion d'un vecteur en Quaternion
    void doRotation(Vector3D* v);

    ///Méthode de mise à jour de la vélocité angulaire
    void UpdateAngularVelocity(Vector3D* v, float duration);

    ///Surcharges d'opérateurs
    Quaternion* operator*(Quaternion const &b);

    Quaternion* operator*(float const &number);

    Quaternion* operator+(Quaternion const &quaternion);

    ///Getters - Setters
    float getR() const;

    void setR(float r);

    float getI() const;

    void setI(float i);

    float getJ() const;

    void setJ(float j);

    float getK() const;

    void setK(float k);

    ///Méthode d'affichage d'un quaternion
    void toString();
};


#endif //GAMEENGINE_QUATERNION_H
