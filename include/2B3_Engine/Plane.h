//
// Created by vince on 05/12/2018.
//

#ifndef GAMEENGINE_PLANE_H
#define GAMEENGINE_PLANE_H


#include "Primitive.h"

class Plane : public Primitive{

private:
    ///Attributs

    /// Normale
    Vector3D * perpendicularAngle;

    /// Offset
    float offset;

public:

    /// Constructeur
    Plane(RigidBody *body, Matrix4 *offset1, Vector3D *perpendicularAngle, float offset);

    /// Destructeur
    virtual ~Plane();


/// Getters - Setters ----------------------------------------------------------------------------------------------
    Vector3D *getPerpendicularAngle() const;

    void setPerpendicularAngle(Vector3D *perpendicularAngle);

    float getOffset() const;

    void setOffset(float offset);

    /// Méthode utilisé pour débugguer
    void toString();


};


#endif //GAMEENGINE_PLANE_H
