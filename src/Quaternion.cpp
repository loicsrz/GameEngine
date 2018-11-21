//
// Created by loicsrz on 07/11/2018.
//

#include <cmath>
#include <iostream>
#include "../include/2B3_Engine/Quaternion.h"

///Constructeur - Destructeur ------------------------------------------------------------------------------------------
Quaternion::Quaternion(float r, float i, float j, float k):r(r),i(i),j(j),k(k) {

}

Quaternion::~Quaternion() {

}

///---------------------------------------------------------------------------------------------------------------------

///Méthode de normalisation d'un quaternion
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
        k = d*k;
    }

}

///Méthode de mise à jour de la vélocité angulaire
void Quaternion::UpdateAngularVelocity(Vector3D* v, float duration) {

    Quaternion * newQuat = (*this) + *((*(Quaternion(0,v->getX(),v->getY(), v->getZ())*(duration/2)))*(*this));
    newQuat->normalize();
    this->setR(newQuat->getR());
    this->setI(newQuat->getI());
    this->setJ(newQuat->getJ());
    this->setK(newQuat->getK());
}

///Méthode de conversion d'un vecteur en Quaternion
void Quaternion::doRotation(Vector3D* v) {

    Quaternion *quaternion = new Quaternion(0,v->getX(),v->getY(),v->getZ());
    quaternion = (*this)*(*quaternion);
    this->r = quaternion->r;
    this->i = quaternion->i;
    this->j = quaternion->j;
    this->k = quaternion->k;

}

///Surcharges d'opérateurs ----------------------------------------------------------------------------------------------------------------------
Quaternion* Quaternion::operator*(Quaternion const &b) {
    float w = this->r*b.r - this->i*b.i - this->j*b.j - this->k*b.k;
    float i = this->r*b.i + b.r*this->i + this->j*b.k - this->k*b.j;
    float j = this->r*b.j + b.r*this->j + this->k*b.i - this->i*b.k;
    float k = this->r*b.k + b.r*this->k + this->i*b.j - this->j*b.i;

    Quaternion *quaternion = new Quaternion(w, i, j, k);
    return quaternion;
}

Quaternion* Quaternion::operator*(float const &number) {
    Quaternion *quaternion = new Quaternion(this->r*number, this->i*number, this->j*number, this->k*number);
    return quaternion;
}

Quaternion* Quaternion::operator+(Quaternion const &quaternion) {
    Quaternion *quaternion1 = new Quaternion(this->r + quaternion.r, this->i + quaternion.i, this->j + quaternion.j, this->k + quaternion.k);
    return quaternion1;
}

///-----------------------------------------------------------------------------------------------------------------------------------------------

///Getters - Setters ------------------------------------------------------------
float Quaternion::getR() const {
    return r;
}

void Quaternion::setR(float r) {
    Quaternion::r = r;
}

float Quaternion::getI() const {
    return i;
}

void Quaternion::setI(float i) {
    Quaternion::i = i;
}

float Quaternion::getJ() const {
    return j;
}

void Quaternion::setJ(float j) {
    Quaternion::j = j;
}

float Quaternion::getK() const {
    return k;
}

void Quaternion::setK(float k) {
    Quaternion::k = k;
}

///-----------------------------------------------------------------------------

///Méthode d'affichage d'un quaternion
void Quaternion::toString(){
    cout << "r : " << r << " | i : " << i << " | j : " << j << " | k : " << k << endl;
}
