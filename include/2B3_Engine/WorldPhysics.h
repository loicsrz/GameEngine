//
// Created by totoa on 22/10/2018.
//

#ifndef GAMEENGINE_WORLDPHYSICS_H
#define GAMEENGINE_WORLDPHYSICS_H

#include <vector>
#include "Particle.h"
#include "ParticleContact.h"
#include "World.h"
#include "RegisterForces.h"
#include "ParticleContactResolver.h"
#include "RigidBody.h"
#include "CollisionData.h"
#include "Primitive.h"
#include "Plane.h"

using namespace std;

///Classe WorldPhysics
    ///Classe qui contient tous les éléments permettant de calculer et mettre à jour la physique du World
class WorldPhysics {
    ///Attributs
protected:
    vector<ParticleContact*> contacts;
    ParticleContactGenerator contactGenerator;
    RegisterForces registerForces;
    ParticleContactResolver contactResolver;
public:

    /// Constructeur par défaut
    WorldPhysics();

    /// Destructeur
    virtual ~WorldPhysics();

    /// Méthode de réinitialisation de la physique du World
    void erasePhysics();

    /// Méthode de génération de forces pour toutes les particules concernées par ces dernières
    void applyForces(float duration);

    /// Méthode d'intégration permettant de mettre à jour la position, la vitesse et l'accélération des Particle du World
    void particlesIntegrator(vector<Particle *> particles, float deltaTime);

    /// Méthode de recherche et résolution des contacts entre les Particle du World et le sol
    void searchAndResolveContactsWithGround(World world);

    /// Méthode de recherche et création de tous les contacts présents pour une Frame de jeu
    void searchContacts(World world);

    /// Méthode de résolution des contacts détectés préalablement
    void resolveContacts(float duration);

    /// Méthode de réinitialisation du resolver de contact utilisé à chaque Frame de jeu
    void initFrameContactResolver(int nbIterMax);

    ///Méthode d'intégration permettant de mettre à jour les informations des RigidBody du World
    void rigidBodyIntegrator(vector<Primitive*> objects, float deltaTime);

    ///Méthode de mise à jour des forceAccum de tous les rigidBody
    void updateAllRigidBodiesAccum(vector<Primitive*> objects);

    void GenerateContacts(Primitive *prim1, Primitive *prim2, CollisionData * data);

    /// Getters - Setters -------------------------------------------------------------------
    const ParticleContactResolver &getContactResolver() const;

    void setContactResolver(const ParticleContactResolver &contactResolver);

    const vector<ParticleContact *> &getContacts() const;

    void setContacts(const vector<ParticleContact *> &contacts);

    ///--------------------------------------------------------------------------------------

    /// Génération de la physique de chacun des World de démonstration ----------------------
    void initWorldPhysics1(World world);

    void initWorldPhysics2(World world);
    ///--------------------------------------------------------------------------------------
};


#endif //GAMEENGINE_WORLDPHYSICS_H
