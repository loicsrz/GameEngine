set(SOURCE_FILES main.cpp Particle.cpp ../include/2B3_Engine/Particle.h Vector3D.cpp ../include/2B3_Engine/Vector3D.h
    ParticleForceGenerator.cpp ../include/2B3_Engine/ParticleForceGenerator.h RegisterForces.cpp
    ../include/2B3_Engine/RegisterForces.h DragGenerator.cpp ../include/2B3_Engine/DragGenerator.h
    GravityGenerator.cpp ../include/2B3_Engine/GravityGenerator.h ParticleSpring.cpp ../include/2B3_Engine/ParticleSpring.h
    ../include/2B3_Engine/DragGenerator.h BungeeSpring.cpp ../include/2B3_Engine/BungeeSpring.h 
    ParticleStiffSpring.cpp ../include/2B3_Engine/ParticleStiffSpring.h ParticleAnchoredSpring.cpp ../include/2B3_Engine/ParticleAnchoredSpring.h ParticleFloating.cpp ../include/2B3_Engine/ParticleFloating.h
    ParticleContact.cpp ../include/2B3_Engine/ParticleContact.h ParticleContactResolver.cpp ../include/2B3_Engine/ParticleContactResolver.h
    World.cpp ../include/2B3_Engine/World.h ParticleContactGenerator.cpp ../include/2B3_Engine/ParticleContactGenerator.h 
    ParticleLink.cpp ../include/2B3_Engine/ParticleLink.h ParticleCable.cpp ../include/2B3_Engine/ParticleCable.h ParticleRod.cpp ../include/2B3_Engine/ParticleRod.h WorldPhysics.cpp ../include/2B3_Engine/WorldPhysics.h Quaternion.cpp ../include/2B3_Engine/Quaternion.h Matrix3.cpp ../include/2B3_Engine/Matrix3.h Matrix4.cpp ../include/2B3_Engine/Matrix4.h)

# Création de l'exécutable pour le projet
add_executable(2Be3_Engine ${SOURCE_FILES})

target_link_libraries(2Be3_Engine ${OPENGL_LIBRARIES} freeglut)