//
// Created by loicsrz on 19/10/2018.
//

#ifndef GAMEENGINE_PARTICLELINK_H
#define GAMEENGINE_PARTICLELINK_H


#include "Particle.h"
#include "ParticleContactGenerator.h"

/// Classe ParticleLink
    /// Classe qui modélise un lien entre deux Particle
class ParticleLink : public ParticleContactGenerator {

protected:
    Particle* linkedParticles[2];

public:

    /// Méthode de récupération de la longueur actuelle du Link entre deux Particle
    float linkLength();

    /// Méthode de création de contact en cas de conditions de Link non respectées
    virtual ParticleContact* addContact()=0;

    ///Getters - Setters ----------------------------------------------
    Particle *const *getLinkedParticles() const;

    void setParticles(Particle * particleA, Particle * particleB);
    ///----------------------------------------------------------------
};


#endif //GAMEENGINE_PARTICLELINK_H
