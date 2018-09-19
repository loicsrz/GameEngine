//
// Created by Thomas on 19/09/2018.
//

#ifndef GAMEENGINE_DRAGGENERATOR_H
#define GAMEENGINE_DRAGGENERATOR_H


#include "ParticleForceGenerator.h"

class DragGenerator : ParticleForceGenerator {
    ///Attributs
protected:
    float k1;
    float k2;

public:
    DragGenerator();
    ~DragGenerator();

    void UpdateForce(Particle *particule, float frame_duration) override;

    float getK1() const;

    void setK1(float k1);

    float getK2() const;

    void setK2(float k2);
};


#endif //GAMEENGINE_DRAGGENERATOR_H
