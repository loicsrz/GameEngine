//
// Created by vince on 05/12/2018.
//

#ifndef GAMEENGINE_BSP_H
#define GAMEENGINE_BSP_H


#include <ostream>
#include "Plane.h"

class BSPNode {

private:
    ///Attributs

    ///Plan
    Plane* plane;

    ///Collider
    Plane* collider;

    /// Noeud du haut
    BSPNode* front;

    ///Noeud du bas
    BSPNode* back;


public:

    ///Constructeur
    BSPNode(Plane *plane, Plane *collider, BSPNode *front, BSPNode *back);

    ///Destructeur
    virtual ~BSPNode();

 /// Getters - Setters ----------------------------------------------------------------------------------------------
    Plane *getPlane();

    void setPlane(Plane *plane);

    BSPNode *getFront();

    void setFront(BSPNode *front);

    BSPNode *getBack();

    void setBack(BSPNode *back);

    Plane *getCollider();

    void setCollider(Plane *collider);




};


#endif //GAMEENGINE_BSP_H
