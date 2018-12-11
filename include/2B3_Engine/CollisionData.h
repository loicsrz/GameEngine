//
// Created by loicsrz on 05/12/2018.
//

#ifndef GAMEENGINE_COLLISIONDATA_H
#define GAMEENGINE_COLLISIONDATA_H


#include "Contact.h"
#include "Plane.h"

class CollisionData {

    /// Attributs
private:
    /// Nombre de contact restant
    int contactLeft;

    /// L'ensemble des contacts réelles
    vector<Contact*> contacts;
    /// Les plans entrant en collision entrant avec la boite
    vector<Plane*> planes;

public:
    CollisionData();

    /// Méthode qui reset CollisionData
    void resetCollisionData();

    /// Méthode qui permet d'ajouter des plans au vecteur
    void addPlanes(Plane *plane);

    /// Méthode qui permet d'ajouter un contact au vecteur
    void addContact(Contact *contact);

    /// Getters - Setters -----------------------------------------------------

    int getContactLeft() const;

    void setContactLeft(int contactLeft);

     vector<Contact *> &getContacts() ;

    void setContacts(const vector<Contact *> &contacts);

    const vector<Plane *> &getPlanes() const;

    void setPlanes(const vector<Plane *> &planes);


};




#endif //GAMEENGINE_COLLISIONDATA_H
