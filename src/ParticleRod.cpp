//
// Created by loicsrz on 21/10/2018.
//

#include "../include/2B3_Engine/ParticleRod.h"
#include "../include/2B3_Engine/Vector3D.h"
#include "../include/2B3_Engine/ParticleContact.h"

void ParticleRod::addContact() {

    if (linkLength() >= maxLenght)
    {
        Vector3D* perpendicularAngle = (particle[0])->getPosition()->substractVector((particle[1])->getPosition())
                ->normalizeVector();
        float penetration = 0;
        ParticleContact *particleContact1 = new ParticleContact(particle, 0.5,perpendicularAngle, penetration );
        particleContact.push_back(particleContact1);
    }

}
