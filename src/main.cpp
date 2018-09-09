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
Particule *particule = new Particule(new Vecteur3D(static_cast<float>(-0.99), 0.0, 0.0), new Vecteur3D(0, 0, 0),
                                                                                                                                new Vecteur3D(0.0, 0.0, 0.0), 1, 1),
                    *projectile;
vector<Particule *> particules;

void afficherChoix(){
    cout<<"Veuillez choisir un projectile à lancer en appuyant sur la touche correspondante : "<<endl;
    cout<<'\t'<<"Balle de pistolet : [1]"<<endl;
    cout<<'\t'<<"Boulet de canon : [2]"<<endl;
    cout<<'\t'<<"Boule de feu : [3]"<<endl;
    cout<<'\t'<<"Laser : [4]"<<endl;
    cout<<endl;
}
void Rendu() {
    //cout<<"Entre dans Rendu : "<<endl;
    if(particules.size()>0) {


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //cout << "IPS : " << gImagesParSeconde << "\r\n";

        glPointSize(5);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex3f(particules[0]->getPosition()->getX(), particules[0]->getPosition()->getY(),
                   particules[0]->getPosition()->getZ());
        if (particules[0]->getPosition()->getX() > 1 || particules[0]->getPosition()->getY() < -1 ||
            particules[0]->getPosition()->getY() > 1) {
            particules.pop_back();
            particules.push_back(particule);

            cout << "La particule s'est envolée vers d'autres horizons ..." << endl;
            cout << endl;
            afficherChoix();
        }
        glEnd();

        glutSwapBuffers();
        //cout<<"Fin de Rendu"<<endl;
        //cout<<endl;
    }
}

void Clavier(unsigned char c) {
    switch(c){
        case '1':
            projectile = new Particule(new Vecteur3D(-0.99f,0,0), new Vecteur3D(0.035f,0,0), new Vecteur3D(0,-0.00002f,0),2,0.99f);
            cout << "Projectile selectionné : Balle de pistolet." << endl;
            break;
        case '2':
            projectile = new Particule(new Vecteur3D(-0.99f,0,0), new Vecteur3D(0.050f,0,0), new Vecteur3D(0,-0.0004f,0),200,0.99f);
            cout << "Projectile selectionné  : Boulet de canon." << endl;
            break;
        case '3':
            projectile = new Particule(new Vecteur3D(-0.99f,0,0), new Vecteur3D(0.01f,0,0), new Vecteur3D(0,0.00006f,0),1,0.9f);
            cout << "Projectile selectionné  : Boule de feu." << endl;
            break;
        case '4':
            projectile = new Particule(new Vecteur3D(-0.99f,0,0), new Vecteur3D(0.1f,0,0), new Vecteur3D(0,0,0),0.1f,0.99f);
            cout << "Projectile selectionné  : Laser." << endl;
            break;
        case 13:
            cout<<"la"<<endl;
            particules.pop_back();
            cout<<"la"<<endl;
            particules.push_back(projectile);
            cout<<"la"<<endl;
            break;
        case 'x':
            exit(0);
        default:
            break;
    }

    cout
            << "Appuyez sur la touche ENTREE pour lancer la particule ou selectionnez un autre projectile en appuyant sur la touche correspondante."
            << endl;
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
    for (auto &particule : particules) {
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
        particule->integrateur(deltaTemps);
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
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(320, 0);
    glutCreateWindow("2Be3_Engine");
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(Rendu);
    glutKeyboardFunc(Clavier);
    glutMainLoop();
}

int main(int argc, char **argv) {
    particules.push_back(particule);
    afficherChoix();
    glutDisplayInit(argc, argv);

    return 0;
}