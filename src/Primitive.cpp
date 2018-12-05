//
// Created by vince on 05/12/2018.
//

#include "../include/2B3_Engine/Primitive.h"

Primitive::Primitive(RigidBody *body, Matrix4 *offset) : body(body), offset(offset) {}

Primitive::~Primitive() {
    delete body;
    delete offset;
}

RigidBody *Primitive::getBody() const {
    return body;
}

void Primitive::setBody(RigidBody *body) {
    Primitive::body = body;
}

Matrix4 *Primitive::getOffset() const {
    return offset;
}

void Primitive::setOffset(Matrix4 *offset) {
    Primitive::offset = offset;
}
