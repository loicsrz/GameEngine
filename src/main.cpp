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
bool isAnchored;
bool isWaterNeeded;

void displayChoice() {
    cout << "Please choose a scenario by pressing one of the following keys : " << endl;
    cout << '\t' << "Bungee Spring : [1]" << endl;
    cout << '\t' << "Anchored Spring : [2]" << endl;
    cout << '\t' << "Floating Point (buoyancy) : [3]" << endl;
    cout << '\t' << "Stiff Spring : [4]" << endl;
    cout << '\t' << "Rod : [5]" << endl;
    cout << '\t' << "Blob (Springs and cables) : [6]" << endl;
    cout << endl;
}

void render() {
    //cout<<"Entre dans Rendu : "<<endl;
    if (isSceneLoaded) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);  //Je mets la matrice MODEL_VIEW en utilisation courante.
        glLoadIdentity();
        gluPerspective(45.0f, (float) 960 / (float) 960, 0.1f, 2000.0f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(-250.0f, 0.0f, -700.0f);

        //cout << "IPS : " << gImagesParSeconde << "\r\n";

        if(isAnchored)
        {
            //Display spring
            glLineWidth(1.0f);
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_LINES);
            glVertex3f(world.getWorldParticles()[0]->getPosition()->getX(),world.getWorldParticles()[0]->getPosition()->getY(),world.getWorldParticles()[0]->getPosition()->getZ());
            glVertex3f(250.0f,150.0f,0.0f);
            glEnd();

            //Display anchor
            glPointSize(3.0f);
            glColor3f(1.0, 1.0, 0.0);
            glBegin(GL_POINTS);
            glVertex3f(250.0f,150.0f,0.0f);
            glEnd();
        }

        if(isWaterNeeded)
        {
            glLineWidth(2.0f);
            glColor3f(0.0, 0.0, 0.8f);
            glBegin(GL_LINES);
            glVertex3f(-100.0f, 100.0f, 0.0f);
            glVertex3f(600.0f, 100.0f, 0.0f);
            glEnd();
        }

        Particle* currentParticle;
        for (auto &i : world.getWorldParticles()) {
            currentParticle = i;

            //Particle display
            glPointSize(3.0f);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POINTS);
            glVertex3f(currentParticle->getPosition()->getX(),currentParticle->getPosition()->getY(),currentParticle->getPosition()->getZ());
            glEnd();

            //Particle radius display
            glLineWidth(2.0f);
            glColor3f(0.2, 0.3, 0.5);
            glBegin(GL_LINE_LOOP);

            for(double d = 0; d < max; d += inc) {
                glVertex2f(static_cast<GLfloat>(cos(d) * currentParticle->getRadius() + currentParticle->getPosition()->getX()),
                           static_cast<GLfloat>(sin(d) * currentParticle->getRadius() + currentParticle->getPosition()->getY()));
            }
            glEnd();
        }


        vector<float> &grounds = world.getGrounds();
        vector<float> &walls = world.getGroundSeparations();
        glLineWidth(1.0f);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        glVertex3f(-100.0f,grounds[0],0.0f);
        if(!walls.empty())
        {
            glVertex3f(walls[0],grounds[0],0.0f);
            glEnd();

            for (int i = 1; i < grounds.size()-1; ++i) {
                glLineWidth(1.0f);
                glColor3f(1.0, 1.0, 1.0);
                glBegin(GL_LINES);
                glVertex3f(walls[i-1],grounds[i-1],0.0f);
                glVertex3f(walls[i-1],grounds[i],0.0f);
                glEnd();

                glLineWidth(1.0f);
                glColor3f(1.0, 1.0, 1.0);
                glBegin(GL_LINES);
                glVertex3f(walls[i-1],grounds[i],0.0f);
                glVertex3f(walls[i],grounds[i],0.0f);
                glEnd();
            }

            glLineWidth(1.0f);
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_LINES);
            glVertex3f(walls[walls.size()-1],grounds[grounds.size()-2],0.0f);
            glVertex3f(walls[walls.size()-1],grounds[grounds.size()-1],0.0f);
            glEnd();

            glLineWidth(1.0f);
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_LINES);
            glVertex3f(walls[walls.size()-1],grounds[grounds.size()-1],0.0f);

        }
        glVertex3f(600.0f,grounds[grounds.size()-1],0.0f);
        glEnd();


        ParticleLink* currentLink;
        for (auto &i : world.getParticleLinks()) {
            currentLink = i;

            //Display of links
            glLineWidth(2.0f);
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_LINES);
            glVertex3f(currentLink->getLinkedParticles()[0]->getPosition()->getX(), currentLink->getLinkedParticles()[0]->getPosition()->getY(), currentLink->getLinkedParticles()[0]->getPosition()->getZ());
            glVertex3f(currentLink->getLinkedParticles()[1]->getPosition()->getX(), currentLink->getLinkedParticles()[1]->getPosition()->getY(), currentLink->getLinkedParticles()[1]->getPosition()->getZ());
            glEnd();
        }


        glutSwapBuffers();

        //glFlush();
        //cout<<"Fin de Rendu"<<endl;
        //cout<<endl;
    }
}

