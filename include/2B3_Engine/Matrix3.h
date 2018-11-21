//
// Created by totoa on 07/11/2018.
//

#ifndef GAMEENGINE_MATRIX3_H
#define GAMEENGINE_MATRIX3_H

class Vector3D;
class Quaternion;

#include "Vector3D.h"
#include "Quaternion.h"
#include <vector>

using namespace std;

///Classe Matrix3
class Matrix3 {

    ///Attributs
protected:
    vector<float> matrix;

    ///Méthodes
public:
    ///Constructeur - Destructeur
    Matrix3(vector<float> matrix);

    virtual ~Matrix3();

    ///Getter
    vector<float> getMatrix() const;

    ///Surcharge d'opérateurs
    Vector3D* operator*(Vector3D const &v);
    Matrix3* operator*(Matrix3 const &m);
    Matrix3* operator*(float const &coef);

    ///Méthode qui calcule le déterminant de la matrice
    float getDeterminant();

    ///Méthode d'inversion de la matrice
    Matrix3* invert();

    ///Méthode de transposition de la matrice
    Matrix3* transposition();

    ///Méthode de conversion d'un Quaternion en Matrix3
    Matrix3* setOrientation(Quaternion* q);


};

#endif //GAMEENGINE_MATRIX3_H
