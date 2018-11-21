//
// Created by Vince on 17/10/2018.
//

#ifndef GAMEENGINE_PARTICLECONTACT_H
#define GAMEENGINE_PARTICLECONTACT_H

#include "Particle.h"

/// Classe ParticleContact
    /// Classe qui modélise un contact entre deux Particle
class ParticleContact {
    friend class ParticleContactResolver;

protected:
    Particle* particles[2];
    float restitution;
    Vector3D* perpendicularAngle;
    float penetration;
    bool isLink;

public:
    ///Constructeur de ParticleContact
    ParticleContact(Particle **mParticles, float restitution, Vector3D *perpendicularAngle, float penetration, bool isLink);

    ///Destructeur
    virtual ~ParticleContact();

    /// Méthode de résolution du contact
    void Resolve(float duration);

    /// Méthode de calcul de vS'
    float SpeedCompute() const;

    /// Méthode de résolution du contact nécessitant une impulsion pour la résolution
    void ImpulsionResolve(float duration);

    /// Méthode de résolution du contact relatif à l'interpénétration des Particles entre elles
    void InterpenetrationResolve(float duration);

    ///Getters-Setters ----------------------------------------------------------
    Particle *const *getParticles() const;

    float getRestitution() const;

    void setRestitution(float restitution);

    Vector3D *getPerpendicularAngle() const;

    void setPerpendicularAngle(Vector3D *perpendicularAngle);

    float getPenetration() const;

    void setPenetration(float penetration);
    ///--------------------------------------------------------------------------

    ///Surcharge de l'opérateur de comparaison '<' pour effectuer un tri de ParticleContact
    bool operator<(ParticleContact const &b);
};

#endif //GAMEENGINE_PARTICLECONTACT_H
