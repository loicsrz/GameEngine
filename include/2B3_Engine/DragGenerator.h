//
// Created by Thomas on 19/09/2018.
//

#ifndef GAMEENGINE_DRAGGENERATOR_H
#define GAMEENGINE_DRAGGENERATOR_H


#include "ParticleForceGenerator.h"

///Classe DragGenerator
    ///Classe qui permet la génération de forces de types Drag
class DragGenerator : public ParticleForceGenerator {
    ///Attributs
protected:
    float k1;
    float k2;

public:
    ///Constructeur par défaut
    DragGenerator();

    ///Destructeur
    ~DragGenerator();

    ///Méthode de mise à jour de la force accumulée par la Particle particle en ajoutant une force de type draging
    void UpdateForce(Particle *particle, float frame_duration) override;

    ///Getters-Setters ------
    float getK1() const;

    void setK1(float k1);

    float getK2() const;

    void setK2(float k2);
    ///----------------------
};


#endif //GAMEENGINE_DRAGGENERATOR_H
