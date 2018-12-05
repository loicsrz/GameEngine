//
// Created by vince on 05/12/2018.
//

#ifndef GAMEENGINE_PRIMITIVE_H
#define GAMEENGINE_PRIMITIVE_H


#include "RigidBody.h"

class Primitive {
public:
    Primitive(RigidBody *body, Matrix4 *offset);

    RigidBody *getBody() const;

    void setBody(RigidBody *body);

    Matrix4 *getOffset() const;

    void setOffset(Matrix4 *offset);

    virtual ~Primitive();

private:
    RigidBody* body;
    Matrix4* offset;
};


#endif //GAMEENGINE_PRIMITIVE_H
