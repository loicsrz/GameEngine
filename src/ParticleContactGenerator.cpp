//
// Created by loicsrz on 17/10/2018.
//
#include <math.h>
#include "../include/2B3_Engine/ParticleContactGenerator.h"


void ParticleContactGenerator::addContact(World world) {

    vector<Particle*>::iterator iterator;
    vector<Particle*>::iterator iterator1;

    for (iterator = world.getWorldParticles().begin(); iterator != world.getWorldParticles().end(); iterator++) {

        if ((*iterator)->getPosition()->getX() < world.getGroundX()[0]) {

            if ((*iterator)->getPosition()->getY() < world.getGroundY()[0]) {
                (*iterator)->getPosition()->setY(world.getGroundY()[0] + (*iterator)->getRadius());

            }
        } else if ((*iterator)->getPosition()->getX() < world.getGroundX()[1]) {

            if ((*iterator)->getPosition()->getY() < world.getGroundY()[1]) {
                (*iterator)->getPosition()->setY(world.getGroundY()[1] + (*iterator)->getRadius());
            }
        } else {
            if ((*iterator)->getPosition()->getY() < world.getGroundX()[2]) {
                (*iterator)->getPosition()->setY(world.getGroundY()[2] + (*iterator)->getRadius());
            }
        }
    }

    for (iterator = world.getWorldParticles().begin();iterator != world.getWorldParticles().end(); iterator++){

        for (iterator1 = world.getWorldParticles().begin();iterator1 != world.getWorldParticles().end(); iterator1++){

            float distance = sqrt(pow(((*iterator)->getPosition()->getX()-(*iterator1)->getPosition()->getX()), 2)
                    + pow(((*iterator)->getPosition()->getY()-(*iterator1)->getPosition()->getY()), 2));
            if (distance < (*iterator)->getRadius()+(*iterator1)->getRadius()){
                Vector3D* perpendicularAngle = (*iterator)->getPosition()->substractVector((*iterator1)->getPosition())
                        ->normalizeVector();
                float penetration = (*iterator)->getRadius() + (*iterator1)->getRadius() - distance;
                Particle* pParticle[2] = {(*iterator),(*iterator1)};
                ParticleContact *particleContact1 = new ParticleContact(pParticle, 0.75,perpendicularAngle, penetration );
                particleContact.push_back(particleContact1);
            }
        }



        }

}

