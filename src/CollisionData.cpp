//
// Created by loicsrz on 05/12/2018.
//

#include "../include/2B3_Engine/CollisionData.h"

int CollisionData::getContactLeft() const {
    return contactLeft;
}

void CollisionData::setContactLeft(int contactLeft) {
    CollisionData::contactLeft = contactLeft;
}

const vector<Contact *> &CollisionData::getContacts() const {
    return contacts;
}

void CollisionData::setContacts(const vector<Contact *> &contacts) {
    CollisionData::contacts = contacts;
}

void CollisionData::Addcontact(Contact *contact) {
    contacts.push_back(contact);
}
