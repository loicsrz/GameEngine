//
// Created by vince on 05/12/2018.
//

#include "../include/2B3_Engine/BSPNode.h"

/// Contructeur
BSPNode::BSPNode(Plane *plane, Plane *collider, BSPNode *front, BSPNode *back) : plane(plane), collider(collider),
                                                                                 front(front), back(back) {}

BSPNode::~BSPNode() {
    delete plane;
    delete front;
    delete back;
}

/// Getters - Setters ----------------------------------------------------------------------------------------------
Plane *BSPNode::getPlane() {
    return plane;
}

void BSPNode::setPlane(Plane *plane) {
    BSPNode::plane = plane;
}

BSPNode *BSPNode::getFront() {
    return front;
}

void BSPNode::setFront(BSPNode *front) {
    BSPNode::front = front;
}

BSPNode *BSPNode::getBack() {
    return back;
}

void BSPNode::setBack(BSPNode *back) {
    BSPNode::back = back;
}

Plane *BSPNode::getCollider() {
    return collider;
}

void BSPNode::setCollider(Plane *collider) {
    BSPNode::collider = collider;
}



