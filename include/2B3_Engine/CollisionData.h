//
// Created by loicsrz on 05/12/2018.
//

#ifndef GAMEENGINE_COLLISIONDATA_H
#define GAMEENGINE_COLLISIONDATA_H


#include "Contact.h"
#include "Plane.h"

class CollisionData {

private:
    int contactLeft;
    vector<Contact*> contacts;
    vector<Plane*> planes;

public:
    CollisionData();

    void resetCollisionData();

    int getContactLeft() const;

    void setContactLeft(int contactLeft);

     vector<Contact *> &getContacts() ;

    void setContacts(const vector<Contact *> &contacts);

    void addContact(Contact *contact);

    const vector<Plane *> &getPlanes() const;

    void setPlanes(const vector<Plane *> &planes);

    void addPlanes(Plane *plane);
};




#endif //GAMEENGINE_COLLISIONDATA_H
