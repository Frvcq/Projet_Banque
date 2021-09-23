#include "comptebancaire.h"
/**
 * @brief CompteBancaire::CompteBancaire
 * @details Constructeur par defaut
 */


CompteBancaire::CompteBancaire()
{
    solde = 0;
}
/**
 * @brief CompteBancaire::CompteBancaire
 * @param _solde
 * @details Constructeur de la classe
 */
CompteBancaire::CompteBancaire(const float _solde):
    solde(_solde)
{

}

/**
 * @brief CompteBancaire::~CompteBancaire
 * @details Destructeur de la classe
 */


CompteBancaire::~CompteBancaire()
{

}

/**
 * @brief CompteBancaire::Deposer
 * @param _montant
 * @details Methode qui permet de déposer de l'argent sur son compte bancaire
 */


void CompteBancaire::Deposer(const float _montant)
{
    if (_montant > 0){
        solde = solde +_montant;
    }
    else {
        cout << "Impossible d'ajouter des choses negatives";
    }

}
/**
 * @brief CompteBancaire::Retirer
 * @param _montant
 * @return retourne le solde
 * @details Methode qui permet de savoir si on peut retirer de l'argent et retire l'argent si possible
 */

bool CompteBancaire::Retirer(const float _montant)
{
    bool x;
    if(solde < _montant){
        x=false;
    }
    else {
        x=true;
        solde = solde-_montant;
    }
    return x;


}

float CompteBancaire::ConsulterSolde()
{
    return solde;
}
