//
// Created by Vince on 29/08/2018.
//

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "../include/2B3_Engine/shader.hpp"

int main( void ) {
    // Initialise GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow(1024, 768, "Playground", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr,
                "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // Assure que l'on peut capturer la touche d'échappement enfoncée ci-dessous
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

    glm::mat4 myMatrix = glm::translate(glm::mat4(), glm::vec3(10.0f, 0.0f, 0.0f));
    glm::vec4 myVector(10.0f, 10.0f, 10.0f, 0.0f);
    glm::vec4 transformedVector = myMatrix * myVector; // guess the result
    //glm::vec4 transformedVector = myMatrix * myVector; // Again, in this order ! this is important.

    // An array of 3 vectors which represents 3 vertices
    static const GLfloat g_vertex_buffer_data[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f,
    };

    // This will identify our vertex buffer
    GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    do{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader
        glUseProgram(programID);

        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
        );
        // Draw the triangle !
        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

        glDisableVertexAttribArray(0);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Vérifie si on a appuyé sur la touche échap (ESC) ou si la fenêtre a été fermée
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

}
/*#include<iostream>
#include <vector>
#include <GL/glut.h>
#include "../include/2B3_Engine/Particle.h"

using namespace std;

GLint gFramesPerSecond = 0;
GLfloat dt = 0.0;
Particle *particle, *projectile;
vector<Particle *> particles;

void displayChoice() {
    cout << "Please choose a projectile to shoot by pressing one of the following keys : " << endl;
    cout << '\t' << "Pistol bullet : [1]" << endl;
    cout << '\t' << "Cannonball : [2]" << endl;
    cout << '\t' << "Fireball : [3]" << endl;
    cout << '\t' << "Laser : [4]" << endl;
    cout << endl;
}

void render() {
    //cout<<"Entre dans Rendu : "<<endl;
    if (!particles.empty()) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);  //Je mets la matrice MODEL_VIEW en utilisation courante.
        glLoadIdentity();
        gluPerspective(45.0f, (float) 960 / (float) 960, 0.1f, 2000.0f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(-250.0f, 0.0f, -700.0f);

        //cout << "IPS : " << gImagesParSeconde << "\r\n";

        glPointSize(5.0f);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex3f(particles[0]->getPosition()->getX(), particles[0]->getPosition()->getY(),
                   particles[0]->getPosition()->getZ());
        if (particles[0]->getPosition()->getX() > 500 || particles[0]->getPosition()->getY() < -500 ||
            particles[0]->getPosition()->getY() > 500) {
            particles.pop_back();
            particles.push_back(particle);

            cout << "The particle blasted off ..." << endl;
            cout << endl;
            displayChoice();
        }
        glEnd();

        glutSwapBuffers();

        //glFlush();
        //cout<<"Fin de Rendu"<<endl;
        //cout<<endl;
    }
}

void keyboard(unsigned char c) {

    switch (c) {
        case '1':
            projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(35.0f, 0, 0),
                                      new Vector3D(0, -1.0f, 0), 2, 0.99f);
            cout << "Projectile chosen : Pistol bullet" << endl;
            cout
                    << "Press ENTER to shoot the particle,"
                    << "\nor select another projectile by pressing the corresponding key."
                    << endl;
            break;
        case '2':
            projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(50.0f, 0, 0),
                                      new Vector3D(0, -20.0f, 0), 200, 0.99f);
            cout << "Projectile chosen : Cannonball." << endl;
            cout
                    << "Press ENTER to shoot the particle,"
                    << "\nor select another projectile by pressing the corresponding key."
                    << endl;
            break;
        case '3':
            projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(2.0f, 0, 0),
                                      new Vector3D(0, 0.6f, 0), 1, 0.9f);
            cout << "Projectile chosen : Fireball" << endl;
            cout
                    << "Press ENTER to shoot the particle,"
                    << "\nor select another projectile by pressing the corresponding key."
                    << endl;
            break;
        case '4':
            projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(100.0f, 0, 0), new Vector3D(0, 0, 0),
                                      0, 0.99f);
            cout << "Projectile chosen : Laser." << endl;
            cout << "Press ENTER to shoot the particle,"
                 << "\nor select another projectile by pressing the corresponding key."
                 << endl;
            break;
        case 13:
            particles.pop_back();
            particles.push_back(projectile);
            break;
        case 'x':
            exit(0);
        default:
            break;
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

void vectorIntegrator(vector<Particle *> particles, float deltaTime) {

//    int n = 1;
    for (auto &particle : particles) {
        */
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
        cout << '\t' << "z : " << (*it)->getAcceleration()->getZ() << endl;*//*

        particle->integrator(deltaTime);
        */
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
        n++;*//*

    }
}

void timer(int value) {
    const int FPSwanted = 60;
    glutTimerFunc(1000 / FPSwanted, timer, ++value);
    dt = static_cast<float>(gFramesPerSecond > 0 ? 1.0 / static_cast<float>(gFramesPerSecond) : 1.0);

    // Emplacements des calculs à réaliser
    vectorIntegrator(particles, dt);
    //particule->setPosition(new Vector3D(particule->getPosition()->getX()+0.01,particule->getPosition()->getY(), particule->getPosition()->getZ()));

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
    particle = new Particle(new Vector3D(-0.99f, 0.0, 0.0), new Vector3D(0, 0, 0),
                            new Vector3D(0.0, 0.0, 0.0), 1, 1);
    particles.push_back(particle);
    displayChoice();
    glutDisplayInit(argc, argv);

    return 0;
}*/
