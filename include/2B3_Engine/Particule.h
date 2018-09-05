//
// Created by Vince on 29/08/2018.
//

#ifndef GAMEENGINE_PARTICULE_H
#define GAMEENGINE_PARTICULE_H


class Particule {
public:
    Particule(float position, float velocite, float inverseMasse);

protected:
    // Position.
    float position;
    // Vélocité.
    float velocite;
    // Accélération.
    float acceleration;
    //
    float inverseMasse;

public:
    // Méthode visant à calculer la position et la vitesse de la prochaine frame.
    void integrer (float temps);

    // Début de l'ensemble des getters et setters de la classe Particule.
    float getInverseMasse() const;

    void setInverseMasse(float inverseMasse);

    float getMasse() const;

    void setMasse(float Masse);
    // Fin de l'ensemble des getters et setters de la classe Particule.

};


#endif //GAMEENGINE_PARTICULE_H