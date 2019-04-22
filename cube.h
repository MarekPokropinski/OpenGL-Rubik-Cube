#pragma once
#include <inttypes.h>
#include "Cubie.h"
#include <vector>
#include "move.h"
using std::vector;

class Cube
{
    static const int dim = 3;
    static constexpr float faceSize = 3.0f;
    bool isAnimating = false;

    Move* move=nullptr;

public:
    vector<Cubie> cubies;
    Cube();
    void display();
    void rotateX(int index, int dir);
    void rotateY(int index, int dir);
    void rotateZ(int index, int dir);

    void shuffle();

    void setMove(Move* m);
};