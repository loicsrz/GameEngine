//
// Created by Vince on 29/08/2018.
//
#include<iostream>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <vector>

using namespace glm;
using namespace std;

#include "../include/2B3_Engine/shader.hpp"
#include "../include/2B3_Engine/Particle.h"

GLint gFramesPerSecond = 0;
GLfloat dt = 0.0;
Particle *particle, *projectile;
vector<Particle *> particles;
GLfloat g_vertex_buffer_data[18];
static const GLfloat verticesCoordinates[]={
    particle->getPosition()->getX()-1.0f, particle->getPosition()->getY()+1.0f, 0.0f,
    particle->getPosition()->getX()-1.0f, particle->getPosition()->getY()-1.0f, 0.0f,
    particle->getPosition()->getX()+1.0f, particle->getPosition()->getY()+1.0f, 0.0f,
    particle->getPosition()->getX()-1.0f, particle->getPosition()->getY()-1.0f, 0.0f,
    particle->getPosition()->getX()+1.0f, particle->getPosition()->getY()-1.0f, 0.0f,
    particle->getPosition()->getX()+1.0f, particle->getPosition()->getY()+1.0f, 0.0f};
static double limitFPS = 1.0 / 60.0;
double lastTime = glfwGetTime(), timer = lastTime;
double deltaTime = 0, nowTime = 0;
int frames = 0 , updates = 0;
GLuint programID, MatrixID;
GLuint vertexbuffer;
glm::mat4 mvp;

void display();

void displayChoice() {
    cout << "Please choose a projectile to shoot by pressing one of the following keys : " << endl;
    cout << '\t' << "Pistol bullet : [1]" << endl;
    cout << '\t' << "Cannonball : [2]" << endl;
    cout << '\t' << "Fireball : [3]" << endl;
    cout << '\t' << "Laser : [4]" << endl;
    cout << endl;
}

int main() {
    particle = new Particle(new Vector3D(-176.5f, 0.0, 0.0), new Vector3D(0, 0, 0), new Vector3D(0.0, 0.0, 0.0), 1, 1);
    display();

    return 0;

}

void update(){
    for (auto &particle : particles) {
        particle->integrator(deltaTime);
    }
}

void inline chooseProjectile(){
    if (glfwGetKey( window, GLFW_KEY_1 ) == GLFW_PRESS){
        projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(35.0f, 0, 0),
                                  new Vector3D(0, -1.0f, 0), 2, 0.99f);
        cout << "Projectile chosen : Pistol bullet" << endl;
        cout
                << "Press ENTER to shoot the particle,"
                << "\nor select another projectile by pressing the corresponding key."
                << endl;
    }
    if (glfwGetKey( window, GLFW_KEY_2 ) == GLFW_PRESS) {
        projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(50.0f, 0, 0),
                                  new Vector3D(0, -20.0f, 0), 200, 0.99f);
        cout << "Projectile chosen : Cannonball." << endl;
        cout
                << "Press ENTER to shoot the particle,"
                << "\nor select another projectile by pressing the corresponding key."
                << endl;
    }
    if (glfwGetKey( window, GLFW_KEY_3 ) == GLFW_PRESS) {
        projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(2.0f, 0, 0),
                                  new Vector3D(0, 0.6f, 0), 1, 0.9f);
        cout << "Projectile chosen : Fireball" << endl;
        cout
                << "Press ENTER to shoot the particle,"
                << "\nor select another projectile by pressing the corresponding key."
                << endl;
    }
    if (glfwGetKey( window, GLFW_KEY_4 ) == GLFW_PRESS) {
        projectile = new Particle(new Vector3D(-0.99f, 0, 0), new Vector3D(100.0f, 0, 0), new Vector3D(0, 0, 0),
                                  0, 0.99f);
        cout << "Projectile chosen : Laser." << endl;
        cout << "Press ENTER to shoot the particle,"
             << "\nor select another projectile by pressing the corresponding key."
             << endl;
    }
    if (glfwGetKey( window, GLFW_KEY_ENTER ) == GLFW_PRESS) {
            particles.pop_back();
            particles.push_back(projectile);
    }
}

