//
// Created by loicsrz on 19/09/2018.
//

#ifndef GAMEENGINE_REGISTERFORCES_H
#define GAMEENGINE_REGISTERFORCES_H


#include <vector>
#include "Particle.h"
#include "ParticleForceGenerator.h"

/// Structure de liaison entre un générateur de force et une Particle
struct SaveForce {
    Particle *particle;
    ParticleForceGenerator *forceGenerator;
};

typedef std::vector<SaveForce> Register;

/// Classe RegisterForces
    /// Classe qui modélise un registre de forces à appliquer à des Particle
class RegisterForces {

public:
    Register m_register;

public:
    ///Constructeur par défaut
    RegisterForces();

    ///Destructeur
    ~RegisterForces();

    /// Méthode d'ajout d'un SaveForce au registre de SaveForce
    void addRegister(SaveForce saveForce);

    /// Méthode de retrait d'un SaveForce au registre de SaveForce
    void deleteRegister(SaveForce saveForce);

    /// Méthode retournant le nombre d'éléments du registre de SaveForce
    int countRegister();

    /// Méthode qui vide le registre de SaveForce
    void clearRegister();
};


#endif //GAMEENGINE_REGISTERFORCES_H
