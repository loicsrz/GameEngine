//
// Created by vince on 05/12/2018.
//

#ifndef GAMEENGINE_BSP_H
#define GAMEENGINE_BSP_H


#include "Plane.h"

class BSPNode {
public:
    BSPNode(Plane *plane, BSPNode *front, BSPNode *back);

    virtual ~BSPNode();

    Plane *getPlane() const;

    void setPlane(Plane *plane);

    BSPNode *getFront() const;

    void setFront(BSPNode *front);

    BSPNode *getBack() const;

    void setBack(BSPNode *back);

private:

    Plane* plane;
    BSPNode* front;
    BSPNode* back;


};


#endif //GAMEENGINE_BSP_H
