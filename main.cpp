#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <Windows.h>
#endif // WINDOWS
#include <GL/gl.h>
#include <GL/glut.h>

#include "render.h"

#include "Cubie.h"
#include "cube.h"
#include "move.h"

#include <cstdio>
#include <vector>
#include <cstdlib>


using namespace std;

vector<Move> moves;
auto currentMove = moves.begin();

Cube cube;

int main(int argc, char**argv)
{
    init(argc,argv);
}
void draw() {
    if(currentMove!=moves.end())
    {
        Move& move = (*currentMove);
        if(!(*currentMove).update())
        {
            if(move.x!=0)
            {
                cube.rotateX(move.x,move.dir);              
            }
            if(move.y!=0)
            {
                cube.rotateY(move.y,move.dir);  
            }
            if(move.z!=0)
            {
                cube.rotateZ(move.z,move.dir);
            }
            ++currentMove;
            if(currentMove!=moves.end())
            {
                cube.setMove(&*currentMove);
            }
            else
            {
                cube.setMove(nullptr);
            }            
        }
    }
    
    cube.display();
}

void setup() {
    Move::setSpeed(10);
    for(int i=0;i<100;i++)
    {
        int a=0,b=0,c=0,d=0;
        int val = rand()%2?-1:1;
        d = rand()%2?-1:1;
        switch (rand()%3)
        {
            case 0:
                a=val;
                break;
            case 1:
                b=val;
                break;
            case 2:
                c=val;
                break;
        }        
        moves.push_back(Move(a,b,c,d));
    }
    moves.push_back(Move(1,0,0,1));
    moves.push_back(Move(0,1,0,1));
    moves.push_back(Move(0,0,1,1));
    currentMove = moves.begin();
    cube.setMove(&*currentMove);
}