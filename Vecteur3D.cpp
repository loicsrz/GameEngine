//
// Created by Vince on 29/08/2018.
//

#include "Vecteur3D.h"
#include <math.h>

Vecteur3D::Vecteur3D() : x(0),y(0),z(0) {}

Vecteur3D::Vecteur3D(float x, float y, float z) : x(x), y(y), z(z) {}

Vecteur3D::~Vecteur3D() {}

Vecteur3D * Vecteur3D::AjoutVecteur(Vecteur3D * v) {
    return new Vecteur3D(this->x+v->x,this->y+v->y,this->z+v->z);
}

Vecteur3D * Vecteur3D::SoustraireVecteur(Vecteur3D *v) {
    return new Vecteur3D(this->x-v->x,this->y-v->y,this->z-v->z);
}

Vecteur3D * Vecteur3D::MultiplierScalaire(float nb) {
    return new Vecteur3D(this->x*nb,this->y*nb,this->z*nb);
}

Vecteur3D * Vecteur3D::ProduitComposante(Vecteur3D *v) {
    return new Vecteur3D(this->x*v->x,this->y*v->y,this->z*v->z);
}

float Vecteur3D::ProduitScalaire(Vecteur3D *v) {
    return this->x*v->x+this->y*v->y+this->z*v->z;
}

float Vecteur3D::ObtenirNorme() {
    return sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
}

Vecteur3D * Vecteur3D::NormaliserVecteur() {
    float norme=this->ObtenirNorme();
    return new Vecteur3D(this->x/norme,this->y/norme,this->z/norme);
}

float Vecteur3D::ObtenirAngle(Vecteur3D *v) {
    return acos(this->ProduitScalaire(v)/(this->ObtenirNorme()*v->ObtenirNorme()));
}

Vecteur3D * Vecteur3D::ObtenirProjection(Vecteur3D *v) {
    float normeV = v->ObtenirNorme();
    float proportion = this->ProduitScalaire(v)/(normeV*normeV);
    return v->MultiplierScalaire(proportion);
}

float Vecteur3D::Distance(Vecteur3D *v) {
    return sqrt(pow(this->x-v->x,2)+pow(this->y-v->y,2)+pow(this->z-v->z,2));
}

Vecteur3D * Vecteur3D::ProduitVectoriel(Vecteur3D *v) {
    float x = this->y*v->z-this->z*v->y;
    float y = this->z*v->x-this->x*v->z;
    float z = this->x*v->y-this->y*v->x;
    return new Vecteur3D(x,y,z);
}

float Vecteur3D::ProduitMixte(Vecteur3D * v, Vecteur3D * w) {
    return this->ProduitScalaire(v->ProduitVectoriel(w));
}

float Vecteur3D::getX() const {
    return x;
}

void Vecteur3D::setX(float x) {
    this->x = x;
}

float Vecteur3D::getY() const {
    return y;
}

void Vecteur3D::setY(float y) {
    this->y = y;
}

float Vecteur3D::getZ() const {
    return z;
}

void Vecteur3D::setZ(float z) {
    this->z = z;
}
