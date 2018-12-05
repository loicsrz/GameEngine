//
// Created by vince on 05/12/2018.
//

#ifndef GAMEENGINE_PRIMITIVE_H
#define GAMEENGINE_PRIMITIVE_H


#include "RigidBody.h"

class Primitive {
public:
    RigidBody *getBody() const;

    void setBody(RigidBody *body);

    Matrix4 *getOffset() const;

    void setOffset(Matrix4 *offset);

private:
    RigidBody* body;
    Matrix4* offset;
};


#endif //GAMEENGINE_PRIMITIVE_H
