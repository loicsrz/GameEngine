//
// Created by vince on 05/12/2018.
//

#include "../include/2B3_Engine/BSPNode.h"

BSPNode::BSPNode(Plane *plane, BSPNode *front, BSPNode *back) : plane(plane), front(front), back(back) {}

BSPNode::~BSPNode() {
    delete plane;
    delete front;
    delete back;
}

Plane *BSPNode::getPlane() const {
    return plane;
}

void BSPNode::setPlane(Plane *plane) {
    BSPNode::plane = plane;
}

BSPNode *BSPNode::getFront() const {
    return front;
}

void BSPNode::setFront(BSPNode *front) {
    BSPNode::front = front;
}

BSPNode *BSPNode::getBack() const {
    return back;
}

void BSPNode::setBack(BSPNode *back) {
    BSPNode::back = back;
}
