#pragma once

class Move
{    
    bool animating = false;
    static float speed;
public:
    float angle;
    int dir;
    int x,y,z;
    Move(int x,int y, int z, int dir);
    bool update();
    bool isFinished();
    static void setSpeed(float);
};