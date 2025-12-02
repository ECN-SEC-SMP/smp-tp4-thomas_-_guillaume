#include " utilitaires.h"

elementListe *creerElementListe(const personne &p)
{
  elementListe *nouv = new elementListe{p, nullptr, nullptr};
  return nouv;
}