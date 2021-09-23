#include "compteepargne.h"
/**
 * @brief CompteEpargne::CompteEpargne
 * @param _tauxInterets les taux d'interets en pourcentage
 * @details Constructeur par defaut  de la classe epargne
 */

CompteEpargne::CompteEpargne(const float _tauxInterets):
   CompteBancaire(0),
   tauxInterets(_tauxInterets)
{

}
/**
 * @brief CompteEpargne::CompteEpargne
 * @param _solde Solde du compte
 * @param _tauxInterets les taux d'interets en pourcentage
 *  @details Constructeur de la classe epargne
 */

CompteEpargne::CompteEpargne(const float _solde, const float _tauxInterets):
    CompteBancaire(_solde),
    tauxInterets(_tauxInterets)
{

}

/**
 * @brief CompteEpargne::CalculerInterets
 * @details permet de calculer les taux d'interets influents sur le solde
 */


void CompteEpargne::CalculerInterets()
{
solde = solde+((solde*tauxInterets)/100);
}
