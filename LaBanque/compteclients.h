#ifndef COMPTECLIENTS_H
#define COMPTECLIENTS_H
#include "compteepargne.h"
#include "comptebancaire.h"

class CompteClients
{
private:
    /**
     * @brief nom
     * @details nom du client
     */
    string nom;
    /**
     * @brief numero
     * @details numero du client
     */
    float numero;
    /**
     * @brief compteBancaire
     * @details compte bancaire du client
     */
    CompteBancaire *compteBancaire;
    /**
     * @brief compteEpargne
     * @details compte epargne du client
     */
    CompteEpargne *compteEpargne;

public:
    CompteClients(string _nom,float _numero);
    ~CompteClients();
    void OuvrirCompteEpargne();
    void GererCompteBancaire();
    void GererCompteEpargne();
};

#endif // COMPTECLIENTS_H
