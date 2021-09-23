#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H
#include "comptebancaire.h"


class CompteEpargne : public CompteBancaire
{
private:
    /**
     * @brief tauxInterets
     * @details Les taux d'interets en pourcentage
     */

    float tauxInterets;
public:
    CompteEpargne(const float _tauxInterets);
    CompteEpargne(const float _solde,const float _tauxInterets);
    void CalculerInterets();
};

#endif // COMPTEEPARGNE_H
