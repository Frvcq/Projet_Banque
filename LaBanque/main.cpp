#include <iostream>
#include "menu.h"
#include "comptebancaire.h"
using namespace std;

enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2,
    OPTION_3,
    QUITTER
};

int main()
{
    try {
        float montant;
        int choix;
        Menu leMenu("../LaBanque/compteBancaire.txt");
        CompteBancaire compte(5);

        do {
            choix = leMenu.Afficher();
            switch (choix)
            {
            case OPTION_1:
                cout << "Consultation du solde" << endl;
                cout <<compte.ConsulterSolde()<<endl;
                leMenu.AttendreAppuiTouche();

                break;

            case OPTION_2:
                cout << "Depot" << endl;
                cin >> montant;
                compte.Deposer(montant);
                cout << "Vous avez depose : "<<montant;
                leMenu.AttendreAppuiTouche();
                break;
            case OPTION_3:
                cout << "Retrait" << endl;
                cin >> montant;
                if(compte.Retirer(montant)==false){
                    cout <<"Solde insufisant pour effectuer l'operation"<<endl;
                }
                else {
                    cout <<"Vous avez retire : "<<montant<<endl;
                }

                leMenu.AttendreAppuiTouche();
                break;

            }

        }while(choix != QUITTER);




    } catch (Exception erreur) {
        erreur.ObtenirMessage();
        erreur.ObtenirCodeErreur();
        exit(EXIT_FAILURE);
    }

    return 0;
}
