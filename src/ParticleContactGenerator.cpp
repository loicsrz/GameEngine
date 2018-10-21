//
// Created by loicsrz on 17/10/2018.
//

#include "../include/2B3_Engine/ParticleContactGenerator.h"


void ParticleContactGenerator::addContact(vector<Particle*> allparticle, World world) {

    vector<Particle*>::iterator iterator;
    vector<Particle*>::iterator iterator1;

    for (iterator = allparticle.begin(); iterator != allparticle.end(); iterator++) {

        if ((*iterator)->getPosition()->getX() < world.getGroundX()[0]){

            if ((*iterator)->getPosition()->getY() < world.getGroundY()[0]){
                // TODO : add contact
            }
        }
        else if ((*iterator)->getPosition()->getX() < world.getGroundX()[1]){

            if ((*iterator)->getPosition()->getY() < world.getGroundY()[1]){
                // TODO : addcontact
            }
        }
        else {
            if ((*iterator)->getPosition()->getY() < world.getGroundX()[2]){
                // TODO : addcontact
            }
        }

        for (iterator1 = allparticle.begin();iterator1 != allparticle.end(); iterator1++){

            if ((*iterator)->getPosition() == (*iterator1)->getPosition()){
                // TODO : addcontact
            }
        }

    }
}

