//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_PARTICLECONTACTGENERATOR_H
#define GAMEENGINE_PARTICLECONTACTGENERATOR_H


#include "Particle.h"
#include "ParticleContact.h"
#include <vector>

using namespace std;

/// Classe ParticleContactGenerator
    /// Classe qui permet de générer des contacts entre des Particle
class ParticleContactGenerator {

public:
    ///Constructeur par défaut
    ParticleContactGenerator();

    ///Destructeur
    virtual ~ParticleContactGenerator();

    /// Méthode de création d'un contact entre deux Particle
    virtual ParticleContact* addContact(Particle* particle, Particle* particle1);

};
#endif


