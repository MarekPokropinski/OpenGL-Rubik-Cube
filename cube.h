#include <inttypes.h>
#include "Cubie.h"
#include <vector>
using std::vector;

class Cube
{
    static const int dim = 3;
    static constexpr float faceSize = 3.0f;
    vector<Cubie> cubies;

public:
    Cube();
    void display();
    void rotateX(int index, int dir);
    void rotateY(int index, int dir);
    void rotateZ(int index, int dir);
};