#include "Cubie.h"

#include <GL/gl.h>
#include <GL/glut.h>

Cubie::Cubie(float x, float y, float z,float faceSize):x(x),y(y),z(z),faceSize(faceSize)
{

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
}
void Cubie::display()
{
    float halfSize = faceSize/2;

    float m[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, m);

    glRotated(angle_x,1,0,0);
    glRotated(angle_y,0,1,0);
    glRotated(angle_z,0,0,1);

    glTranslated(x,y,z);
    
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

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(m);
}