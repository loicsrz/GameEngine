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

class Matrix3 {

protected:
    vector<float> matrix;

public:
    Matrix3(vector<float> matrix);

    virtual ~Matrix3();

    vector<float> getMatrix() const;

    Vector3D* operator*(Vector3D const &v);
    Matrix3* operator*(Matrix3 const &m);
    Matrix3* operator*(float const &coef);

    float getDeterminant();

    Matrix3* invert();

    Matrix3* transposition();

    Matrix3* setOrientation(Quaternion* q);


};

#endif //GAMEENGINE_MATRIX3_H
