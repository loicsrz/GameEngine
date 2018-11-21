//
// Created by loicsrz on 19/09/2018.
//

#include "../include/2B3_Engine/RegisterForces.h"

///Constructeur par défaut
RegisterForces::RegisterForces() {

}

///Destructeur
RegisterForces::~RegisterForces() {

}

/// Méthode d'ajout d'un SaveForce au registre de SaveForce
void RegisterForces::addRegister(SaveForce saveForce) {
    this->m_register.push_back(saveForce);

}

/// Méthode de retrait d'un SaveForce au registre de SaveForce
void RegisterForces::deleteRegister(SaveForce saveForce) {
    Register::iterator iterator;
    int count = 0;
    for (iterator = this->m_register.begin(); iterator != this->m_register.end(); iterator++) {
        if (iterator->particle == saveForce.particle && iterator->forceGenerator == saveForce.forceGenerator) {
            this->m_register.erase(iterator);
            break;
        }
        count++;
    }
}

/// Méthode retournant le nombre d'éléments du registre de SaveForce
int RegisterForces::countRegister() {
    return (int) this->m_register.size();

}

/// Méthode qui vide le registre de SaveForce
void RegisterForces::clearRegister() {
    m_register.clear();
}


