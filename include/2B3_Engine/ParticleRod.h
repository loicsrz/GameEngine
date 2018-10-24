//
// Created by loicsrz on 21/10/2018.
//

#ifndef GAMEENGINE_PARTICLEROD_H
#define GAMEENGINE_PARTICLEROD_H


#include "ParticleLink.h"

/// Classe ParticleRod
    /// Classe qui modélise les conditions relatives à une jonction de deux Particle par une liaison de type Tige
class ParticleRod : public ParticleLink{

protected:

    float maxLength;
    float restitutionCoefficient;

public:
    ///Constructeur de ParticleCable
    ParticleRod(float maxLenght, float restitutionCoefficient);

    ///Destructeur
    virtual ~ParticleRod();

    /// Méthode qui crée un contact en cas de conditions relative à la Tige non respectées
    virtual ParticleContact* addContact();


};


#endif //GAMEENGINE_PARTICLEROD_H
