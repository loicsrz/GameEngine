//
// Created by Vince on 17/10/2018.
//

#include "../include/2B3_Engine/ParticleContact.h"

///Constructeur de ParticleContact
ParticleContact::ParticleContact(Particle **mParticles, float restitution, Vector3D *perpendicularAngle,
                                 float penetration, bool isLink) : restitution(restitution),
                                                                   perpendicularAngle(perpendicularAngle),
                                                                   penetration(penetration),
                                                                   isLink(isLink){
    ParticleContact::particles[0]= mParticles[0];
    ParticleContact::particles[1]= mParticles[1];
}

///Destructeur
ParticleContact::~ParticleContact() {

}

/// Méthode de résolution du contact
void ParticleContact::Resolve(float duration) {
    InterpenetrationResolve(duration);
    ImpulsionResolve(duration);
}

/// Méthode de calcul de vS'
float ParticleContact::SpeedCompute() const {
    Particle* A = particles[0];
    Particle* B = particles[1];
    float vS = A->getVelocity()->substractVector(B->getVelocity())->scalarProduct(perpendicularAngle);
    return (- restitution * vS);
}

/// Méthode de résolution du contact nécessitant une impulsion pour la résolution
void ParticleContact::ImpulsionResolve(float duration) {
    Particle* A = particles[0];
    Particle* B = particles[1];
    float vS = SpeedCompute();
    if(isLink){
        vS = abs(vS);
    }
    Vector3D* velocity0 = perpendicularAngle->scalarMultiplier(vS);
    Vector3D* velocity1 = velocity0->scalarMultiplier(-1.0f);
    A->setVelocity(A->getVelocity()->addVector(velocity0->scalarMultiplier(A->getInvertedMass())));
    B->setVelocity(B->getVelocity()->addVector(velocity1->scalarMultiplier(B->getInvertedMass())));
}

/// Méthode de résolution du contact relatif à l'interpénétration des Particles entre elles
void ParticleContact::InterpenetrationResolve(float duration) {
    Particle* A = particles[0];
    Particle* B = particles[1];
    Vector3D* deltaPosA = perpendicularAngle->scalarMultiplier((B->getMass() * penetration) / (A->getMass() + B->getMass()));
    Vector3D* deltaPosB = perpendicularAngle->scalarMultiplier(-1 * (A->getMass() * penetration) / (A->getMass() + B->getMass()));

    A->setPosition(A->getPosition()->addVector(deltaPosA));
    B->setPosition(B->getPosition()->addVector(deltaPosB));
}

///Getters-Setters ---------------------------------------------------------------------------------------------------
Particle *const *ParticleContact::getParticles() const {
    return particles;
}

float ParticleContact::getRestitution() const {
    return restitution;
}

void ParticleContact::setRestitution(float restitution) {
    ParticleContact::restitution = restitution;
}

Vector3D *ParticleContact::getPerpendicularAngle() const {
    return perpendicularAngle;
}

void ParticleContact::setPerpendicularAngle(Vector3D *perpendicularAngle) {
    ParticleContact::perpendicularAngle = perpendicularAngle;
}

float ParticleContact::getPenetration() const {
    return penetration;
}

void ParticleContact::setPenetration(float penetration) {
    ParticleContact::penetration = penetration;
}
///-------------------------------------------------------------------------------------------------------------------

///Surcharge de l'opérateur de comparaison '<' pour effectuer un tri de ParticleContact
bool ParticleContact::operator<(ParticleContact const &b) {
    return this->SpeedCompute() < b.SpeedCompute();
}
