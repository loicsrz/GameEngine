//
// Created by Vince on 29/08/2018.
//

#ifndef GAMEENGINE_VECTEUR3D_H
#define GAMEENGINE_VECTEUR3D_H

// Classe Vecteur3D:
//      Classe qui définit ce qu'est un vecteur ainsi que l'ensemble des méthodes que peut effectuer celui-ci.

class Vecteur3D {
protected:
    // On définit ici les 3 coordonnées du vecteur(x,y,z).
    float x;
    float y;
    float z;

public:
    // Constructeur par défaut.
    Vecteur3D();

    // Constructeur connaissant les coordonnées du vecteur.
    Vecteur3D(float x, float y, float z);

    // Destructeur.
    virtual ~Vecteur3D();

    // Méthode qui définit l'addition entre le vecteur et un vecteur v.
    Vecteur3D * AjoutVecteur(Vecteur3D *v);

    // Méthode qui définit la soustraction entre le vecteur et un vecteur v.
    Vecteur3D * SoustraireVecteur(Vecteur3D *v);

    // Méthode qui définit la multiplication du vecteur par un scalaire nb.
    Vecteur3D * MultiplierScalaire(float nb);

    // Méthode qui définit le produit de la composante entre le vecteur et un vecteur v.
    Vecteur3D * ProduitComposante(Vecteur3D *v);

    // Méthode qui définit le produit scalaire entre le vecteur et un vecteur v.
    float ProduitScalaire(Vecteur3D *v);

    // Méthode qui permet d'obtenir la norme du vecteur.
    float ObtenirNorme();

    // Méthode qui permet de normaliser le vecteur.
    Vecteur3D * NormaliserVecteur();

    // Méthode qui permet d'obtenir l'angle entre le vecteur et un vecteur v.
    float ObtenirAngle(Vecteur3D *v);

    // Méthode qui permet d'obtenir la projection du vecteur sur un vecteur v.
    Vecteur3D * ObtenirProjection(Vecteur3D *v);

    // Méthode qui permet d'obtenir la distance entre le vecteur et un vecteur v.
    float Distance(Vecteur3D *v);

    // Méthode qui permet de faire le produit vectoriel entre le vecteur et un vecteur v.
    Vecteur3D * ProduitVectoriel(Vecteur3D *v);

    // Méthode qui permet de faire le produit mixte entre le vecteur, un vecteur v et un vecteur w.
    float ProduitMixte(Vecteur3D *v, Vecteur3D *w);

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