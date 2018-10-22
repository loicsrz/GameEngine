//
// Created by loicsrz on 17/10/2018.
//
#include <math.h>
#include "../include/2B3_Engine/ParticleContactGenerator.h"


void ParticleContactGenerator::addContact(Particle* particle, Particle* particle1) {

    float distance = sqrt(pow(((particle)->getPosition()->getX()-(particle1)->getPosition()->getX()), 2)
                          + pow(((particle)->getPosition()->getY()-(particle1)->getPosition()->getY()), 2));
    if (distance < (particle)->getRadius()+(particle1)->getRadius()){
    }
        Vector3D* perpendicularAngle = (particle)->getPosition()->substractVector((particle1)->getPosition())
                ->normalizeVector();
        float penetration = (particle)->getRadius() + (particle1)->getRadius() - distance;
        Particle* pParticle[2] = {(particle),(particle1)};
        ParticleContact *particleContact1 = new ParticleContact(pParticle, 0.75,perpendicularAngle, penetration );
        particleContact.push_back(particleContact1);


}

ParticleContactGenerator::ParticleContactGenerator(vector<ParticleContact *> vector) {

    particleContact = vector;
}

