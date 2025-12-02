#include "repertoire.h"

int rechercher(elementListe *liste, const personne &p)
{
  elementListe *actuel = liste;
  int index = 0;

  while (actuel != nullptr)
  {
    if (actuel->p.nom == p.nom && actuel->p.prenom == p.prenom && actuel->p.telephone == p.telephone)
    {
      return index; // personne trouvée retourner l'indice
    }
    actuel = actuel->suivant;
    index++;
  }

  return -1; // personne non trouvée
}