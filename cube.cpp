#include "cube.h"

#include <GL/gl.h>
#include <GL/glut.h>

#include <cstdlib>
#include <cstdio>

constexpr float PI = 3.14;

static const float eps = 0.1;

bool almostEqual(float a, float b)
{
    return a<b+eps && a > b-eps;
}

Cube::Cube()
{
    /**
     * Set cube initial state
    */
    for(int x=-dim/2;x<(dim+1)/2;x++)
    for(int y=-dim/2;y<(dim+1)/2;y++)
    for(int z=-dim/2;z<(dim+1)/2;z++)
        cubies.push_back(Cubie(x*faceSize,y*faceSize,z*faceSize,faceSize));
}

void Cube::display()
{      
    for(auto&cubie : cubies)
    {
        glPushMatrix();
        if(move!=nullptr&&!move->isFinished())
        {          
            if((*move).x!=0&&almostEqual(cubie.x,(*move).x*faceSize))
            {
                glRotated(move->angle,1,0,0);
            }
            if((*move).y!=0&&almostEqual(cubie.y,(*move).y*faceSize))
            {
                glRotated(move->angle,0,1,0);
            }
            if((*move).z!=0&&almostEqual(cubie.z,(*move).z*faceSize))
            {
                glRotated(move->angle,0,0,1);
            }
        }        
        cubie.display();
        glPopMatrix();
    }
}
void Cube::rotateX(int index, int dir)
{
    for(auto& cubie : cubies)
    {
        if(almostEqual(index*faceSize,cubie.x))
        {
            cubie.setPosition(
                cubie.x,
                -dir*cubie.z,
                dir*cubie.y
            );
            cubie.rotate(dir*90,0,0);
        }
    }
}
void Cube::rotateY(int index, int dir)
{
    for(auto& cubie : cubies)
    {        
        if(almostEqual(index*faceSize,cubie.y))
        {
            cubie.setPosition(
                dir*cubie.z,
                cubie.y,
                -dir*cubie.x
            );
            cubie.rotate(0,dir*90,0);
        }
    }
}
void Cube::rotateZ(int index, int dir)
{
    for(auto& cubie : cubies)
    {        
        if(almostEqual(index*faceSize,cubie.z))
        {
            cubie.setPosition(
                -dir*cubie.y,
                dir*cubie.x,
                cubie.z
            );
            cubie.rotate(0,0,dir*90);
        }
    }
}

void Cube::shuffle()
{
    for(int i=0;i<20;i++){
        int index = rand()%2==0?0:2;
        int dir = rand()%2==0?-1:1;
        switch (rand()%3)
        {
            case 0:
                rotateX(index,dir);
                break;
            case 1:
                rotateY(index,dir);
                break;
            case 2:
                rotateZ(index,dir);
                break;
        
            default:
                break;
        }
    }    
}
void Cube::setMove(Move* m)
{
    move =m;
}