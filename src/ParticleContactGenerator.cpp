//
// Created by loicsrz on 17/10/2018.
//
#include <math.h>
#include "../include/2B3_Engine/ParticleContactGenerator.h"


ParticleContact* ParticleContactGenerator::addContact(Particle* particle, Particle* particle1) {

    ParticleContact* contact = nullptr;
    float distance = sqrt(pow(((particle)->getPosition()->getX()-(particle1)->getPosition()->getX()), 2)
                          + pow(((particle)->getPosition()->getY()-(particle1)->getPosition()->getY()), 2));
    if (distance < (particle)->getRadius()+(particle1)->getRadius()) {
        Vector3D *perpendicularAngle = (particle)->getPosition()->substractVector((particle1)->getPosition())
                ->normalizeVector();
        float penetration = (particle)->getRadius() + (particle1)->getRadius() - distance;
        Particle *pParticle[2] = {(particle), (particle1)};
        contact = new ParticleContact(pParticle, 0.75, perpendicularAngle, penetration);
    }

    return contact;

}

ParticleContactGenerator::ParticleContactGenerator() {

}

ParticleContactGenerator::~ParticleContactGenerator() {

}

