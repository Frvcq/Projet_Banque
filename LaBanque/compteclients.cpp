#include "compteclients.h"
#include "menu.h"

/**
 *  @author Farvacque Flavian
 *  @date 23 septembre 2021
 */
/**
 * @brief CompteClients::CompteClients
 * @param _nom nom du client
 * @param _numero numero du compte
 * @details constructeur de la classe CompteClients
 */

CompteClients::CompteClients(string _nom, float _numero):
    nom(_nom),
    numero(_numero)
{
    compteBancaire = new CompteBancaire();
    compteEpargne = nullptr;
}
/**
 * @brief CompteClients::~CompteClients
 * @details Destructeur de la classe client. Il detruit compteBancaire puis compteEpargne si il existe
 */

CompteClients::~CompteClients()
{
    delete compteBancaire;

    if (compteEpargne != nullptr){
        delete compteEpargne;
    }


}
/**
 * @brief CompteClients::OuvrirCompteEpargne
 * @details Ouvre un compte epargne. Si compteEpargne est = nullptr le compte va alors se creer
 * sinon cela veut dire qu'il existe deja
 */

void CompteClients::OuvrirCompteEpargne()
{
    float y =0;
    float x=0;
    if (compteEpargne == nullptr){
    cout <<"entrez le solde initial"<<endl;
    cin >>y;
    cout <<"entrez le taux d'interet"<<endl;
    cin >>x;

    if (x <0 || y<0){
        cout<<"Operation echoue"<<endl;
    }
    else {
    compteEpargne = new CompteEpargne(y,x);

    }

    }
    else{
        cout <<"vous avez deja un compte epargne"<<endl;
    }
}
/**
 * @brief CompteClients::GererCompteBancaire
 * @details Permet de gerer son compte bancaire.
 */

void CompteClients::GererCompteBancaire()
{
    try {
        float montant;
        int choix;
        Menu leMenu("../LaBanque/compteBancaire.txt");
      //  CompteBancaire compte(5);

        do {
            choix = leMenu.Afficher();
            switch (choix)
            {
            case 1:
                cout << "Consultation du solde" << endl;
                cout <<compteBancaire->ConsulterSolde()<<endl;
                leMenu.AttendreAppuiTouche();

                break;

            case 2:
                cout << "Depot" << endl;
                cin >> montant;
                compteBancaire->Deposer(montant);
                cout << "Vous avez depose : "<<montant;
                leMenu.AttendreAppuiTouche();
                break;
            case 3:
                cout << "Retrait" << endl;
                cin >> montant;
                if(compteBancaire->Retirer(montant)==false){
                    cout <<"Solde insufisant pour effectuer l'operation"<<endl;
                }
                else {
                    cout <<"Vous avez retire : "<<montant<<endl;
                }

                leMenu.AttendreAppuiTouche();
                break;

            }

        }while(choix != 4);




    } catch (Exception erreur) {
        erreur.ObtenirMessage();
        erreur.ObtenirCodeErreur();
        exit(EXIT_FAILURE);
    }
}
/**
 * @brief CompteClients::GererCompteEpargne
 * @details permet de gerer le compte erpagne si compteEpargne n'est pas egale a nullptr. Sinon
 * cela veut dire que le compte epargne n'existe pas et on ne peut donc pas le gerer
 */

void CompteClients::GererCompteEpargne()
{

    if (compteEpargne!=nullptr){
    try {

        float montant;
        int choix;
        Menu leMenu("../LaBanque/compteEpargne.txt");
        //CompteEpargne compte(5);

        do {
            choix = leMenu.Afficher();
            switch (choix)
            {
            case 1:
                cout << "Consultation du solde" << endl;
                cout <<compteEpargne->ConsulterSolde()<<endl;
                leMenu.AttendreAppuiTouche();

                break;

            case 2:
                cout << "Depot" << endl;
                cin >> montant;
                compteEpargne->Deposer(montant);
                cout << "Vous avez depose : "<<montant;
                leMenu.AttendreAppuiTouche();
                break;
            case 3:
                cout << "Retrait" << endl;
                cin >> montant;
                if(compteEpargne->Retirer(montant)==false){
                    cout <<"Solde insufisant pour effectuer l'operation"<<endl;
                }
                else {
                    cout <<"Vous avez retire : "<<montant<<endl;
                }

                leMenu.AttendreAppuiTouche();
                break;
            case 4:
                cout << "Calul des interets : "<< endl;
                compteEpargne->CalculerInterets();
                cout <<"Votre noveau solde apres calcul des interets : "<<compteEpargne->ConsulterSolde()<<endl;

                break;
            }

        }while(choix != 5);




    } catch (Exception erreur) {
        erreur.ObtenirMessage();
        erreur.ObtenirCodeErreur();
        exit(EXIT_FAILURE);
    }
}
    else {
        cout <<"Compte epargne inexistant"<<endl;
    }
}
