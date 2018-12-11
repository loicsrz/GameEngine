//
// Created by loicsrz on 05/12/2018.
//

#include "../include/2B3_Engine/CollisionData.h"

CollisionData::CollisionData() {}

/// Méthode qui permet d'ajouter un contact au vecteur
void CollisionData::addContact(Contact *contact) {
    contacts.push_back(contact);
}

/// Méthode qui reset CollisionData
void CollisionData::resetCollisionData() {
    contactLeft = 0;
    contacts.clear();
}

/// Méthode qui permet d'ajouter des plans au vecteur
void CollisionData::addPlanes(Plane *plane) {
    planes.push_back(plane);
}

/// Getters - Setters ------------------------------------------------------------------------------------------
int CollisionData::getContactLeft() const {
    return contactLeft;
}

void CollisionData::setContactLeft(int contactLeft) {
    CollisionData::contactLeft = contactLeft;
}

 vector<Contact *> &CollisionData::getContacts()  {
    return contacts;
}

void CollisionData::setContacts(const vector<Contact *> &contacts) {
    CollisionData::contacts = contacts;
}


const vector<Plane *> &CollisionData::getPlanes() const {
    return planes;
}

void CollisionData::setPlanes(const vector<Plane *> &planes) {
    CollisionData::planes = planes;
}
