//
// Created by totoa on 13/11/2018.
//

#include <cmath>
#include "../include/2B3_Engine/Matrix4.h"

Matrix4::Matrix4() {}

Matrix4::Matrix4(float *matrix) : matrix(matrix) {}

Matrix4::~Matrix4() {
    delete this->matrix;
}

float *Matrix4::getMatrix() const {
    return matrix;
}

Vector3D *Matrix4::operator*(Vector3D const &v) {
    float x = this->matrix[0]*v.getX()+this->matrix[1]*v.getY()+this->matrix[2]*v.getZ()+this->matrix[3];
    float y = this->matrix[4]*v.getX()+this->matrix[5]*v.getY()+this->matrix[6]*v.getZ()+this->matrix[7];
    float z = this->matrix[8]*v.getX()+this->matrix[9]*v.getY()+this->matrix[10]*v.getZ()+this->matrix[11];
    return new Vector3D(x,y,z);
}

Matrix4 *Matrix4::operator*(Matrix4 const &m) {
    float resultCoefs[12];
    float * mCoefs = m.getMatrix();
    resultCoefs[0] = this->matrix[0]*mCoefs[0]+this->matrix[1]*mCoefs[4]+this->matrix[2]*mCoefs[8];
    resultCoefs[1] = this->matrix[0]*mCoefs[1]+this->matrix[1]*mCoefs[5]+this->matrix[2]*mCoefs[9];
    resultCoefs[2] = this->matrix[0]*mCoefs[2]+this->matrix[1]*mCoefs[6]+this->matrix[2]*mCoefs[10];
    resultCoefs[3] = this->matrix[0]*mCoefs[3]+this->matrix[1]*mCoefs[7]+this->matrix[2]*mCoefs[11]+this->matrix[3];
    resultCoefs[4] = this->matrix[4]*mCoefs[0]+this->matrix[5]*mCoefs[4]+this->matrix[6]*mCoefs[8];
    resultCoefs[5] = this->matrix[4]*mCoefs[1]+this->matrix[5]*mCoefs[5]+this->matrix[6]*mCoefs[9];
    resultCoefs[6] = this->matrix[4]*mCoefs[2]+this->matrix[5]*mCoefs[6]+this->matrix[6]*mCoefs[10];
    resultCoefs[7] = this->matrix[4]*mCoefs[3]+this->matrix[5]*mCoefs[7]+this->matrix[6]*mCoefs[11]+this->matrix[7];
    resultCoefs[8] = this->matrix[8]*mCoefs[0]+this->matrix[9]*mCoefs[4]+this->matrix[10]*mCoefs[8];
    resultCoefs[9] = this->matrix[8]*mCoefs[1]+this->matrix[9]*mCoefs[5]+this->matrix[10]*mCoefs[9];
    resultCoefs[10] = this->matrix[8]*mCoefs[2]+this->matrix[9]*mCoefs[6]+this->matrix[10]*mCoefs[10];
    resultCoefs[11] = this->matrix[8]*mCoefs[3]+this->matrix[9]*mCoefs[7]+this->matrix[10]*mCoefs[11]+this->matrix[11];
    return new Matrix4(mCoefs);
}

Matrix4 *Matrix4::operator*(float const &coef) {
    float mCoefs[12];
    mCoefs[0] = this->matrix[0]*coef;
    mCoefs[1] = this->matrix[1]*coef;
    mCoefs[2] = this->matrix[2]*coef;
    mCoefs[3] = this->matrix[3]*coef;
    mCoefs[4] = this->matrix[4]*coef;
    mCoefs[5] = this->matrix[5]*coef;
    mCoefs[6] = this->matrix[6]*coef;
    mCoefs[7] = this->matrix[7]*coef;
    mCoefs[8] = this->matrix[8]*coef;
    mCoefs[9] = this->matrix[9]*coef;
    mCoefs[10] = this->matrix[10]*coef;
    mCoefs[11] = this->matrix[11]*coef;
    return new Matrix4(mCoefs);
}

Matrix4 *Matrix4::setOrientation(Quaternion *q) {
    float quatMatCoefs[12];
    quatMatCoefs[0] = 1 - (2*powf(q->getJ(),2.0f)+2*powf(q->getK(),2.0f));
    quatMatCoefs[1] = 2*q->getI()*q->getJ()+2*q->getK()*q->getR();
    quatMatCoefs[2] = 2*q->getI()*q->getK()-2*q->getJ()*q->getR();
    quatMatCoefs[3] = q->getI();
    quatMatCoefs[4] = 2*q->getI()*q->getJ()-2*q->getK()*q->getR();
    quatMatCoefs[5] = 1 - (2*powf(q->getI(),2.0f)+2*powf(q->getK(),2.0f));
    quatMatCoefs[6] = 2*q->getJ()*q->getK()+2*q->getI()*q->getR();
    quatMatCoefs[7] = q->getJ();
    quatMatCoefs[8] = 2*q->getI()*q->getK()+2*q->getJ()*q->getR();
    quatMatCoefs[9] = 2*q->getJ()*q->getK()-2*q->getI()*q->getR();
    quatMatCoefs[10] = 1 - (2*powf(q->getI(),2.0f)+2*powf(q->getJ(),2.0f));
    quatMatCoefs[11] = q->getK();
    return new Matrix4(quatMatCoefs);
}

