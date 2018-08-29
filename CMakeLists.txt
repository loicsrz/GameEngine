#Déclaration de version du Cmake minimum
cmake_minimum_required(VERSION 3.5)

#Déclaration du nom du projet
project(GameEngine)

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -framework GLUT -framework OpenGL")

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp Particule.cpp Particule.h Vecteur3D.cpp Vecteur3D.h)

#Crée l'exécutable pour le projet
add_executable(2Be3_Engine ${SOURCE_FILES})