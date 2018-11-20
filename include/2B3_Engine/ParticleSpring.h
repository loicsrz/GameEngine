//
// Created by Vince on 26/09/2018.
//

#ifndef GAMEENGINE_PARTICLESPRING_H
#define GAMEENGINE_PARTICLESPRING_H


#include "ParticleForceGenerator.h"
#include "RigidBody.h"

///Classe ParticleSpring
    ///Classe qui permet la génération de forces de types ressorts classiques
class ParticleSpring : public ParticleForceGenerator {

protected:

    Particle * extremite1;
    RigidBody* AutreRigidBody;
    Particle * extremite2;
    float K;
    float l0;

public:
    ///Constructeur par défaut
    ParticleSpring();

    ///Destructeur
    ~ParticleSpring();

    ///Méthode de mise à jour de la force accumulée par le RigidBody en ajoutant une force de ressort classique
    void UpdateForce(RigidBody * rigidBody, float frame_duration);

    ///Getters - Setters ----------------------------------------
    Particle *getExtremite1() const;

    void setExtremite1(Particle *extremite1);

    RigidBody *getAutreRigidBody() const;

    void setAutreRigidBody(RigidBody *AutreRigidBody);

    Particle *getExtremite2() const;

    void setExtremite2(Particle *extremite2);

    float getK() const;

    void setK(float K);

    float getL0() const;

    void setL0(float l0);
    ///----------------------------------------------------------
};

#endif //GAMEENGINE_PARTICLESPRING_H
