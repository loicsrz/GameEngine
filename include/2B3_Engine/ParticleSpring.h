//
// Created by Vince on 26/09/2018.
//

#ifndef GAMEENGINE_PARTICLESPRING_H
#define GAMEENGINE_PARTICLESPRING_H


#include "ParticleForceGenerator.h"

///Classe ParticleSpring
    ///Classe qui permet la génération de forces de types ressorts classiques
class ParticleSpring : public ParticleForceGenerator {

protected:
Particle* secondParticle;
float K;
float l0;

public:
    ///Constructeur par défaut
    ParticleSpring();

    ///Destructeur
    ~ParticleSpring();

    ///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de ressort classique
    void UpdateForce(Particle *particle, float frame_duration) override;

    ///Getters - Setters ----------------------------------------
    Particle *getSecondParticle();

    void setSecondParticle(Particle *secondParticle);

    float getK() const;

    void setK(float K);

    float getL0() const;

    void setL0(float l0);
    ///----------------------------------------------------------
};

#endif //GAMEENGINE_PARTICLESPRING_H
