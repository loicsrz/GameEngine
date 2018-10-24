//
// Created by loicsrz on 19/10/2018.
//

#include "../include/2B3_Engine/ParticleCable.h"
#include <iostream>
using namespace std;


///Constructeur de ParticleCable
ParticleCable::ParticleCable(float maxLength, float restitutionCoefficient) : maxLength(maxLength),
                                                                              restitutionCoefficient(
                                                                                      restitutionCoefficient) {}

///Destructeur
ParticleCable::~ParticleCable() {

}

/// Méthode qui crée un contact en cas de conditions relative au Cable non respectées
ParticleContact* ParticleCable::addContact() {

    ParticleContact *contact = nullptr;

    if (linkLength() > maxLength)
    {
        Vector3D* perpendicularAngle = (linkedParticles[1])->getPosition()->substractVector((linkedParticles[0])->getPosition())
                ->normalizeVector();
        float penetration = 0;
        contact = new ParticleContact(linkedParticles, restitutionCoefficient, perpendicularAngle, penetration,true );
    }
    return contact;
}


