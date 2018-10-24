//
// Created by totoa on 26/09/2018.
//

#ifndef GAMEENGINE_PARTICLEFLOATING_H
#define GAMEENGINE_PARTICLEFLOATING_H


#include "ParticleForceGenerator.h"
#include<iostream>

///Classe ParticleFloating
    ///Classe qui permet la génération de forces de types flottaison
class ParticleFloating : public ParticleForceGenerator {
protected:
    float depth;
    float volume;
    float liquidLevel;
    float liquidDensity;

public:
    ///Constructeur par défaut
    ParticleFloating();

    ///Destructeur
    virtual ~ParticleFloating();

    ///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de type flottaison
    void UpdateForce(Particle *particle, float frame_duration) override;

    ///Getters - Setters ------------------------------------
    float getDepth() const;

    void setDepth(float depth);

    float getVolume() const;

    void setVolume(float volume);

    float getLiquidLevel() const;

    void setLiquidLevel(float liquidLevel);

    float getLiquidDensity() const;

    void setLiquidDensity(float liquidDensity);
    ///-------------------------------------------------------
};


#endif //GAMEENGINE_PARTICLEFLOATING_H
