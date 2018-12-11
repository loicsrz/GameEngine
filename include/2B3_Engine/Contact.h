//
// Created by loicsrz on 05/12/2018.
//

#ifndef GAMEENGINE_CONTACT_H
#define GAMEENGINE_CONTACT_H


#include "Vector3D.h"

class Contact {

    ///Attributs
private:
    /// Point de contact
    Vector3D * contactPoint;

    /// Normale
    Vector3D * perpendicularAngle;

    /// Interpénétration
    float interpenetration;

public:

    ///Constructeur
    Contact(Vector3D * contactpoint, Vector3D * perpendicularangle, float inter);

    ///Destructeur
    ~Contact();

    /// Getters - Setters -----------------------------------------------------

    Vector3D *getContactPoint() const;

    void setContactPoint(Vector3D *contactPoint);

    Vector3D *getPerpendicularAngle() const;

    void setPerpendicularAngle(Vector3D *perpendicularAngle);

    float getInterpenetration() const;

    void setInterpenetration(float interpenetration);


};


#endif //GAMEENGINE_CONTACT_H