void keyboard(unsigned char c) {

    if(!isSceneLoaded){
        switch (c) {
            case '1':
                cout<<"World init for bungee spring"<<endl;
                world.initWorld1();
                physics.initWorldPhysics1(world);
                cout<<"init finished"<<endl;
                isSceneLoaded = true;


                break;
            case '2':
                cout<<"init begin"<<endl;
                world.initWorld2();
                physics.initWorldPhysics2(world);
                isWaterNeeded = true;
                isSceneLoaded = true;
                cout<<"init finished"<<endl;

                break;
            case '3':

                cout<<"World init for anchored particle"<<endl;
                world.initWorld3();
                physics.initWorldPhysics3(world);
                cout<<"init finished"<<endl;
                isAnchored = true;
                isSceneLoaded = true;

                break;
            case '4':

                cout<<"World init for stiff spring"<<endl;
                world.initWorld4();
                physics.initWorldPhysics4(world);
                cout<<"init finished"<<endl;
                isAnchored = true;
                isSceneLoaded = true;

                break;
            case '5':

                cout<<"World init for Rod"<<endl;
                world.initWorld5();
                physics.initWorldPhysics5(world);
                cout<<"init finished"<<endl;
                isSceneLoaded = true;

                break;

            case '6':

                cout<<"World init for blob"<<endl;
                world.initWorld6();
                physics.initWorldPhysics6(world);
                cout<<"init finished"<<endl;
                isSceneLoaded = true;

                break;
            case 'x':
                exit(0);
            default:
                break;
        }
    }
    else{
        switch (c) {
            case 'r':
                world.getWorldParticles()[0]->setVelocity(new Vector3D(world.getWorldParticles()[0]->getVelocity()->getX()+1.5f,0,0));
                break;
            case 'e':
                world.getWorldParticles()[0]->setVelocity(new Vector3D(world.getWorldParticles()[0]->getVelocity()->getX()-1.5f,0,0));
                break;
            case 'x':
                isSceneLoaded = false;
                isAnchored = false;
                isWaterNeeded = false;
                world.eraseWorld();
                physics.erasePhysics();
                displayChoice();
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

    // Boucle de calculs physiques en cas de Scene de jeu chargée
    if(isSceneLoaded){
        // Application des forces aux particules
        physics.applyForces(dt);

        // Intégration
        physics.particlesIntegrator(world.getWorldParticles(),dt);

        // Réinitialisation des forces accumulées
        world.clearForceAccums();

        // Résolution de contacts avec le sol
        physics.searchAndResolveContactsWithGround(world);

        // Résolution de contacts
        physics.searchContacts(world);
        if(!physics.getContacts().empty()){
            physics.initFrameContactResolver(physics.getContacts().size());
            physics.resolveContacts(dt);
        }
        while(physics.getContactResolver().getConsumedIterations()<physics.getContactResolver().getIterationsMax()){
            physics.searchContacts(world);
            if(physics.getContacts().size()>0){
                physics.resolveContacts(dt);
            }
            else{
                break;
            }
        }
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
    isAnchored=false;
    isWaterNeeded=false;
    displayChoice();
    glutDisplayInit(argc, argv);

    return 0;
}