//
// Created by Vince on 29/08/2018.
//

#ifndef GAMEENGINE_PARTICULE_H
#define GAMEENGINE_PARTICULE_H


class Particule {
protected:
    float pos;
    float vel;
    float acc;
    float inverseMasse;

public:
    void integrer (float temps);

    float getInverseMasse() const;

    void setInverseMasse(float inverseMasse);
};


#endif //GAMEENGINE_PARTICULE_H