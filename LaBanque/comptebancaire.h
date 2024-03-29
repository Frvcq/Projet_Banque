#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
class CompteBancaire
{
protected:
    /**
     * @brief solde
     * @details Le solde du compte bancaire
     */
    float solde;
public:
    CompteBancaire();
    CompteBancaire(const float _solde);
    void Deposer(const float _montant);
    bool Retirer(const float _montant);
    float ConsulterSolde();
};

#endif // COMPTEBANCAIRE_H
