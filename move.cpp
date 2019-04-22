#include "move.h"

#include <cmath>
#include <cstdio>

Move::Move(int x,int y, int z, int dir):x(x),y(y),z(z),dir(dir)
{
    angle=0;   
    animating=true; 
}
float Move::speed = 1;
void Move::setSpeed(float speed)
{
    Move::speed = speed;
}
bool Move::update()
{
    if(animating)
    {
        angle+=speed*dir;
        if(abs(angle)>=90){
            animating=false;
            angle=0;            
            return false;
        }
        return true;
    }
    else{
        return false;
    }
}
bool Move::isFinished()
{
    return !animating;
}