//
// Created by loicsrz on 26/09/2018.
//

#ifndef GAMEENGINE_ANCHOREDPARTICLE_H
#define GAMEENGINE_ANCHOREDPARTICLE_H


#include "ParticleForceGenerator.h"

/// Classe ParticleAnchoredSpring
    /// Classe qui permet la génération de forces de ressorts ancrés
class ParticleAnchoredSpring : public ParticleForceGenerator  {

protected:
    Vector3D* anchoredPoint;
    float K;
    float l0;

public:
    ///Constructeur par défaut
    ParticleAnchoredSpring();

    ///Destructeur
    ~ParticleAnchoredSpring();

    ///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de gravité
    void UpdateForce(Particle *particle, float frame_duration) override;

    ///Getters - Setters ------------------------------
    Vector3D *getAnchoredPoint() const;

    void setAnchoredPoint(Vector3D *anchoredPoint);

    float getK() const;

    void setK(float K);

    float getL0() const;

    void setL0(float l0);
    ///------------------------------------------------
};



#endif //GAMEENGINE_ANCHOREDPARTICLE_H
