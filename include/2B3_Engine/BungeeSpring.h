//
// Created by totoa on 26/09/2018.
//

#ifndef GAMEENGINE_BUNGEESPRING_H
#define GAMEENGINE_BUNGEESPRING_H


#include "ParticleForceGenerator.h"

///Classe BungeeSpring
    ///Classe qui permet la génération de forces de types Bungee
class BungeeSpring : public ParticleForceGenerator {

protected:
    Particle* secondParticle;
    float K;
    float L0;

public:
    ///Constructeur par défaut
    BungeeSpring();

    ///Destructeur
    virtual ~BungeeSpring();

    ///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de ressort Bungee
    void UpdateForce(Particle *particle, float frame_duration) override;

    ///Getters-Setters ------------------------------------------
    Particle *getSecondParticle() const;

    void setSecondParticle(Particle *secondParticle);

    float getK() const;

    void setK(float K);

    float getL0() const;

    void setL0(float L0);
    ///----------------------------------------------------------
};


#endif //GAMEENGINE_BUNGEESPRING_H
