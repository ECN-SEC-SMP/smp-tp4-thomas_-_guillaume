/*
 * Nom1 Nom2
 * TP4
 *
 * .......
 *
 */

#include <iostream>
#include "utilitaire_generation.h"
#include "type_def.h"
#include "utilitaires.h"

int main()
{
    personne *p1 = genererPersonne();
    std::string nom = genererNomPrenom("Noms_TP4.txt", 1000);
    std::string prenom = genererNomPrenom("Prenoms_TP4.txt", 11612);
    std::string tel = genererTel();
    cout << nom << " " << prenom << " " << tel << endl;

    // test creerElementListe
    elementListe *elem = creerElementListe(*p1);
    cout << elem->p.nom << " " << elem->p.prenom << " " << elem->p.telephone << endl;

    // test egalitePersonne
    personne *p2 = new personne{nom, prenom, tel};
    if (egalitePersonne(*p1, *p2))
    {
        cout << "Les deux personnes sont égales." << endl;
    }
    else
    {
        cout << "Les deux personnes sont différentes." << endl;
    }

    return 0;
}