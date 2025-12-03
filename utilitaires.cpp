#include "utilitaire_generation.h"
#include "utilitaires.h"

#include <iostream>
#include <ostream>

personne *genererPersonne()
{
  std::string nom = genererNomPrenom("Noms_TP4.txt", 1000);
  std::string prenom = genererNomPrenom("Prenoms_TP4.txt", 11612);
  std::string tel = genererTel();
  personne *p1 = new personne{nom, prenom, tel};
  return p1;
}

elementListe *creerElementListe(const personne &p)
{
  elementListe *nouv = new elementListe{p, nullptr, nullptr};
  return nouv;
}

void affichagePersonne(personne* p) {
  std::cout << p->nom << endl;
  std::cout << p->prenom << endl;
  std::cout << p->telephone << endl;
}