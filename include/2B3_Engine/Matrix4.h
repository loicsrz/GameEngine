//
// Created by totoa on 13/11/2018.
//

#ifndef GAMEENGINE_MATRIX4_H
#define GAMEENGINE_MATRIX4_H


#include "Vector3D.h"
#include "Quaternion.h"

class Matrix4 {

protected:
    float * matrix;
public:
    Matrix4(float *matrix);

    virtual ~Matrix4();

    float *getMatrix() const;

    Vector3D* operator*(Vector3D const &v);
    Matrix4* operator*(Matrix4 const &m);
    Matrix4* operator*(float const &coef);

    float getDeterminant();

    Matrix4* invert();

    Matrix4* setOrientation(Quaternion* q);

    Matrix4* directionTransformRotation(Matrix4* otherBase);

    Matrix4* invertDirectionTransformRotation(Matrix4* otherBase);


};


#endif //GAMEENGINE_MATRIX4_H