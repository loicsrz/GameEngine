//
// Created by Vince on 29/08/2018.
//
#include<iostream>
#include <vector>
#include <GL/glut.h>
#include "../include/2B3_Engine/Particle.h"

using namespace std;

GLint gImagesParSeconde = 0;
GLfloat dt = 0.0;
Particle *particule = new Particle(new Vector3D(-0.99f, 0.0, 0.0), new Vector3D(0, 0, 0),
                                     new Vector3D(0.0, 0.0, 0.0), 1, 1),
        *projectile;
vector<Particle *> particules;

void afficherChoix() {
    cout << "Veuillez choisir un projectile à lancer en appuyant sur la touche correspondante : " << endl;
    cout << '\t' << "Balle de pistolet : [1]" << endl;
    cout << '\t' << "Boulet de canon : [2]" << endl;
    cout << '\t' << "Boule de feu : [3]" << endl;
    cout << '\t' << "Laser : [4]" << endl;
    cout << endl;
}

void Rendu() {
    //cout<<"Entre dans Rendu : "<<endl;
    if (!particules.empty()) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);  //Je met la matrice MODEL_VIEW en utilisation courante.
        glLoadIdentity();
        gluPerspective(45.0f, (float)960 / (float)960, 0.1f, 2000.0f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(-250.0f,0.0f,-700.0f);

        //cout << "IPS : " << gImagesParSeconde << "\r\n";

        glPointSize(5.0f);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex3f(particules[0]->getPosition()->getX(), particules[0]->getPosition()->getY(),
                   particules[0]->getPosition()->getZ());
        if (particules[0]->getPosition()->getX() > 500 || particules[0]->getPosition()->getY() < -500 ||
            particules[0]->getPosition()->getY() > 500) {
            particules.pop_back();
            particules.push_back(particule);

            cout << "La particule s'est envolee vers d'autres horizons ..." << endl;
            cout << endl;
            afficherChoix();
        }
        glEnd();

        glutSwapBuffers();

        //glFlush();
        //cout<<"Fin de Rendu"<<endl;
        //cout<<endl;
    }
}

void Clavier(unsigned char c) {

    switch (c) {
        case '1':
            projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(35.0f, 0, 0),
                                       new Vector3D(0, -1.0f, 0), 2, 0.99f);
            cout << "Projectile selectionne : Balle de pistolet." << endl;
            cout
                    << "Appuyez sur la touche ENTREE pour lancer la particule,"
                    << "\nou selectionnez un autre projectile en appuyant sur la touche correspondante."
                    << endl;
            break;
        case '2':
            projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(50.0f, 0, 0),
                                       new Vector3D(0, -20.0f, 0), 200, 0.99f);
            cout << "Projectile selectionne  : Boulet de canon." << endl;
            cout
                    << "Appuyez sur la touche ENTREE pour lancer la particule,"
                    << "\nou selectionnez un autre projectile en appuyant sur la touche correspondante."
                    << endl;
            break;
        case '3':
            projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(2.0f, 0, 0),
                                       new Vector3D(0, 0.6f, 0), 1, 0.9f);
            cout << "Projectile selectionne  : Boule de feu." << endl;
            cout
                    << "Appuyez sur la touche ENTREE pour lancer la particule,"
                    << "\nou selectionnez un autre projectile en appuyant sur la touche correspondante."
                    << endl;
            break;
        case '4':
            projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(100.0f, 0, 0), new Vector3D(0, 0, 0),
                                       0, 0.99f);
            cout << "Projectile selectionne  : Laser." << endl;
            cout
                    << "Appuyez sur la touche ENTREE pour lancer la particule,"
                    << "\nou selectionnez un autre projectile en appuyant sur la touche correspondante."
                    << endl;
            break;
        case 13:
            particules.pop_back();
            particules.push_back(projectile);
            break;
        case 'x':
            exit(0);
        default:
            break;
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

void integrateur(vector<Particle *> particules, float deltaTemps) {

//    int n = 1;
    for (auto &particule : particules) {
        /*cout << "Particle " << n << " :" << endl;
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
    //particule->setPosition(new Vector3D(particule->getPosition()->getX()+0.01,particule->getPosition()->getY(), particule->getPosition()->getZ()));

    IPS(); // Appelé une fois par calcul d'image pour afficher le nombre d'IPS
    glutPostRedisplay(); // Lance un appel à Rendu() au taux d'IPS voulu
}

void glutDisplayInit(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(960, 960);
    glutInitWindowPosition(900, 0);
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