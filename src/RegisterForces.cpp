//
// Created by loicsrz on 19/09/2018.
//

#include "../include/2B3_Engine/RegisterForces.h"

void RegisterForces::addRegister(SaveForce saveForce) {
    this->m_register.push_back(saveForce);

}

void RegisterForces::deleteRegister(SaveForce saveForce) {
    Register::iterator iterator;
    int count = 0;
    for (iterator = this->m_register.begin(); iterator != this->m_register.end(); iterator++) {
        if (iterator->particule == saveForce.particule && iterator->forceGenerator == saveForce.forceGenerator) {
            this->m_register.erase(iterator);
            break;
        }
        count++;
    }
}

int RegisterForces::countRegister(SaveForce saveForce) {
    return (int) this->m_register.size();

}

