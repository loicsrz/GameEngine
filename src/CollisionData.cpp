//
// Created by loicsrz on 05/12/2018.
//

#include "../include/2B3_Engine/CollisionData.h"

CollisionData::CollisionData() {}

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

void CollisionData::addContact(Contact *contact) {
    contacts.push_back(contact);
}

void CollisionData::resetCollisionData() {
    contactLeft = 0;
    contacts.clear();
}

const vector<Plane *> &CollisionData::getPlanes() const {
    return planes;
}

void CollisionData::setPlanes(const vector<Plane *> &planes) {
    CollisionData::planes = planes;
}

void CollisionData::addPlanes(Plane *plane) {
    planes.push_back(plane);
}
