//
// Created by loicsrz on 21/10/2018.
//

#include "../include/2B3_Engine/ParticleRod.h"
#include "../include/2B3_Engine/Vector3D.h"
#include "../include/2B3_Engine/ParticleContact.h"

///Constructeur de ParticleCable
ParticleRod::ParticleRod(float maxLenght, float restitutionCoefficient) : maxLength(maxLenght), restitutionCoefficient(
        restitutionCoefficient) {}

///Destructeur
ParticleRod::~ParticleRod() {

}

/// Méthode qui crée un contact en cas de conditions relative à la Tige non respectées
ParticleContact* ParticleRod::addContact() {

    ParticleContact *contact = nullptr;
    if (linkLength() > maxLength)
    {
        Vector3D* perpendicularAngle = (linkedParticles[1])->getPosition()->substractVector((linkedParticles[0])->getPosition())
                ->normalizeVector();
        float penetration = 0;
        contact = new ParticleContact(linkedParticles, 0.5,perpendicularAngle, penetration,true );
    }
    else if(linkLength()< maxLength){
        Vector3D* perpendicularAngle = (linkedParticles[1])->getPosition()->substractVector((linkedParticles[0])->getPosition())
                ->normalizeVector();
        float penetration = 0;
        contact = new ParticleContact(linkedParticles, 0.5,perpendicularAngle, penetration,false );
    }

    return contact;
}


