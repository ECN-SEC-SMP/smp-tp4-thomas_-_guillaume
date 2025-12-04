#include "repertoire.h"
#include "utilitaires.h"

int rechercher(elementListe *liste, const personne &p)
{
    elementListe *actuel = liste;
    int index = 0;

    while (actuel != nullptr)
    {
        if (egalitePersonne(actuel->p, p))
        {
            return index; // personne trouvée retourner l'indice
        }
        actuel = actuel->suivant;
        index++;
    }

    return -1; // personne non trouvée
}