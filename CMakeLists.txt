#Déclaration de version du Cmake minimum
cmake_minimum_required(VERSION 3.5)

#Déclaration du nom du projet
project(GameEngine)

# Définition du standard C++
set(CMAKE_CXX_STANDARD 14)

# Définition des fichiers sources
set(SOURCE_FILES main.cpp Particule.cpp Particule.h Vecteur3D.cpp Vecteur3D.h)

#Crée l'exécutable pour le projet
add_executable(2Be3_Engine ${SOURCE_FILES})