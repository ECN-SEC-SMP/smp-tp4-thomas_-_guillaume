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

void affichagePersonne(personne *p)
{
  std::cout << p->nom << endl;
  std::cout << p->prenom << endl;
  std::cout << p->telephone << endl;
}

bool egalitePersonne(const personne &p1, const personne &p2)
{
  return (p1.nom == p2.nom) && (p1.prenom == p2.prenom) && (p1.telephone == p2.telephone);
}

bool comparerPersonne(personne *p1, personne *p2)
{
  if (p1->nom < p2->nom)
  {
    return true;
  }
  else
  {
    return false;
  }
  if (p1->prenom < p2->prenom)
  {
    return true;
  }
  else
  {
    return false;
  }
  if (p1->telephone < p2->telephone)
  {
    return true;
  }
  else
  {
    return false;
  }
}