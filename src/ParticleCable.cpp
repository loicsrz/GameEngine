//
// Created by loicsrz on 19/10/2018.
//

#include "../include/2B3_Engine/ParticleCable.h"

ParticleContact* ParticleCable::addContact() {

    ParticleContact *contact = nullptr;
    if (linkLength() >= maxLenght)
    {
        Vector3D* perpendicularAngle = (particle[0])->getPosition()->substractVector((particle[1])->getPosition())
                ->normalizeVector();
        float penetration = 0;
        contact = new ParticleContact(particle, 0.5,perpendicularAngle, penetration );
    }
    return contact;
}

ParticleCable::ParticleCable(float maxLenght, float restitutionCoefficient) : maxLenght(maxLenght),
                                                                              restitutionCoefficient(
                                                                                      restitutionCoefficient) {}

ParticleCable::~ParticleCable() {

}