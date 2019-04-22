#include "Cubie.h"
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <Windows.h>
#endif // WINDOWS
#include <GL/gl.h>
#include <GL/glut.h>

#include <cmath>

#include <cstdio>


Cubie::Cubie(float x, float y, float z,float faceSize):x(x),y(y),z(z),faceSize(faceSize),mat(*new Matrix)
{
    mat.loadIdentity();  
}
void Cubie::setPosition(float x,float y,float z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}
void Cubie::rotate(float x,float y,float z)
{   
    angle_x+=x;
    angle_y+=y;
    angle_z+=z;

    mat.rotateX(x);
    mat.rotateY(y);
    mat.rotateZ(z);
}


void Cubie::display()
{
    float halfSize = faceSize/2;

    glPushMatrix();
    glTranslated(x,y,z);    
    glMultMatrixf(mat.transposed().getData());
    
    glBegin(GL_TRIANGLES);
    // back face
    glColor3f(0,0,1);
    glVertex3f(-halfSize,-halfSize,+halfSize);
    glVertex3f(-halfSize,+halfSize,+halfSize);
    glVertex3f(+halfSize,+halfSize,+halfSize);    

    glVertex3f(-halfSize,-halfSize,+halfSize);
    glVertex3f(+halfSize,-halfSize,+halfSize);
    glVertex3f(+halfSize,+halfSize,+halfSize);

    // front face
    glColor3f(0,1,0);
    glVertex3f(-halfSize,-halfSize,-halfSize);
    glVertex3f(-halfSize,+halfSize,-halfSize);
    glVertex3f(+halfSize,+halfSize,-halfSize);    

    glVertex3f(-halfSize,-halfSize,-halfSize);
    glVertex3f(+halfSize,-halfSize,-halfSize);
    glVertex3f(+halfSize,+halfSize,-halfSize);

    // right face
    glColor3f(1,0,0);
    glVertex3f(+halfSize,-halfSize,-halfSize);
    glVertex3f(+halfSize,-halfSize,+halfSize);
    glVertex3f(+halfSize,+halfSize,+halfSize);    

    glVertex3f(+halfSize,-halfSize,-halfSize);
    glVertex3f(+halfSize,+halfSize,-halfSize);
    glVertex3f(halfSize,+halfSize,+halfSize);

    // left face
    glColor3f(1,0.65,0);
    glVertex3f(-halfSize,-halfSize,-halfSize);
    glVertex3f(-halfSize,-halfSize,+halfSize);
    glVertex3f(-halfSize,+halfSize,+halfSize);    

    glVertex3f(-halfSize,-halfSize,-halfSize);
    glVertex3f(-halfSize,+halfSize,-halfSize);
    glVertex3f(-halfSize,+halfSize,+halfSize);

    // top face
    glColor3f(1,1,1);
    glVertex3f(-halfSize,+halfSize,-halfSize);
    glVertex3f(-halfSize,+halfSize,+halfSize);
    glVertex3f(halfSize,+halfSize,+halfSize);    

    glVertex3f(-halfSize,+halfSize,-halfSize);
    glVertex3f(halfSize,+halfSize,-halfSize);
    glVertex3f(halfSize,+halfSize,+halfSize);

    // bottom face
    glColor3f(1,1,0);
    glVertex3f(-halfSize,-halfSize,-halfSize);
    glVertex3f(-halfSize,-halfSize,+halfSize);
    glVertex3f(halfSize,-halfSize,+halfSize);    

    glVertex3f(-halfSize,-halfSize,-halfSize);
    glVertex3f(halfSize,-halfSize,-halfSize);
    glVertex3f(halfSize,-halfSize,+halfSize);

    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(-halfSize,-halfSize,+halfSize);
    glVertex3f(-halfSize,+halfSize,+halfSize);
    glVertex3f(halfSize,+halfSize,+halfSize);
    glVertex3f(halfSize,-halfSize,+halfSize);
    glVertex3f(-halfSize,-halfSize,+halfSize);
    glVertex3f(-halfSize,-halfSize,-halfSize);
    glVertex3f(-halfSize,+halfSize,-halfSize);
    glVertex3f(halfSize,+halfSize,-halfSize);
    glVertex3f(halfSize,-halfSize,-halfSize);
    glVertex3f(-halfSize,-halfSize,-halfSize);

    glVertex3f(halfSize,-halfSize,-halfSize);
    glVertex3f(halfSize,-halfSize,+halfSize);
    glVertex3f(-halfSize,-halfSize,+halfSize);
    glVertex3f(-halfSize,-halfSize,-halfSize);

    glVertex3f(-halfSize,+halfSize,-halfSize);
    glVertex3f(-halfSize,+halfSize,+halfSize);
    glVertex3f(halfSize,+halfSize,+halfSize);
    glVertex3f(halfSize,+halfSize,-halfSize);

    glEnd();

    glPopMatrix();
}