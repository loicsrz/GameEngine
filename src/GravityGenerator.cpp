//
// Created by Vince on 20/09/2018.
//

#include "../include/2B3_Engine/GravityGenerator.h"
#include <iostream>
using namespace std;
GravityGenerator::GravityGenerator() {

}

GravityGenerator::~GravityGenerator() {

}

void GravityGenerator::UpdateForce(Particle *particle, float frame_duration) {
    cout<<"UpdateForce gravity"<<endl;
    if(particle->getMass()==0) return;
//    cout<<gravity->getY()<<endl;
//    cout<<"Particle Y before : "<<particle->getForcesAccum()->getY()<<endl;
//    cout<<"particle mass : "<<particle->getMass()<<endl;
//    GravityGenerator * test = new GravityGenerator();
//    Vector3D * newGrav = new Vector3D(gravity->getX(),gravity->getY(),gravity->getZ());
//    test->setGravity(newGrav);
//    cout<<"Gravity Y applied: "<<test->getGravity()->scalarMultiplier(particle->getMass())->getY()<<endl;
    particle->addForce(gravity->scalarMultiplier(particle->getMass()));
//    cout<<"Particle Y after : "<<particle->getForcesAccum()->getY()<<endl;
}

Vector3D *GravityGenerator::getGravity() const {
    return gravity;
}

void GravityGenerator::setGravity(Vector3D *gravity) {
    GravityGenerator::gravity = gravity;
}

