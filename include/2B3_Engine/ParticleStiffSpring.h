//
// Created by loicsrz on 17/10/2018.
//

#ifndef GAMEENGINE_PARTICLESTIFFSPRING_H
#define GAMEENGINE_PARTICLESTIFFSPRING_H


#include "ParticleForceGenerator.h"

///Classe ParticleStiffSpring
    ///Classe qui permet la génération de forces de types ressorts rigides
class ParticleStiffSpring : public ParticleForceGenerator {
protected:
    Vector3D* anchor;
    float K;
    float damping;

public:
    /// Constructeur par défaut
    ParticleStiffSpring();

    ///Destructeur
    virtual ~ParticleStiffSpring();

    ///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de ressort rigide
    void UpdateForce(Particle *particle, float frame_duration) override;

    ///Getters - Setters ----------------------------
    Vector3D* getAnchor() const;

    void setAnchor(Vector3D* anchor);

    float getK() const;

    void setK(float K);

    float getDamping() const;

    void setDamping(float damping);
    ///----------------------------------------------

};


#endif //GAMEENGINE_PARTICLESTIFFSPRING_H