float Matrix4::getDeterminant() {
    return
    this->matrix[8]*this->matrix[5]*this->matrix[2]
    + this->matrix[4]*this->matrix[9]*this->matrix[2]
    + this->matrix[8]*this->matrix[1]*this->matrix[6]
    - this->matrix[0]*this->matrix[9]*this->matrix[6]
    - this->matrix[4]*this->matrix[1]*this->matrix[10]
    + this->matrix[0]*this->matrix[5]*this->matrix[10]; //Modif du - en + ici
}

Matrix4 *Matrix4::invert() {
    float invertedCoefs[12];
    invertedCoefs[0] = -this->matrix[9]*this->matrix[6]+this->matrix[5]*this->matrix[10];
    invertedCoefs[1] = this->matrix[9]*this->matrix[2]-this->matrix[1]*this->matrix[10];
    invertedCoefs[2] = -this->matrix[5]*this->matrix[2]+this->matrix[1]*this->matrix[6];
    invertedCoefs[3] = this->matrix[9]*this->matrix[6]*this->matrix[3]
            -this->matrix[5]*this->matrix[10]*this->matrix[3]
            -this->matrix[9]*this->matrix[2]*this->matrix[7]
            +this->matrix[1]*this->matrix[10]*this->matrix[7]
            +this->matrix[5]*this->matrix[2]*this->matrix[11]
            -this->matrix[1]*this->matrix[6]*this->matrix[11];
    invertedCoefs[4] = this->matrix[8]*this->matrix[6]-this->matrix[4]*this->matrix[10];
    invertedCoefs[5] = -this->matrix[8]*this->matrix[2]+this->matrix[0]*this->matrix[10];
    invertedCoefs[6] = this->matrix[4]*this->matrix[2]-this->matrix[0]*this->matrix[6];
    invertedCoefs[7] = -this->matrix[8]*this->matrix[6]*this->matrix[3]
                       +this->matrix[4]*this->matrix[10]*this->matrix[3]
                       +this->matrix[8]*this->matrix[2]*this->matrix[7]
                       -this->matrix[0]*this->matrix[10]*this->matrix[7]
                       -this->matrix[4]*this->matrix[2]*this->matrix[11]
                       +this->matrix[0]*this->matrix[6]*this->matrix[11];
    invertedCoefs[8] = -this->matrix[5]*this->matrix[5]+this->matrix[4]*this->matrix[9];
    invertedCoefs[9] = this->matrix[8]*this->matrix[1]-this->matrix[0]*this->matrix[9];
    invertedCoefs[10] = -this->matrix[4]*this->matrix[1]+this->matrix[0]*this->matrix[5];
    invertedCoefs[11] = +this->matrix[8]*this->matrix[5]*this->matrix[3]
                        -this->matrix[4]*this->matrix[9]*this->matrix[3]
                        -this->matrix[8]*this->matrix[1]*this->matrix[7]
                        +this->matrix[0]*this->matrix[9]*this->matrix[7]
                        +this->matrix[4]*this->matrix[1]*this->matrix[11]
                        -this->matrix[0]*this->matrix[5]*this->matrix[11];
    Matrix4 * invertedMatrix = new Matrix4(invertedCoefs);
    return (*invertedMatrix)*this->getDeterminant();
}

Vector3D *Matrix4::directionTransformRotation(Vector3D *direction) {
    float x = this->matrix[0]*direction->getX()+this->matrix[1]*direction->getY()+this->matrix[2]*direction->getZ();
    float y = this->matrix[4]*direction->getX()+this->matrix[5]*direction->getY()+this->matrix[6]*direction->getZ();
    float z = this->matrix[8]*direction->getX()+this->matrix[9]*direction->getY()+this->matrix[10]*direction->getZ();
    return new Vector3D(x,y,z);
}

Vector3D *Matrix4::invertDirectionTransformRotation(Vector3D *direction) {
    Matrix4 * invertedMatrix = this->invert();
    float x = invertedMatrix->matrix[0]*direction->getX()+invertedMatrix->matrix[1]*direction->getY()+invertedMatrix->matrix[2]*direction->getZ();
    float y = invertedMatrix->matrix[4]*direction->getX()+invertedMatrix->matrix[5]*direction->getY()+invertedMatrix->matrix[6]*direction->getZ();
    float z = invertedMatrix->matrix[8]*direction->getX()+invertedMatrix->matrix[9]*direction->getY()+invertedMatrix->matrix[10]*direction->getZ();
    return new Vector3D(x,y,z);
}


