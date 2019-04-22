#pragma once
#include "Matrix.h"

class Cubie
{    
    float faceSize;
    float angle_x=0;
    float angle_y=0;
    float angle_z=0;

    Matrix& mat;


public:
    float x,y,z;
    Cubie(float x, float y, float z, float faceSize);
    void display();
    void setPosition(float,float,float);
    void rotate(float,float,float);
};