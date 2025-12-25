/*
 * Nom1 Nom2
 * TP4
 *
 * .......
 *
 */

#include <iostream>
#include <ctime> // clock()
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
    afficherElementListe(elem);

    // test rechercher
    elementListe *liste = nullptr;
    liste = creerElementListe(*p1);
    liste->suivant = creerElementListe(*p2);
    liste->suivant->precedent = liste;
    int index = rechercher(liste, *p2);
    cout << "Index de la personne recherchée : " << index << endl;
    // test rechercherRec
    index = rechercherRec(liste, *p2, 0);
    cout << "Index de la personne recherchée (récursif) : " << index << endl;
    // test supprimer
    liste = supprimer(liste, *p1);
    index = rechercher(liste, *p1);
    cout << "Index de la personne supprimée : " << index << endl; // toujours -1 normalement

    // test performance tableau vs liste chaînée

    const int N = 1000;
    const int K = 100;

    personne tabGen[N];                // personnes générées une fois pour toutes
    personne tab[N];                   // répertoire sous forme de tableau
    elementListe *listeTest = nullptr; // répertoire sous forme de liste

    clock_t t1, t2;
    double dtTab, dtListe;

    // temps pour chaque opération
    double tCreateTab, tCreateListe;
    double tAffTab, tAffListe;
    double tSearchTab, tSearchListe;
    double tSuppTab, tSuppListe;

    std::cout << "Test sur " << N << " personnes" << std::endl;

    // generation des personnes
    for (int i = 0; i < N; ++i)
    {
        personne *p = genererPersonne();
        tabGen[i] = *p;
        delete p;
    }

    // création du répertoire sous forme de tableau
    t1 = clock();
    for (int i = 0; i < N; ++i)
    {
        tab[i] = tabGen[i];
    }
    t2 = clock();
    dtTab = double(t2 - t1) / CLOCKS_PER_SEC;
    tCreateTab = dtTab;

    // création du répertoire sous forme de liste chaînée
    t1 = clock();
    for (int i = 0; i < N; ++i)
    {
        listeTest = ajouter(tabGen[i], listeTest); // ajouter(personne&, liste) renvoie la nouvelle tête
    }
    t2 = clock();
    dtListe = double(t2 - t1) / CLOCKS_PER_SEC;
    tCreateListe = dtListe;

    // affichage du répertoire sous forme de tableau
    t1 = clock();
    for (int i = 0; i < N; ++i)
    {
        affichagePersonne(tab[i]);
    }
    t2 = clock();
    dtTab = double(t2 - t1) / CLOCKS_PER_SEC;
    tAffTab = dtTab;

    // affichage du répertoire sous forme de liste chaînée
    t1 = clock();
    afficherElementListe(listeTest);
    t2 = clock();
    dtListe = double(t2 - t1) / CLOCKS_PER_SEC;
    tAffListe = dtListe;

    // recherche de 100 personnes dans le répertoire
    t1 = clock();
    for (int k = 0; k < K; ++k)
    {
        const personne &cible = tab[k];
        int pos = -1;

        for (int i = 0; i < N; ++i)
        {
            if (egalitePersonne(tab[i], cible))
            {
                pos = i;
                break;
            }
        }
        (void)pos;
    }
    t2 = clock();
    dtTab = double(t2 - t1) / CLOCKS_PER_SEC;
    tSearchTab = dtTab;

    // recherche de 100 personnes dans la liste chaînée
    t1 = clock();
    for (int k = 0; k < K; ++k)
    {
        const personne &cible = tab[k];
        int pos = rechercher(listeTest, cible);
        (void)pos;
    }
    t2 = clock();
    dtListe = double(t2 - t1) / CLOCKS_PER_SEC;
    tSearchListe = dtListe;

    // suppression de 100 personnes du répertoire
    int tailleTab = N;

    t1 = clock();
    for (int k = 0; k < K && tailleTab > 0; ++k)
    {
        for (int i = 1; i < tailleTab; ++i)
        {
            tab[i - 1] = tab[i];
        }
        --tailleTab;
    }
    t2 = clock();
    dtTab = double(t2 - t1) / CLOCKS_PER_SEC;
    tSuppTab = dtTab;

    // suppression de 100 personnes de la liste chaînée
    t1 = clock();
    for (int k = 0; k < K; ++k)
    {
        const personne &cible = tabGen[k]; // on prend les mêmes personnes que celles générées
        listeTest = supprimer(listeTest, cible);
    }
    t2 = clock();
    dtListe = double(t2 - t1) / CLOCKS_PER_SEC;
    tSuppListe = dtListe;

    // affichage des résultats
    std::cout << "\n================= RESUME DES TEMPS =================\n";
    std::cout << "Creation (N = " << N << ")\n";
    std::cout << "  Tableau : " << tCreateTab << " s\n";
    std::cout << "  Liste   : " << tCreateListe << " s\n\n";

    std::cout << "Affichage (N = " << N << ")\n";
    std::cout << "  Tableau : " << tAffTab << " s\n";
    std::cout << "  Liste   : " << tAffListe << " s\n\n";

    std::cout << "Recherche (" << K << " personnes)\n";
    std::cout << "  Tableau : " << tSearchTab << " s\n";
    std::cout << "  Liste   : " << tSearchListe << " s\n\n";

    std::cout << "Suppression (" << K << " personnes)\n";
    std::cout << "  Tableau : " << tSuppTab << " s\n";
    std::cout << "  Liste   : " << tSuppListe << " s\n";
    std::cout << "====================================================\n";
    return 0;
}