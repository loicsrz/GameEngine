//
// Created by totoa on 07/11/2018.
//

#include <cmath>
#include "../include/2B3_Engine/Matrix3.h"

/// Constructeur - Destructeur -----------------------------------------------------------------------------------
Matrix3::Matrix3(vector<float> matrix) : matrix(matrix) {}

Matrix3::~Matrix3(){
    for (int i = 0; i < 9; ++i) {
        matrix.push_back(0.0f);
    }
}

///----------------------------------------------------------------------------------------------------------------

///Méthode d'inversion de la matrice
Matrix3 *Matrix3::invert() {
    if(this->getDeterminant()!=0){
        vector<float> invertCoefs;
        for (int i = 0; i < 9; ++i) {
            invertCoefs.push_back(0.0f);
        }
        invertCoefs[0] = this->matrix[4]*this->matrix[8]-this->matrix[5]*this->matrix[7];
        invertCoefs[1] = this->matrix[2]*this->matrix[7]-this->matrix[1]*this->matrix[8];
        invertCoefs[2] = this->matrix[1]*this->matrix[5]-this->matrix[2]*this->matrix[4];
        invertCoefs[3] = this->matrix[5]*this->matrix[6]-this->matrix[3]*this->matrix[8];
        invertCoefs[4] = this->matrix[0]*this->matrix[8]-this->matrix[2]*this->matrix[6];
        invertCoefs[5] = this->matrix[2]*this->matrix[3]-this->matrix[0]*this->matrix[5];
        invertCoefs[6] = this->matrix[3]*this->matrix[7]-this->matrix[4]*this->matrix[6];
        invertCoefs[7] = this->matrix[1]*this->matrix[6]-this->matrix[0]*this->matrix[7];
        invertCoefs[8] = this->matrix[0]*this->matrix[4]-this->matrix[1]*this->matrix[3];
        Matrix3* invertedMatrix = new Matrix3(invertCoefs);
        return (*invertedMatrix)*(this->getDeterminant());
    }

    return this;
}

///Méthode de transposition de la matrice
Matrix3 *Matrix3::transposition() {
    vector<float> transposeCoefs;
    for (int i = 0; i < 9; ++i) {
        transposeCoefs.push_back(0.0f);
    }
    transposeCoefs[0] = this->matrix[0];
    transposeCoefs[1] = this->matrix[3];
    transposeCoefs[2] = this->matrix[6];
    transposeCoefs[3] = this->matrix[1];
    transposeCoefs[4] = this->matrix[4];
    transposeCoefs[5] = this->matrix[7];
    transposeCoefs[6] = this->matrix[2];
    transposeCoefs[7] = this->matrix[5];
    transposeCoefs[8] = this->matrix[8];
    return new Matrix3(transposeCoefs);
}

///Méthode qui calcule le déterminant de la matrice
float Matrix3::getDeterminant() {
    return this->matrix[0]*this->matrix[4]*this->matrix[8]
    + this->matrix[3]*this->matrix[7]*this->matrix[2]
    +  this->matrix[6]*this->matrix[1]*this->matrix[5]
    -  this->matrix[0]*this->matrix[7]*this->matrix[5]
    -  this->matrix[6]*this->matrix[4]*this->matrix[2]
    -  this->matrix[3]*this->matrix[1]*this->matrix[8];
}

///Méthode de conversion d'un Quaternion en Matrix3
Matrix3 *Matrix3::setOrientation(Quaternion *q) {
    vector<float> quatMatCoefs;
    for (int i = 0; i < 9; ++i) {
        quatMatCoefs.push_back(0.0f);
    }
    quatMatCoefs[0] = 1 - (2*powf(q->getJ(),2.0f)+2*powf(q->getK(),2.0f));
    quatMatCoefs[1] = 2*q->getI()*q->getJ()+2*q->getK()*q->getR();
    quatMatCoefs[2] = 2*q->getI()*q->getK()-2*q->getJ()*q->getR();
    quatMatCoefs[3] = 2*q->getI()*q->getJ()-2*q->getK()*q->getR();
    quatMatCoefs[4] = 1 - (2*powf(q->getI(),2.0f)+2*powf(q->getK(),2.0f));
    quatMatCoefs[5] = 2*q->getJ()*q->getK()+2*q->getI()*q->getR();
    quatMatCoefs[6] = 2*q->getI()*q->getK()+2*q->getJ()*q->getR();
    quatMatCoefs[7] = 2*q->getJ()*q->getK()-2*q->getI()*q->getR();
    quatMatCoefs[8] = 1 - (2*powf(q->getI(),2.0f)+2*powf(q->getJ(),2.0f));
    return new Matrix3(quatMatCoefs);
}

///Surcharges d'opérateurs ------------------------------------------------------------------------------
Matrix3 *Matrix3::operator*(float const &coef) {
    for(int i = 0;i<9;i++){
        matrix[i]*=coef;
    }
    return new Matrix3(matrix);
}

Vector3D *Matrix3::operator*(Vector3D const &v) {
    float x = this->matrix[0]*v.getX()+this->matrix[1]*v.getY()+this->matrix[2]*v.getZ();
    float y = this->matrix[3]*v.getX()+this->matrix[4]*v.getY()+this->matrix[5]*v.getZ();
    float z = this->matrix[6]*v.getX()+this->matrix[7]*v.getY()+this->matrix[8]*v.getZ();
    return new Vector3D(x,y,z);
}

Matrix3 *Matrix3::operator*(Matrix3 const &m) {
    vector<float> coefs;
    for (int i = 0; i < 9; ++i) {
        coefs.push_back(0.0f);
    }
    vector<float> mCoefs = m.getMatrix();
    coefs[0]=this->matrix[0]*mCoefs[0]+this->matrix[1]*mCoefs[3]+this->matrix[2]*mCoefs[6];
    coefs[1]=this->matrix[0]*mCoefs[1]+this->matrix[1]*mCoefs[4]+this->matrix[2]*mCoefs[7];
    coefs[2]=this->matrix[0]*mCoefs[2]+this->matrix[1]*mCoefs[5]+this->matrix[2]*mCoefs[8];
    coefs[3]=this->matrix[3]*mCoefs[0]+this->matrix[4]*mCoefs[3]+this->matrix[5]*mCoefs[6];
    coefs[4]=this->matrix[3]*mCoefs[1]+this->matrix[4]*mCoefs[4]+this->matrix[5]*mCoefs[7];
    coefs[5]=this->matrix[3]*mCoefs[2]+this->matrix[4]*mCoefs[5]+this->matrix[5]*mCoefs[8];
    coefs[6]=this->matrix[6]*mCoefs[0]+this->matrix[7]*mCoefs[3]+this->matrix[8]*mCoefs[6];
    coefs[7]=this->matrix[6]*mCoefs[1]+this->matrix[7]*mCoefs[4]+this->matrix[8]*mCoefs[7];
    coefs[8]=this->matrix[6]*mCoefs[2]+this->matrix[7]*mCoefs[5]+this->matrix[8]*mCoefs[8];
    return new Matrix3(coefs);
}

///----------------------------------------------------------------------------------------------------------

/// Getter
vector<float> Matrix3::getMatrix() const {
    return matrix;
}