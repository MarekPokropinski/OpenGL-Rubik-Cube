#include "Matrix.h"
#include <cmath>
#include <cstdio>

Matrix::Matrix():data(16)
{
}
void Matrix::loadIdentity()
{
    data = vector<float>(16);
    for(int i=0;i<4;i++)
    {
        data[i+4*i]=1;
    }
}
void Matrix::display()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%f ",data[i*4+j]);
        }
        puts("");
    } 
    puts("");
}

Matrix::Matrix(float values[]):data(16)
{
    for(int i=0;i<16;i++){
        data[i]=values[i];
    }
}

Matrix Matrix::mul(Matrix& other)
{
    Matrix result;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            result.data[i*4+j] = 0;
            for(int k=0; k<4; k++){
                result.data[i*4+j] += data[i*4+k]*other.data[k*4+j];
            }
        }
    }
    return result;
}

void Matrix::transpose()
{
    float temp;
    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            temp = data[i*4+j];
            data[i*4+j] = data[j*4+i];
            data[j*4+i] = temp;
        }
    }
}
void Matrix::rotateX(float angle)
{
    angle = angle/180*3.141592653589793238;
    float rot[] = {
        1,0,0,0,
        0,cos(angle),-sin(angle),0,
        0,sin(angle),cos(angle),0,
        0,0,0,1
    };
    Matrix rotation(rot);
    *this=rotation.mul(*this);
}
void Matrix::rotateY(float angle)
{
    angle = angle/180*3.141592653589793238;
    float rot[] = {
        cos(angle),0,sin(angle),0,
        0,1,0,0,
        -sin(angle),0,cos(angle),0,
        0,0,0,1
    };
    Matrix rotationMatrix(rot);
    *this = rotationMatrix.mul(*this);    
}
void Matrix::rotateZ(float angle)
{
    angle = angle/180*3.141592653589793238;
    float rot[] = {
        cos(angle),-sin(angle),0,0,
        sin(angle),cos(angle),0,0,
        0,0,1,0,
        0,0,0,1
    };
    Matrix rotationMatrix(rot);
    *this = rotationMatrix.mul(*this);  
}

void Matrix::rotate90X()
{}
void Matrix::rotate90Y()
{}
void Matrix::rotate90Z()
{}

Matrix Matrix::transposed()
{
    Matrix t;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            t.data[i*4+j] = data[j*4+i];
        }
    }
    return t;
}

float* Matrix::getData()
{
    return data.data();
}