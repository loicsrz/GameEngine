//
// Created by totoa on 28/11/2018.
//

#ifndef GAMEENGINE_BOX_H
#define GAMEENGINE_BOX_H


#include "Vector3D.h"

class Box {
protected:
    Vector3D * center;
    float semiWidth; //semiX
    float semiHeight; //semiY
    float semiDepth; //semiZ

public:
    Box(Vector3D *center, float semiWidth, float semiHeight, float semiDepth);

    virtual ~Box();

    vector<Vector3D*> getBoxVertices();

    Vector3D *getCenter() const;

    void setCenter(Vector3D *center);

    float getSemiWidth() const;

    void setSemiWidth(float semiWidth);

    float getSemiHeight() const;

    void setSemiHeight(float semiHeight);

    float getSemiDepth() const;

    void setSemiDepth(float semiDepth);
};


#endif //GAMEENGINE_BOX_H
