//
// Created by Vince on 29/08/2018.
//

#ifndef GAMEENGINE_VECTEUR3D_H
#define GAMEENGINE_VECTEUR3D_H


class Vecteur3D {
protected:
    float x;
    float y;
    float z;

public:
    Vecteur3D();

    Vecteur3D(float x, float y, float z);

    virtual ~Vecteur3D();

    Vecteur3D * AjoutVecteur(Vecteur3D *v);

    Vecteur3D * SoustraireVecteur(Vecteur3D *v);

    Vecteur3D * MultiplierScalaire(float nb);

    Vecteur3D * ProduitComposante(Vecteur3D *v);

    float ProduitScalaire(Vecteur3D *v);

    float ObtenirNorme();

    Vecteur3D * NormaliserVecteur();

    float ObtenirAngle(Vecteur3D *v);

    Vecteur3D * ObtenirProjection(Vecteur3D *v);

    float Distance(Vecteur3D *v);

    Vecteur3D * ProduitVectoriel(Vecteur3D *v);

    float ProduitMixte(Vecteur3D *v, Vecteur3D *w);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getZ() const;

    void setZ(float z);
};


#endif //GAMEENGINE_VECTEUR3D_H
