//
// Created by loicsrz on 07/11/2018.
//

#include <cmath>
#include "../include/2B3_Engine/Quaternion.h"

void Quaternion::normalize() {

    float d = r*r+i*i+j*j+k*k;
    if(d == 0){
        r = 1;
        i=j=k=0;
    } else{
        d = 1/sqrt(d);
        r = d*r;
        i = d*i;
        j = d*j;

    }

}

void Quaternion::UpdateAngularVelocity(Vector3D v, float duration) {
    (*this) = (*this) + (Quaternion(0,v.getX(),v.getY(), v.getZ())*(duration/2))*(*this);

}

Quaternion* Quaternion::operator*(Quaternion const &b) {
    float w = this->r*b.r - this->i*b.i - this->j*b.j - this->k*b.k;
    float i = this->r*b.i + b.r*this->i + this->j*b.k - this->k*b.j;
    float j = this->r*b.j + b.r*this->j + this->k*b.i - this->i*b.k;
    float k = this->r*b.k + b.r*this->k + this->i*b.j - this->j*b.i;

    Quaternion *quaternion = new Quaternion(w, i, j, k);
    return quaternion;
}

Quaternion::Quaternion(float a, float b, float c, float d):r(a),i(b),j(c),k(d) {

}

Quaternion::~Quaternion() {

}

void Quaternion::doRotation(Vector3D v) {

    Quaternion *quaternion = new Quaternion(0,v.getX(),v.getY(),v.getZ());
    quaternion = (*this)*(*quaternion);
    this->r = quaternion->r;
    this->i = quaternion->i;
    this->j = quaternion->j;
    this->k = quaternion->k;

}

Quaternion* Quaternion::operator*(float const &number) {
    Quaternion *quaternion = new Quaternion(this->r*number, this->i*number, this->j*number, this->k*number);
    return quaternion;
}

Quaternion* Quaternion::operator+(Quaternion const &quaternion) {
    Quaternion *quaternion1 = new Quaternion(this->r + quaternion.r, this->i + quaternion.i, this->j + quaternion.j, this->k + quaternion.k);
    return quaternion1;
}
