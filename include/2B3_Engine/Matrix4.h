//
// Created by totoa on 13/11/2018.
//

#ifndef GAMEENGINE_MATRIX4_H
#define GAMEENGINE_MATRIX4_H


#include <iostream>
#include <vector>
#include "Vector3D.h"
#include "Quaternion.h"

class Matrix4 {

protected:
    vector<float> matrix;
public:
    Matrix4();

    Matrix4(vector<float> matrix);

    virtual ~Matrix4();

    vector<float> getMatrix() const;

    Vector3D* operator*(Vector3D const &v);
    Matrix4* operator*(Matrix4 const &m);
    Matrix4* operator*(float const &coef);

    float getDeterminant();

    Matrix4* invert();

    Matrix4* setOrientation(Quaternion* q);

    Vector3D* directionTransformRotation(Vector3D* direction);

    Vector3D* invertDirectionTransformRotation(Vector3D* direction);

    void toString();

    void setValue(int index, float value);
};


#endif //GAMEENGINE_MATRIX4_H
