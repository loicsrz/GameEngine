//
// Created by Vince on 17/10/2018.
//

using namespace std;

#ifndef GAMEENGINE_PARTICLECONTACTRESOLVER_H
#define GAMEENGINE_PARTICLECONTACTRESOLVER_H

#include <vector>
#include "ParticleContact.h"

/// Classe ParticleContactResolver
    /// Classe chargée de la résolution des contacts détectés par la boucle de calculs physiques du moteur physique
class ParticleContactResolver {
    friend class ParticleContact;

protected:
    int iterationsMax;
    int consumedIterations;

public:
    ///Constructeur par défaut
    ParticleContactResolver();

    ///Destructeur
    virtual ~ParticleContactResolver();

    /// Méthode de résolution des ParticleContact passés en paramètres
    void resolveContact(vector<ParticleContact*> contactVector,float duration);

    ///Getters - Setters ----------------------------------------------------------
    int getIterationsMax() const;

    int getConsumedIterations() const;

    void setIterationsMax(int iterationsMax);

    void setConsumedIterations(int consumedIterations);
    ///----------------------------------------------------------------------------

};


#endif //GAMEENGINE_PARTICLECONTACTRESOLVER_H
