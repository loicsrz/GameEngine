//
// Created by loicsrz on 05/12/2018.
//

#ifndef GAMEENGINE_COLLISIONDATA_H
#define GAMEENGINE_COLLISIONDATA_H


#include "Contact.h"

class CollisionData {

private:
    int contactLeft;
    vector<Contact*> contacts;

public:
    int getContactLeft() const;

    void setContactLeft(int contactLeft);

    const vector<Contact *> &getContacts() const;

    void setContacts(const vector<Contact *> &contacts);

    void Addcontact(Contact *contact);
};




#endif //GAMEENGINE_COLLISIONDATA_H
