//
// Created by Vince on 29/08/2018.
//

#include "../include/2B3_Engine/Vector3D.h"
#include <cmath>

// Constructeur par défaut.
Vector3D::Vector3D() : x(0),y(0),z(0) {}

// Contructeur connaissant les coordonnées du vecteur.
Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3D::Vector3D(const Vector3D &vecteur) {
    this->x = vecteur.x;
    this->y = vecteur.y;
    this->z = vecteur.z;
}
// Destructeur.
Vector3D::~Vector3D() = default;

// Méthode qui définit l'addition entre le vecteur et un vecteur v.
Vector3D * Vector3D::AjoutVecteur(Vector3D * v) {
    return new Vector3D(this->x+v->x,this->y+v->y,this->z+v->z);
}

// Méthode qui définit la soustraction entre le vecteur et un vecteur v.
Vector3D * Vector3D::SoustraireVecteur(Vector3D *v) {
    return new Vector3D(this->x-v->x,this->y-v->y,this->z-v->z);
}

// Méthode qui définit la multiplication du vecteur par un scalaire nb.
Vector3D * Vector3D::MultiplierScalaire(float nb) {
    return new Vector3D(this->x*nb,this->y*nb,this->z*nb);
}

// Méthode qui définit le produit de la composante entre le vecteur et un vecteur v.
Vector3D * Vector3D::ProduitComposante(Vector3D *v) {
    return new Vector3D(this->x*v->x,this->y*v->y,this->z*v->z);
}

// Méthode qui définit le produit scalaire entre le vecteur et un vecteur v.
float Vector3D::ProduitScalaire(Vector3D *v) {
    return this->x*v->x+this->y*v->y+this->z*v->z;
}

// Méthode qui permet d'obtenir la norme du vecteur.
float Vector3D::ObtenirNorme() {
    return static_cast<float>(sqrt(this->x * this->x + this->y * this->y + this->z * this->z));
}

// Méthode qui permet de normaliser le vecteur.
Vector3D * Vector3D::NormaliserVecteur() {
    // On récupère la norme du vecteur.
    float norme=this->ObtenirNorme();
    // On normalise le vecteur.
    return new Vector3D(this->x/norme,this->y/norme,this->z/norme);
}

// Méthode qui permet d'obtenir l'angle entre le vecteur et un vecteur v.
float Vector3D::ObtenirAngle(Vector3D *v) {
    return static_cast<float>(acos(this->ProduitScalaire(v) / (this->ObtenirNorme() * v->ObtenirNorme())));
}

// Méthode qui permet d'obtenir la projection du vecteur sur un vecteur v.
Vector3D * Vector3D::ObtenirProjection(Vector3D *v) {
    // On récupère la norme de v.
    float normeV = v->ObtenirNorme();
    // On fait le calcul de la partie gauche du produit scalaire (u.v/||v||²).
    float proportion = this->ProduitScalaire(v)/(normeV*normeV);
    // On multiplie le scalaire obtenue par le vecteur v sur lequel on projecte notre vecteur.
    return v->MultiplierScalaire(proportion);
}

// Méthode qui permet d'obtenir la distance entre le vecteur et un vecteur v.
float Vector3D::Distance(Vector3D *v) {
    return static_cast<float>(sqrt(pow(this->x - v->x, 2) + pow(this->y - v->y, 2) + pow(this->z - v->z, 2)));
}

// Méthode qui permet de faire le produit vectoriel entre le vecteur et un vecteur v.
Vector3D * Vector3D::ProduitVectoriel(Vector3D *v) {
    float x = this->y*v->z-this->z*v->y;
    float y = this->z*v->x-this->x*v->z;
    float z = this->x*v->y-this->y*v->x;
    return new Vector3D(x,y,z);
}

// Méthode qui permet de faire le produit mixte entre le vecteur, un vecteur v et un vecteur w.
float Vector3D::ProduitMixte(Vector3D * v, Vector3D * w) {
    return this->ProduitScalaire(v->ProduitVectoriel(w));
}

// Début de l'ensemble des getters et setters de la classe Vector3D.

float Vector3D::getX() const {
    return x;
}

void Vector3D::setX(float x) {
    this->x = x;
}

float Vector3D::getY() const {
    return y;
}

void Vector3D::setY(float y) {
    this->y = y;
}

float Vector3D::getZ() const {
    return z;
}

void Vector3D::setZ(float z) {
    this->z = z;
}
// Fin de l'ensemble des getters et setters de la classe Vector3D.
