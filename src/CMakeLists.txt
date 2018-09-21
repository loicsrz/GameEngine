set(SOURCE_FILES main.cpp Particle.cpp ../include/2B3_Engine/Particle.h Vector3D.cpp ../include/2B3_Engine/Vector3D.h
    ParticleForceGenerator.cpp ../include/2B3_Engine/ParticleForceGenerator.h RegisterForces.cpp
    ../include/2B3_Engine/RegisterForces.h DragGenerator.cpp ../include/2B3_Engine/DragGenerator.h
    GravityGenerator.cpp ../include/2B3_Engine/GravityGenerator.h shader.cpp shader.hpp)

# Création de l'exécutable pour le projet
add_executable(2Be3_Engine ${SOURCE_FILES} SimpleFragmentShader.fragmentshader SimpleVertexShader.vertexshader)

target_link_libraries(2Be3_Engine ${OPENGL_LIBRARIES} glfw3 glew32)