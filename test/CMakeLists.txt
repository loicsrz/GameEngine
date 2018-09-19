set(SOURCE_FILES ../src/Particle.cpp ../include/2B3_Engine/Particle.h Test_Particule.cpp ../src/Vector3D.cpp ../include/2B3_Engine/Vector3D.h)

# Déclaration de la librarie Google Test
set(GTEST_INCLUDE_DIRS ../googletest/include)
set(GTEST_LIBRARIES ../googletest)
set(GTEST_LIBRARY_DIRS ../googletest/lib/x64)

include_directories(${GTEST_INCLUDE_DIRS} ${GTEST_LIBRARIES})

#Création du lien avec la librairie GoogleTest
link_directories(${GTEST_LIBRARY_DIRS})

# Création de l'exécutable pour le projet de test
add_executable(2Be3_Engine_Test ${SOURCE_FILES})

target_link_libraries(2Be3_Engine_Test ${OPENGL_LIBRARIES} freeglut googletest)