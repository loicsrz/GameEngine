//
// Created by vince on 05/12/2018.
//

#ifndef GAMEENGINE_BSP_H
#define GAMEENGINE_BSP_H


#include <ostream>
#include "Plane.h"

class BSPNode {
public:
    BSPNode(Plane *plane, Plane *collider, BSPNode *front, BSPNode *back);

    virtual ~BSPNode();

    void toString();

    Plane *getPlane();

    void setPlane(Plane *plane);

    BSPNode *getFront();

    void setFront(BSPNode *front);

    BSPNode *getBack();

    void setBack(BSPNode *back);

    Plane *getCollider();

    void setCollider(Plane *collider);

    void toString();

private:

    Plane* plane;
    Plane* collider;
    BSPNode* front;
    BSPNode* back;


};


#endif //GAMEENGINE_BSP_H
