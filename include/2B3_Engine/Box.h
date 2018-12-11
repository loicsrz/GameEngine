//
// Created by totoa on 28/11/2018.
//

#ifndef GAMEENGINE_BOX_H
#define GAMEENGINE_BOX_H


#include "Vector3D.h"
#include "Primitive.h"
#include "Sphere.h"

class Box : public Primitive{

    ///Attributs
protected:

    ///Centre
    Vector3D * center;

    /// Moitié de la longueur en X
    float semiWidth; //semiX

    /// Moitié de la longueur en Y
    float semiHeight; //semiY

    /// Moitié de la longueur Z
    float semiDepth; //semiZ

    /// Sphère pour la broad phase
    Sphere* sphere; //Broad volume

public:

    /// Constructeur
    Box(RigidBody *body, Matrix4 *offset, Vector3D *center, float semiWidth, float semiHeight, float semiDepth,
        Sphere *sphere);

    /// Destructeur
    virtual ~Box();

    /// Méthode permettant d'obtenir l'ensemble des sommets
    vector<Vector3D*> getAllCorners();

    vector<Vector3D*> getBoxVertices();

/// Getters - Setters ----------------------------------------------------------------------------------------------

    Vector3D *getCenter() const;

    void setCenter(Vector3D *center);

    float getSemiWidth() const;

    void setSemiWidth(float semiWidth);

    float getSemiHeight() const;

    void setSemiHeight(float semiHeight);

    float getSemiDepth() const;

    void setSemiDepth(float semiDepth);

    Sphere *getSphere() const;

    void setSphere(Sphere *sphere);
};


#endif //GAMEENGINE_BOX_H
