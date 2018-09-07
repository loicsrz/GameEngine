//
// Created by Vince on 29/08/2018.
//

using namespace std;

#include<iostream>
#include <GL/glut.h>
#include <ctime>
#include <windows.h>
#include <vector>
#include <chrono>
#include "../include/2B3_Engine/Particule.h"

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    glFlush();
}

void glutDisplayInit(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2Be3_Engine");
    glutDisplayFunc(displayMe);
    glutMainLoop();
}

void integrateur(vector<Particule *> particules, float deltaTemps){

    int n = 1;
    for(vector<Particule *>::iterator it=particules.begin();it != particules.end();++it){
        cout<<"Particule "<<n<<" :"<<endl;
        cout<<"Avant Integration : "<<endl;
        cout<< "Position : "<<endl;
        cout<<'\t'<<"x : "<<(*it)->getPosition()->getX()<<endl;
        cout<<'\t'<<"y : "<<(*it)->getPosition()->getY()<<endl;
        cout<<'\t'<<"z : "<<(*it)->getPosition()->getZ()<<endl;
        cout<< "Velocite : "<<endl;
        cout<<'\t'<<"x : "<<(*it)->getVelocite()->getX()<<endl;
        cout<<'\t'<<"y : "<<(*it)->getVelocite()->getY()<<endl;
        cout<<'\t'<<"z : "<<(*it)->getVelocite()->getZ()<<endl;
        cout<< "Acceleration : "<<endl;
        cout<<'\t'<<"x : "<<(*it)->getAcceleration()->getX()<<endl;
        cout<<'\t'<<"y : "<<(*it)->getAcceleration()->getY()<<endl;
        cout<<'\t'<<"z : "<<(*it)->getAcceleration()->getZ()<<endl;
        (*it)->integrateur(deltaTemps);
        cout<<"Après Integration : "<<endl;
        cout<< "Position : "<<endl;
        cout<<'\t'<<"x : "<<(*it)->getPosition()->getX()<<endl;
        cout<<'\t'<<"y : "<<(*it)->getPosition()->getY()<<endl;
        cout<<'\t'<<"z : "<<(*it)->getPosition()->getZ()<<endl;
        cout<< "Velocite : "<<endl;
        cout<<'\t'<<"x : "<<(*it)->getVelocite()->getX()<<endl;
        cout<<'\t'<<"y : "<<(*it)->getVelocite()->getY()<<endl;
        cout<<'\t'<<"z : "<<(*it)->getVelocite()->getZ()<<endl;
        cout<< "Acceleration : "<<endl;
        cout<<'\t'<<"x : "<<(*it)->getAcceleration()->getX()<<endl;
        cout<<'\t'<<"y : "<<(*it)->getAcceleration()->getY()<<endl;
        cout<<'\t'<<"z : "<<(*it)->getAcceleration()->getZ()<<endl;
        cout<<endl;
        n++;
    }
}

void lancerProjectile(float limiteTemps, float frameRate){ // Méthode à modifier en fonction de l'utilisation de glut avec le chrono
    using namespace std::chrono;

    vector<Particule*> vecteur;
    Particule * p1 = new Particule();
    Particule * p2 = new Particule();
    vecteur.push_back(p1);
    vecteur.push_back(p2);

    float temps=0.0f;
    while(temps<limiteTemps){
        //cout<<temps<<endl;
        steady_clock::time_point t1 = steady_clock::now();

        integrateur(vecteur,temps);
        //rendu

        steady_clock::time_point t2 = steady_clock::now();

        duration<float> time_span = duration_cast<duration<float>>(t2 - t1);
        //cout<<time_span.count()<<endl;
        float deltaTime = time_span.count();
        if(deltaTime < (1000.0f/frameRate)){
            temps+=(1000.0f/frameRate);
            Sleep((1000.0f/frameRate)-time_span.count());
        }
        else{
            steady_clock::time_point drop1 = steady_clock::now();
            float n = 2.0f;
            while(deltaTime < n * (1000.0f/frameRate)){
                n++;
            }
            steady_clock::time_point drop2 = steady_clock::now();
            duration<float> drop_span = duration_cast<duration<float>>(drop1 - drop2);
            temps+= n * (1000.0f/frameRate);
            if(deltaTime-(n-1) * (1000.0f/frameRate)+drop_span.count()<(1000.0f/frameRate)){
                Sleep((1000.0f/frameRate)-(deltaTime-(n-1) * (1000.0f/frameRate)+drop_span.count()));
            }
            else{
                Sleep((2*1000.0f/frameRate)-(deltaTime-(n-1) * (1000.0f/frameRate)+drop_span.count()));
            }
        }

    }
}

int main(int argc, char** argv)
{
    //glutDisplayInit(argc, argv);

    //lancerProjectile(10000,30);

    vector<Particule*> vecteur;
    Particule * p1 = new Particule();
    Particule * p2 = new Particule();
    p1 -> setAcceleration(new Vecteur3D(0,0,-1));
    vecteur.push_back(p1);
    vecteur.push_back(p2);

    float t1 = 0.0f;
    float t2 = 0.5f;
    float deltaTime;
    while(t2<=2.0f){
        deltaTime = t2-t1;
        integrateur(vecteur,deltaTime);
        t1=t2;
        t2+=0.5f;
    }

    return 0;

}

