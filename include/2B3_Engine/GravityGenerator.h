//
// Created by Vince on 20/09/2018.
//

#ifndef GAMEENGINE_GRAVITYGENERATOR_H
#define GAMEENGINE_GRAVITYGENERATOR_H


#include "ParticleForceGenerator.h"

///Classe GravityGenerator
    ///Classe qui permet la génération de forces de gravité
class GravityGenerator : public ParticleForceGenerator {
    ///Attributs
protected:
    Vector3D* gravity;

public:
    ///Constructeur par défaut
    GravityGenerator();

    ///Destructeur
    ~GravityGenerator();

    ///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de gravité
    void UpdateForce(Particle *particle, float frame_duration) override;

    ///Getters-Setters ---------------------
    Vector3D *getGravity() const;

    void setGravity(Vector3D *gravity);
    ///-------------------------------------
};


#endif //GAMEENGINE_GRAVITYGENERATOR_H
