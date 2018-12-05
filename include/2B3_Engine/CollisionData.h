//
// Created by loicsrz on 05/12/2018.
//

#ifndef GAMEENGINE_COLLISIONDATA_H
#define GAMEENGINE_COLLISIONDATA_H


#include "Contact.h"

class CollisionData {

    Contact * contact;
public:
    Contact *getContact() const;

    void setContact(Contact *contact);

    int getContactLeft() const;

    void setContactLeft(int contactLeft);

private:
    int contactLeft;

};


#endif //GAMEENGINE_COLLISIONDATA_H
