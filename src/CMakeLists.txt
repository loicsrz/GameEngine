set(SOURCE_FILES main.cpp Particule.cpp ../include/2B3_Engine/Particule.h Vecteur3D.cpp ../include/2B3_Engine/Vecteur3D.h)

# Création de l'exécutable pour le projet
add_executable(2Be3_Engine ${SOURCE_FILES})

target_link_libraries(2Be3_Engine ${OPENGL_LIBRARIES} freeglut)