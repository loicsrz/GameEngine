//
// Created by loicsrz on 05/12/2018.
//

#include "../include/2B3_Engine/CollisionData.h"

Contact *CollisionData::getContact() const {
    return contact;
}

void CollisionData::setContact(Contact *contact) {
    CollisionData::contact = contact;
}

int CollisionData::getContactLeft() const {
    return contactLeft;
}

void CollisionData::setContactLeft(int contactLeft) {
    CollisionData::contactLeft = contactLeft;
}
