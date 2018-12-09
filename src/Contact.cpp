//
// Created by loicsrz on 05/12/2018.
//

#include "../include/2B3_Engine/Contact.h"

Vector3D *Contact::getContactPoint() const {
    return contactPoint;
}

void Contact::setContactPoint(Vector3D *contactPoint) {
    Contact::contactPoint = contactPoint;
}

Vector3D *Contact::getPerpendicularAngle() const {
    return perpendicularAngle;
}

void Contact::setPerpendicularAngle(Vector3D *perpendicularAngle) {
    Contact::perpendicularAngle = perpendicularAngle;
}

float Contact::getInterpenetration() const {
    return interpenetration;
}

void Contact::setInterpenetration(float interpenetration) {
    Contact::interpenetration = interpenetration;
}

Contact::Contact(Vector3D *contactpoint, Vector3D *perpendicularangle, float inter) : contactPoint(contactpoint),
perpendicularAngle(perpendicularangle), interpenetration(inter){

}

Contact::~Contact() {
    delete  contactPoint;
    delete perpendicularAngle;
}
