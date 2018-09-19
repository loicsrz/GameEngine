//
// Created by Vince on 29/08/2018.
//

#ifndef GAMEENGINE_VECTEUR3D_H
#define GAMEENGINE_VECTEUR3D_H

// Classe Vector3D:
//      Classe qui définit ce qu'est un vecteur ainsi que l'ensemble des méthodes que peut effectuer celui-ci.

class Vector3D {
protected:
    // On définit ici les 3 coordonnées du vecteur(x,y,z).
    float x;
    float y;
    float z;

public:
    // Constructeur par défaut.
    Vector3D();

    // Constructeur connaissant les coordonnées du vecteur.
    Vector3D(float x, float y, float z);

    Vector3D( const Vector3D & vecteur);

    // Destructeur.
    virtual ~Vector3D();

    // Méthode qui définit l'addition entre le vecteur et un vecteur v.
    Vector3D * AjoutVecteur(Vector3D *v);

    // Méthode qui définit la soustraction entre le vecteur et un vecteur v.
    Vector3D * SoustraireVecteur(Vector3D *v);

    // Méthode qui définit la multiplication du vecteur par un scalaire nb.
    Vector3D * MultiplierScalaire(float nb);

    // Méthode qui définit le produit de la composante entre le vecteur et un vecteur v.
    Vector3D * ProduitComposante(Vector3D *v);

    // Méthode qui définit le produit scalaire entre le vecteur et un vecteur v.
    float ProduitScalaire(Vector3D *v);

    // Méthode qui permet d'obtenir la norme du vecteur.
    float ObtenirNorme();

    // Méthode qui permet de normaliser le vecteur.
    Vector3D * NormaliserVecteur();

    // Méthode qui permet d'obtenir l'angle entre le vecteur et un vecteur v.
    float ObtenirAngle(Vector3D *v);

    // Méthode qui permet d'obtenir la projection du vecteur sur un vecteur v.
    Vector3D * ObtenirProjection(Vector3D *v);

    // Méthode qui permet d'obtenir la distance entre le vecteur et un vecteur v.
    float Distance(Vector3D *v);

    // Méthode qui permet de faire le produit vectoriel entre le vecteur et un vecteur v.
    Vector3D * ProduitVectoriel(Vector3D *v);

    // Méthode qui permet de faire le produit mixte entre le vecteur, un vecteur v et un vecteur w.
    float ProduitMixte(Vector3D *v, Vector3D *w);

    // Début de l'ensemble des getters et setters de la classe Vector3D.
    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getZ() const;

    void setZ(float z);
    // Fin de l'ensemble des getters et setters de la classe Vector3D.
};


#endif //GAMEENGINE_VECTEUR3D_H