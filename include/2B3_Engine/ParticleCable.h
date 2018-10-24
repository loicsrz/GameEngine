//
// Created by loicsrz on 19/10/2018.
//

#ifndef GAMEENGINE_PARTICLECABLE_H
#define GAMEENGINE_PARTICLECABLE_H


#include "ParticleLink.h"

/// Classe ParticleCable
    /// Classe qui modélise les conditions relatives à une jonction de deux Particle par une liaison de type Cable
class ParticleCable : public ParticleLink {
protected:

    float maxLength;
    float restitutionCoefficient;

public:
    ///Constructeur de ParticleCable
    ParticleCable(float maxLength, float restitutionCoefficient);

    ///Destructeur
    virtual ~ParticleCable();

    /// Méthode qui crée un contact en cas de conditions relative au Cable non respectées
    virtual ParticleContact* addContact();

};


#endif //GAMEENGINE_PARTICLECABLE_H
