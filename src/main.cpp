//
// Created by Vince on 29/08/2018.
//
#include<iostream>
#include <GL/glut.h>
#include "../include/2B3_Engine/Particule.h"

using namespace std;

GLint gImagesParSeconde = 0;
GLfloat dt = 0.0;
Particule *particule = new Particule();


void Rendu()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    cout << "IPS : " << gImagesParSeconde << "\r\n";

    glPointSize(5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
        glVertex3f(particule->getPosition()->getX(), particule->getPosition()->getY(), particule->getPosition()->getZ());
    glEnd();

    glutSwapBuffers();
}

void Clavier(unsigned char c, int x, int y)
{
    if (c == 'x') //Appuyer sur la touche x permet de quitter l'application
    {
        exit(0);
    }
}

void IPS(void)
{
    static GLint Images = 0;         // frames averaged over 1000mS
    static GLuint Horloge;             // [milliSeconds]
    static GLuint ProchaineHorloge = 0;     // [milliSeconds]

    ++Images;
    Horloge = static_cast<GLuint>(glutGet(GLUT_ELAPSED_TIME)); //has limited resolution, so average over 1000mS
    if ( Horloge < ProchaineHorloge ) return;

    gImagesParSeconde = Images/1; // store the averaged number of frames per second

    ProchaineHorloge = Horloge+1000; // 1000mS=1S in the future
    Images=0;
}

void timer(int value)
{
    const int IPSvoulus=60;
    glutTimerFunc(1000/IPSvoulus, timer, ++value);
    dt = static_cast<GLfloat>(gImagesParSeconde > 0 ? 1.0 / gImagesParSeconde : 1.0);

    // DO STUFF HERE
    //particule->setPosition(new Vecteur3D(particule->getPosition()->getX()+0.01,particule->getPosition()->getY(), particule->getPosition()->getZ()));

    IPS(); //only call once per frame loop to measure IPS
    glutPostRedisplay(); // initiate display() call at IPSvoulus rate
}

void glutDisplayInit(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(640, 240);
    glutCreateWindow("2Be3_Engine");
    glutTimerFunc(0,timer,0);
    glutDisplayFunc(Rendu);
    glutKeyboardFunc(Clavier);
    glutMainLoop();
}

int main(int argc, char** argv)
{
    particule->setPosition(new Vecteur3D(static_cast<float>(-0.99), 0.0, 0.0));
    glutDisplayInit(argc, argv);
    return 0;
}