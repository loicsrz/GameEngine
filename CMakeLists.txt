# Déclaration de version du Cmake minimum
cmake_minimum_required(VERSION 3.4)

# Déclaration du nom du projet
project(GameEngine)

set(TEST false)

#Déclaration du dossier de sortie
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ../bin/x64)

# Déclaration de la librairie FreeGLUT
set(FREEGLUT_INCLUDE_DIRS freeglut/include)
set(FREEGLUT_LIBRARY_DIRS freeglut/lib/x64)
set(FREEGLUT_LIBRARIES freeglut)

# Définition des fichiers sources
include_directories( ${OPENGL_INCLUDE_DIRS}  ${FREEGLUT_INCLUDE_DIRS} )

#Instruction de recherche du paquet OpenGL
find_package(OpenGL REQUIRED)

# Définition du standard C++
set(CMAKE_CXX_STANDARD 14)

#Création du lien avec la librairie FreeGLUT
link_directories(${FREEGLUT_LIBRARY_DIRS} )

if (TEST)
    add_subdirectory(test)
    else()
    add_subdirectory(src)
endif(TEST)