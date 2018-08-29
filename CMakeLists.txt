#Déclaration de version du Cmake minimum
cmake_minimum_required(VERSION 3.5)

#Déclaration du nom du projet
project(GameEngine)

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -framework GLUT -framework OpenGL")

#Crée l'exécutable pour le projet
add_executable(Main main.cpp)