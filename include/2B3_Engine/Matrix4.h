//
// Created by totoa on 13/11/2018.
//

#ifndef GAMEENGINE_MATRIX4_H
#define GAMEENGINE_MATRIX4_H


#include <iostream>
#include <vector>
#include "Vector3D.h"
#include "Quaternion.h"

///Classe Matrix4
class Matrix4 {

    ///Attributs
protected:
    vector<float> matrix;

    ///Méthodes
public:
    ///Constructeurs - Destructeurs
    Matrix4();

    Matrix4(vector<float> matrix);

    virtual ~Matrix4();

    ///Getter
    vector<float> getMatrix() const;

    ///Surcharges d'opérateurs
    Vector3D* operator*(Vector3D const &v);
    Matrix4* operator*(Matrix4 const &m);
    Matrix4* operator*(float const &coef);

    ///Méthode qui calcule le déterminant de la matrice
    float getDeterminant();

    ///Méthode d'inversion de la matrice
    Matrix4* invert();

    ///Méthode de conversion d'un quaternion en Matrix4
    Matrix4* setOrientation(Quaternion* q);

    ///Méthode de transformation d'un vecteur direction
    Vector3D* directionTransformRotation(Vector3D* direction);

    ///Méthode de transformation inverse d'un vecteur direction
    Vector3D* invertDirectionTransformRotation(Vector3D* direction);

    ///Méthode d'affichage d'une matrice
    void toString();

    ///Méthode de mise à jour d'une valeur de la matrice
    void setValue(int index, float value);
};


#endif //GAMEENGINE_MATRIX4_H
