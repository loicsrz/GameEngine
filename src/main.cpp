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

void integrateur(vector<Particule> particules, float temps){

    for(vector<Particule>::iterator it=particules.begin();it != particules.end();++it){
        //it->integrateur(temps);
        cout << it->getPosition()->getZ();
    }
}

void lancerProjectile(float limiteTemps, float frameRate){
    using namespace std::chrono;

    vector<Particule> vecteur;
    Particule * p1 = new Particule();
    Particule * p2 = new Particule();
    vecteur.push_back(*p1);
    vecteur.push_back(*p2);

    float temps=0.0f;
    while(temps<limiteTemps){
        cout<<temps<<endl;
        steady_clock::time_point t1 = steady_clock::now();

        //integrateur(vecteur,temps);
        //rendu
        int a = 2;
        int b = a;
        cout<<b<<endl;
        steady_clock::time_point t2 = steady_clock::now();

        duration<float> time_span = duration_cast<duration<float>>(t2 - t1);
        cout<<time_span.count()<<endl;
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

    lancerProjectile(10000,30);
    return 0;

}

