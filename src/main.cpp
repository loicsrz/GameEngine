//
// Created by Vince on 29/08/2018.
//

#define _USE_MATH_DEFINES

#include<iostream>
#include <vector>
#include <GL/glut.h>
#include <math.h>
#include "../include/2B3_Engine/Particle.h"
#include "../include/2B3_Engine/World.h"
#include "../include/2B3_Engine/WorldPhysics.h"

using namespace std;

GLint gFramesPerSecond = 0;
GLfloat dt = 0.0;
static const double inc = M_PI / 12;
static const double max = 2 * M_PI;
World world;
WorldPhysics physics;
bool isSceneLoaded;
bool runScenario;
Particle massCenter;
Particle Vertices [3];
int scene=0;

void displayChoice() {
    cout << "Please choose a scenario by pressing one of the following keys : " << endl;
    cout << '\t' << "Mouvement parabolique rotatif : [1]" << endl;
    cout << '\t' << "Contact planifié : [2]" << endl;
    cout << '\t' << "Sortie : [x]" << endl;
    cout << endl;
}

void render() {
    //cout<<"Entre dans Rendu : "<<endl;
    if (isSceneLoaded) {
        if(scene == 1)
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glMatrixMode(GL_PROJECTION);  //Je mets la matrice MODEL_VIEW en utilisation courante.
            glLoadIdentity();
            gluPerspective(45.0f, (float) 960 / (float) 960, 0.1f, 2000.0f);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslatef(-250.0f, 0.0f, -700.0f);

            glLineWidth(1.0f);
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_TRIANGLES);
            for (int i = 0; i < 3; ++i) {
                glVertex3f(world.getWorldRigidBodies()[0]->getBodyParticles()[i]->getPosition()->getX(), world.getWorldRigidBodies()[0]->getBodyParticles()[i]->getPosition()->getY(), 0.0f);
            }
            glEnd();

            glPointSize(5.0f);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POINTS);
                glVertex3f(world.getWorldRigidBodies()[0]->getMassCenter()->getPosition()->getX(),world.getWorldRigidBodies()[0]->getMassCenter()->getPosition()->getY(),0.0f);
            glEnd();

            glLineWidth(1.0f);
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_LINES);
            glVertex3f(-200.0f, world.getGrounds().front(),0.0f);
            glVertex3f(600.0f, world.getGrounds().front(),0.0f);
            glEnd();

            glutSwapBuffers();
        }

        //cout << "IPS : " << gImagesParSeconde << "\r\n";

        //glFlush();
        //cout<<"Fin de Rendu"<<endl;
        //cout<<endl;
    }
}

void keyboard(unsigned char c) {

    if (isSceneLoaded)
    {
        switch (c){
            case 'f':
                runScenario = true;
                break;
            case 'x':
                runScenario = false;
                isSceneLoaded = false;
                scene = 0;
                world.eraseWorld();
                physics.erasePhysics();
                displayChoice();
                break;
            default:
                break;
        }
    }
    else if(!isSceneLoaded){
        switch (c) {
            case '1':
                cout<<"World init for "<<endl;
                world.initWorld1();
                physics.initWorldPhysics1(world);
                cout<<"init finished"<<endl;
                isSceneLoaded = true;
                scene = 1;


                break;
            case '2':
                cout<<"init begin"<<endl;
                world.initWorld2();
                physics.initWorldPhysics2(world);
                isSceneLoaded = true;
                cout<<"init finished"<<endl;
                scene = 2;

                break;
            case 'x':
                exit(0);
            default:
                break;
        }
    }
}

void fps() {
    static GLint Frames = 0;         // Moyenne des images sur 1000ms
    static GLuint Clock;
    static GLuint NextClock = 0;

    ++Frames;
    Clock = static_cast<GLuint>(glutGet(GLUT_ELAPSED_TIME));
    if (Clock < NextClock) return;

    NextClock = Clock + 1000; // 1000mS=1S dans le futur
    Frames = 0;
}

void timer(int value) {
    const int FPSwanted = 60;
    glutTimerFunc(1000 / FPSwanted, timer, ++value);
    dt = static_cast<float>(gFramesPerSecond > 0 ? 1.0 / static_cast<float>(gFramesPerSecond) : 1.0);

    //Boucle de calculs physiques en cas de Scene de jeu chargée
    if(runScenario){
        // Application des forces et torques aux rigidBodies
        physics.applyForces(dt);
        physics.updateAllRigidBodiesAccum(world.getWorldRigidBodies());

        // Intégration
        physics.rigidBodyIntegrator(world.getWorldRigidBodies(),dt);

        // Réinitialisation des forces accumulées
        world.clearAccums();

        // Résolution de contacts avec le sol
//        physics.searchAndResolveContactsWithGround(world);

        // Résolution de contacts
//        physics.searchContacts(world);
//        if(!physics.getContacts().empty()){
//            physics.initFrameContactResolver(physics.getContacts().size());
//            physics.resolveContacts(dt);
//        }
//        while(physics.getContactResolver().getConsumedIterations()<physics.getContactResolver().getIterationsMax()){
//            physics.searchContacts(world);
//            if(!physics.getContacts().empty()){
//                physics.resolveContacts(dt);
//            }
//            else{
//                break;
//            }
//        }
    }

    fps(); // Appelé une fois par calcul d'image pour afficher le nombre d'IPS
    glutPostRedisplay(); // Lance un appel à Rendu() au taux d'IPS voulu
}

void glutDisplayInit(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(960, 960);
    glutInitWindowPosition(900, 0);
    glutCreateWindow("2Be3_Engine");
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

int main(int argc, char **argv) {
    isSceneLoaded=false;
    runScenario = false;

    displayChoice();
    glutDisplayInit(argc, argv);

    return 0;
}