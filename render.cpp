#include <cstdio>

#include <GL/gl.h>
#include <GL/glut.h>



void draw();
void setup();



float x_pos_old;
float delta_x;
float y_pos_old;
float delta_y;
float pix2angle;
float theta_x=20;
float theta_y=-20;

bool rotXl=false;
bool rotXr=false;

bool rotYl=false;
bool rotYr=false;

bool rotZl=false;
bool rotZr=false;

bool leftButton = false;

void resetKeys(){
    rotXl=false;
    rotXr=false;

    rotYl=false;
    rotYr=false;

    rotZl=false;
    rotZr=false;
}

void RenderScene(void);

void Mouse(int btn, int state, int x, int y)
{    
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)        
    {
        x_pos_old=x;
        y_pos_old=y;
        leftButton=true;
    }
    else if(btn==GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        leftButton=false;
    }   
}
void Keyboard(unsigned char key,int x, int y)
{

    switch (key)
    {
        case 'z':
            rotXl=true;
            break;
        case 'x':
            rotXr=true;
            break;
        case 'a':
            rotYl=true;
            break;
        case 's':
            rotYr=true;
            break;
        case 'q':
            rotZl=true;
            break;
        case 'w':
            rotZr=true;
            break;
    
        default:
            break;
    }

    RenderScene();
}

void Motion( GLsizei x, GLsizei y )
{    
    delta_x=x-x_pos_old;     // obliczenie różnicy położenia kursora myszy
    delta_y=y-y_pos_old;
    x_pos_old=x;            // podstawienie bieżącego położenia jako poprzednie
    y_pos_old=y;
    glutPostRedisplay();     // przerysowanie obrazu sceny
}


void RenderScene(void)
{
    if(leftButton) {
        theta_x += delta_x*pix2angle;
        theta_y += delta_y*pix2angle;
    }
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Czyszczenie okna aktualnym kolorem czyszczącym
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();// Czyszczenie macierzy bieżącej

    glRotatef(theta_x, 0.0, 1.0, 0.0); 
    glRotatef(theta_y, 1.0, 0.0, 0.0);     
    
    draw();

    glFlush();// Przekazanie poleceń rysujących do wykonania    
    glutSwapBuffers();
}

void ChangeSize(GLsizei horizontal, GLsizei vertical )
{
    pix2angle = 360.0/(float)horizontal;
    GLfloat AspectRatio;
    if(vertical == 0)
    vertical = 1;  
    glViewport(0, 0, horizontal, vertical);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();        
    AspectRatio = (GLfloat)horizontal/(GLfloat)vertical;      
    if(horizontal <= vertical)
    glOrtho(-7.5,7.5,-7.5/AspectRatio,7.5/AspectRatio,10.0, -10.0); 
    else
    glOrtho(-7.5*AspectRatio,7.5*AspectRatio,-7.5,7.5,10.0,-10.0);                     
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Idle()
{
    glutPostRedisplay();
}

int init(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Rubik cube");
    glutIdleFunc(Idle);

    glutMouseFunc(Mouse);  
    glutKeyboardFunc(Keyboard);  
    glutMotionFunc(Motion);                
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);  
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    setup();
    glutMainLoop();    
    return 0;
}

