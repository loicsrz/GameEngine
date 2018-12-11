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
bool collisionDetected;
Particle massCenter;
Particle Vertices [3];
int scene=0;
vector<Vector3D*> walls;
vector<Vector3D*> contactPoints;
vector<Contact*> contacts;
int i = 0;
bool stopDrawing = false;

void displayChoice() {
    cout << "Please choose a scenario by pressing one of the following keys : " << endl;
    cout << '\t' << "Recherche de contact : [1]" << endl;
    cout << '\t' << "Sortie : [x]" << endl;
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
        glTranslatef(0.0f, -100.0f, -1400.0f);
        //gluLookAt(0.0f, -200.0f, 700.0f, 0.0f, 0.0f, 0.0f, 0.f, 1.0f, 0.0f);

        //DESSIN DE LA BOITE

        //glColor3f(0.0, 1.0, 0.0)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        //FRONT
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        for (int i = 4; i < 8; i++) {
            glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
            glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[i]->getPosition()->getX(),
                       world.getWorldObjects()[0]->getBody()->getBodyParticles()[i]->getPosition()->getY(),
                       world.getWorldObjects()[0]->getBody()->getBodyParticles()[i]->getPosition()->getZ());
        }
        glEnd();

        //BACK
        glBegin(GL_POLYGON);
        for (int i = 0; i < 4; i++) {
            glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
            glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[i]->getPosition()->getX(),
                       world.getWorldObjects()[0]->getBody()->getBodyParticles()[i]->getPosition()->getY(),
                       world.getWorldObjects()[0]->getBody()->getBodyParticles()[i]->getPosition()->getZ());
        }
        glEnd();

        //RIGHT
        glBegin(GL_POLYGON);
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[5]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[5]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[5]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[1]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[1]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[1]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[2]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[2]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[2]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[6]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[6]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[6]->getPosition()->getZ());
        glEnd();

        //LEFT
        glBegin(GL_POLYGON);
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[0]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[0]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[0]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[4]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[4]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[4]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[7]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[7]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[7]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[3]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[3]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[3]->getPosition()->getZ());
        glEnd();

        //TOP
        glBegin(GL_POLYGON);
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[7]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[7]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[7]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[6]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[6]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[6]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[2]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[2]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[2]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[3]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[3]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[3]->getPosition()->getZ());
        glEnd();

        //DOWN
        glBegin(GL_POLYGON);
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[0]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[0]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[0]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[1]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[1]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[1]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[5]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[5]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[5]->getPosition()->getZ());
        glColor3f((float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100, (float) (rand() % 100 + 1)/100);
        glVertex3f(world.getWorldObjects()[0]->getBody()->getBodyParticles()[4]->getPosition()->getX(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[4]->getPosition()->getY(),
                   world.getWorldObjects()[0]->getBody()->getBodyParticles()[4]->getPosition()->getZ());
        glEnd();




        //DESSIN DE LA CAGE
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glLineWidth(1.0f);
        glColor3f(0.0f,1.0f,0.0f);

        //FRONT
        glBegin(GL_POLYGON);
        glVertex3f(-300, -300,300);
        glVertex3f(300,-300,300);
        glVertex3f(300,300,300);
        glVertex3f(-300,300,300);
        glEnd();

        //BACK
        glBegin(GL_POLYGON);
        glVertex3f(-300, -300,-300);
        glVertex3f(300,-300,-300);
        glVertex3f(300,300,-300);
        glVertex3f(-300,300,-300);
        glEnd();

        //EDGES BETWEEN FRONT & BACK

        glBegin(GL_LINES);
        glVertex3f(-300, -300,-300);
        glVertex3f(-300, -300,300);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(300, -300,-300);
        glVertex3f(300, -300,300);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(300, 300,-300);
        glVertex3f(300, 300,300);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(-300, 300,-300);
        glVertex3f(-300, 300,300);
        glEnd();


        //DESSIN DES FACES TOUCHÉES
        if(collisionDetected)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glColor4f(0.0f,1.0f,0.0f,0.5f);
            for(Vector3D * & perpAngle : walls)
            {
                glBegin(GL_POLYGON);

                if((int)perpAngle->getX() == 1)     //RIGHT PLANE
                {
                    glVertex3f(300,-300,-300);
                    glVertex3f(300,-300,300);
                    glVertex3f(300,300,300);
                    glVertex3f(300,300,-300);
                }
                else if ((int)perpAngle->getX() == -1)      //LEFT PLANE
                {
                    glVertex3f(-300,-300,300);
                    glVertex3f(-300,-300,-300);
                    glVertex3f(-300,300,-300);
                    glVertex3f(-300,300,300);
                }
                else
                {
                    if ((int)perpAngle->getY() == 1)      //TOP PLANE
                    {
                        glVertex3f(-300,300,-300);
                        glVertex3f(300,300,-300);
                        glVertex3f(300,300,300);
                        glVertex3f(-300,300,300);
                    }
                    else if ((int)perpAngle->getY() == -1)      //BOTTOM PLANE
                    {
                        glVertex3f(-300,-300,-300);
                        glVertex3f(300,-300,-300);
                        glVertex3f(300,-300,300);
                        glVertex3f(-300,-300,300);
                    }
                    else
                    {
                        if((int)perpAngle->getZ() == 1)      //FRONT PLANE
                        {
                            glVertex3f(-300,-300,300);
                            glVertex3f(300,-300,300);
                            glVertex3f(300,300,300);
                            glVertex3f(-300,300,300);
                        }
                        else      //BACK PLANE
                        {
                            glVertex3f(-300,-300,-300);
                            glVertex3f(300,-300,-300);
                            glVertex3f(300,300,-300);
                            glVertex3f(-300,300,-300);
                        }
                    }
                }
                glEnd();
            }

            if(contactPoints.size()!=0)
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glDisable(GL_DEPTH_TEST);
                glColor3f(1.0f,0.0f,0.0f);
                glLineWidth(2.0f);
                glPointSize(2.0f);
                for(Vector3D * & point : contactPoints)
                {
                    glBegin(GL_POLYGON);
                    glVertex3f(point->getX()-10,point->getY()-10,point->getZ());
                    glVertex3f(point->getX()+10,point->getY()+-10,point->getZ());
                    glVertex3f(point->getX()+10,point->getY()+10,point->getZ());
                    glVertex3f(point->getX()-10,point->getY()+10,point->getZ());
                    glEnd();
                    glBegin(GL_POINTS);
                    glVertex3f(point->getX(),point->getY(),point->getZ());
                    glEnd();
                }
                glEnable(GL_DEPTH_TEST);
            }
        }

        glFlush();
        glutSwapBuffers();

        //cout << "IPS : " << gImagesParSeconde << "\r\n";

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
                contactPoints.clear();
                walls.clear();
                collisionDetected = false;
                displayChoice();
                break;
            default:
                break;
        }
    }
    else if(!isSceneLoaded){
        switch (c) {
            case '1':
                world.initWorld1();
                physics.initWorldPhysics1();
                isSceneLoaded = true;
                scene = 1;


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
    if(runScenario && !collisionDetected){
        // Application des forces et torques aux rigidBodies
        physics.applyForces(dt);
        physics.updateAllRigidBodiesAccum(world.getWorldObjects());

        // Intégration
        physics.rigidBodyIntegrator(world.getWorldObjects(),dt);
        // Réinitialisation des forces accumulées
        world.clearAccums();


        physics.searchAllPotentialContacts(world.getWorldObjects(),world.getRoot());
        physics.generateAllContacts();
        if(physics.getData()->getContacts().size() != 0){
            collisionDetected = true;
            contacts = physics.getData()->getContacts();
            for (Contact * & contact : contacts) {
                contactPoints.push_back(contact->getContactPoint());
            }
            walls = physics.contactType();
        }
        physics.resetAllCollisions();
    }

    fps(); // Appelé une fois par calcul d'image pour afficher le nombre d'IPS
    glutPostRedisplay(); // Lance un appel à Rendu() au taux d'IPS voulu
}

void glutDisplayInit(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(960, 960);
    glutInitWindowPosition(900, 0);
    glutCreateWindow("2Be3_Engine");
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

int main(int argc, char **argv) {
    isSceneLoaded=false;
    runScenario = false;
    collisionDetected = false;

    displayChoice();
    glutDisplayInit(argc, argv);

    return 0;
}