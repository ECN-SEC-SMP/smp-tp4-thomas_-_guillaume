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
#include "repertoire.h"

int main()
{
    personne *p1 = genererPersonne();
    personne *p3 = genererPersonne();

    affichagePersonne(*p1);
    affichagePersonne(*p3);

    std::string nom = genererNomPrenom("Noms_TP4.txt", 1000);
    std::string prenom = genererNomPrenom("Prenoms_TP4.txt", 11612);
    std::string tel = genererTel();

    cout << nom << " " << prenom << " " << tel << endl;
    cout << comparerPersonne(*p1, *p3) << endl;

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

    ajouter(*p1, elem);
    ajouter(*p2, elem);
    ajouter(*p3, elem);
    return 0;
}