/****************************************/
/*******OPEN GL WITH GLFW AND GLEW*******/
/****************************************/

void verticesPositionUpdate(float x, float y, float z){
    for (int i = 0; i < 18; i+=3) {
        for (int j = 0; j <3 ; ++j) {
            cout << i+j << endl;
            switch (j){
                case 0 :
                    g_vertex_buffer_data[i+j] = x + verticesCoordinates[i+j];
                    break;
                case 1 :
                    g_vertex_buffer_data[i+j] = y + verticesCoordinates[i+j];
                    break;
                case 2 :
                    g_vertex_buffer_data[i+j] = z + verticesCoordinates[i+j];
                    break;
                default:break;
            }
        }
    }
}

void render(){
    glClear(GL_COLOR_BUFFER_BIT);
    //cout << "IPS : " << gImagesParSeconde << "\r\n";

    verticesPositionUpdate(particles[0]->getPosition()->getX(), particles[0]->getPosition()->getY(),
                           particles[0]->getPosition()->getZ());
    if (particles[0]->getPosition()->getX() > 360 || particles[0]->getPosition()->getY() < 200 ||
        particles[0]->getPosition()->getY() > 200) {
        particles.pop_back();
        particles.push_back(particle);

        cout << "The particle blasted off ..." << endl;
        cout << endl;
        displayChoice();
    }

    // Use our shader
    glUseProgram(programID);

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

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
    glDrawArrays(GL_TRIANGLES, 0, 2*3); // Starting from vertex 0; 3 vertices total -> 1 triangle

    glDisableVertexAttribArray(0);

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void display(){
    // Initialise GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow(1280, 720, "Playground", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr,
                "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return;
    }

    // Assure que l'on peut capturer la touche d'échappement enfoncée ci-dessous
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

    // Get a handle for our "MVP" uniform
    MatrixID = glGetUniformLocation(programID, "mvp");

    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 Projection = glm::perspective(glm::radians(90.0f), 16.0f/9.0f, 0.1f, 100.0f);

    // Or, for an ortho camera :
//    glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

    // Camera matrix
    glm::mat4 View = glm::lookAt(
            glm::vec3(0,0,100), // Camera is at (4,3,3), in World Space
            glm::vec3(0,0,0), // and looks at the origin
            glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    // Model matrix : an identity matrix (model will be at the origin)
//    glm::mat4 Model      = glm::mat4(1.0f);
    glm::mat4 Model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    // Our ModelViewProjection : multiplication of our 3 matrices
    mvp = Projection * View * Model; // Remember, matrix multiplication is the other way around

    // An array of 3 vectors which represents 3 vertices
    verticesPositionUpdate(particle->getPosition()->getX(),particle->getPosition()->getY(),particle->getPosition()->getZ());

    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    do{

        // - Measure time
        nowTime = glfwGetTime();
        deltaTime += (nowTime - lastTime) / limitFPS;
        lastTime = nowTime;

// - Only update at 60 frames / s
        while (deltaTime >= 1.0){
            update();   // - Update function
            updates++;
            deltaTime--;
        }
// - Render at maximum possible frames
        render(); // - Render function
        frames++;

// - Reset after one second
        if (glfwGetTime() - timer > 1.0) {
            timer ++;
            std::cout << "FPS: " << frames << " Updates:" << updates << std::endl;
            updates = 0, frames = 0;
        }

        if(particles[0]==particle){
            chooseProjectile();
        }
    } // Vérifie si on a appuyé sur la touche échap (ESC) ou si la fenêtre a été fermée
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    // Cleanup VBO and shader
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteProgram(programID);
    glDeleteVertexArrays(1, &VertexArrayID);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();
}
/*

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
