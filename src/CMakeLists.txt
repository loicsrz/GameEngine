set(SOURCE_FILES main.cpp Particle.cpp ../include/2B3_Engine/Particle.h Vector3D.cpp ../include/2B3_Engine/Vector3D.h
    ParticleForceGenerator.cpp ../include/2B3_Engine/ParticleForceGenerator.h RegisterForces.cpp
    ../include/2B3_Engine/RegisterForces.h DragGenerator.cpp ../include/2B3_Engine/DragGenerator.h
    GravityGenerator.cpp ../include/2B3_Engine/GravityGenerator.h ParticleSpring.cpp ../include/2B3_Engine/ParticleSpring.h
    ../include/2B3_Engine/DragGenerator.h BungeeSpring.cpp ../include/2B3_Engine/BungeeSpring.h AnchoredParticle.cpp ../include/2B3_Engine/AnchoredParticle.h)

# Création de l'exécutable pour le projet
add_executable(2Be3_Engine ${SOURCE_FILES})

target_link_libraries(2Be3_Engine ${OPENGL_LIBRARIES} freeglut)