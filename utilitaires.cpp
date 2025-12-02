#include "utilitaire_generation.h"
#include "utilitaires.h"

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

bool egalitePersonne(const personne &p1, const personne &p2)
{
  return (p1.nom == p2.nom) && (p1.prenom == p2.prenom) && (p1.telephone == p2.telephone);
}