# Déclaration de version du Cmake minimum
cmake_minimum_required(VERSION 3.5)

# Déclaration du nom du projet
project(GameEngine)

#Déclaration du dossier de sortie
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ../freeglut/bin/x64)

# Déclaration de la librairie FreeGLUT
set(FREEGLUT_INCLUDE_DIRS freeglut/include)
set(FREEGLUT_LIBRARY_DIRS freeglut/lib/x64)
set(FREEGLUT_LIBRARIES freeglut)

#Instruction de recherche du paquet OpenGL
find_package(OpenGL REQUIRED)

# Définition du standard C++
set(CMAKE_CXX_STANDARD 14)

# Définition des fichiers sources
set(SOURCE_FILES main.cpp Particule.cpp Particule.h Vecteur3D.cpp Vecteur3D.h)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${FREEGLUT_INCLUDE_DIRS} )

#Création du lien avec la librairie FreeGLUT
link_directories(${FREEGLUT_LIBRARY_DIRS})

# Création de l'exécutable pour le projet
add_executable(2Be3_Engine ${SOURCE_FILES})
target_link_libraries(2Be3_Engine ${OPENGL_LIBRARIES} freeglut)