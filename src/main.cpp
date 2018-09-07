//
// Created by Vince on 29/08/2018.
//
#include<iostream>
#include <vector>
#include <GL/glut.h>
#include "../include/2B3_Engine/Particule.h"

using namespace std;

GLint gImagesParSeconde = 0;
GLfloat dt = 0.0;
Particule *particule;
vector<Particule *> particules;

void Rendu() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //cout << "IPS : " << gImagesParSeconde << "\r\n";

    glPointSize(5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex3f(particule->getPosition()->getX(), particule->getPosition()->getY(), particule->getPosition()->getZ());
    glEnd();

    glutSwapBuffers();
}

void Clavier(unsigned char c) {
    if (c == 'x') //Appuyer sur la touche x permet de quitter l'application
    {
        exit(0);
    }
}

void IPS() {
    static GLint Images = 0;         // Moyenne des images sur 1000ms
    static GLuint Horloge;
    static GLuint ProchaineHorloge = 0;

    ++Images;
    Horloge = static_cast<GLuint>(glutGet(GLUT_ELAPSED_TIME));
    if (Horloge < ProchaineHorloge) return;

    ProchaineHorloge = Horloge + 1000; // 1000mS=1S dans le futur
    Images = 0;
}

void integrateur(vector<Particule *> particules, float deltaTemps) {

//    int n = 1;
    for (auto it = particules.begin(); it != particules.end(); ++it) {
        /*cout << "Particule " << n << " :" << endl;
        cout << "Avant Integration : " << endl;
        cout << "Position : " << endl;
        cout << '\t' << "x : " << (*it)->getPosition()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getPosition()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getPosition()->getZ() << endl;
        cout << "Velocite : " << endl;
        cout << '\t' << "x : " << (*it)->getVelocite()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getVelocite()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getVelocite()->getZ() << endl;
        cout << "Acceleration : " << endl;
        cout << '\t' << "x : " << (*it)->getAcceleration()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getAcceleration()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getAcceleration()->getZ() << endl;*/
        (*it)->integrateur(deltaTemps);
        /*cout << "Après Integration : " << endl;
        cout << "Position : " << endl;
        cout << '\t' << "x : " << (*it)->getPosition()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getPosition()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getPosition()->getZ() << endl;
        cout << "Velocite : " << endl;
        cout << '\t' << "x : " << (*it)->getVelocite()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getVelocite()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getVelocite()->getZ() << endl;
        cout << "Acceleration : " << endl;
        cout << '\t' << "x : " << (*it)->getAcceleration()->getX() << endl;
        cout << '\t' << "y : " << (*it)->getAcceleration()->getY() << endl;
        cout << '\t' << "z : " << (*it)->getAcceleration()->getZ() << endl;
        cout << endl;
        n++;*/
    }
}

void timer(int value) {
    const int IPSvoulus = 60;
    glutTimerFunc(1000 / IPSvoulus, timer, ++value);
    dt = static_cast<float>(gImagesParSeconde > 0 ? 1.0 / static_cast<float>(gImagesParSeconde) : 1.0);

    // Emplacements des calculs à réaliser
    integrateur(particules, dt);
    //particule->setPosition(new Vecteur3D(particule->getPosition()->getX()+0.01,particule->getPosition()->getY(), particule->getPosition()->getZ()));

    IPS(); // Appelé une fois par calcul d'image pour afficher le nombre d'IPS
    glutPostRedisplay(); // Lance un appel à Rendu() au taux d'IPS voulu
}

void glutDisplayInit(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(640, 240);
    glutCreateWindow("2Be3_Engine");
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(Rendu);
    glutKeyboardFunc(Clavier);
    glutMainLoop();
}

int main(int argc, char **argv) {
    particule = new Particule(new Vecteur3D(static_cast<float>(-0.99), 0.0, 0.0), new Vecteur3D(0.03, 0, 0),
                              new Vecteur3D(0.0, 0.0001f, 0.0), 2, 0.99);
    particules.push_back(particule);
    glutDisplayInit(argc, argv);
    return 0;
}