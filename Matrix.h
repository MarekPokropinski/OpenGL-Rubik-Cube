#include <vector>
using namespace std;



class Matrix
{
    vector<float> data;

public:
    Matrix();
    Matrix(float[]);

    void display();

    void loadIdentity();

    Matrix mul(Matrix&);
    void transpose();
    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);

    void rotate90X();
    void rotate90Y();
    void rotate90Z();

    Matrix transposed();

    float* getData();

};