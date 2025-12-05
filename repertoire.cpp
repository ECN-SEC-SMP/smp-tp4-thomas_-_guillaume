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

// version récursive de la fonction rechercher (obligé d'ajouter un paramètre index)
int rechercherRec(elementListe *liste, const personne &p, int index)
{
    if (liste == nullptr) // fin de la liste
    {
        return -1; // personne non trouvée
    }
    if (egalitePersonne(liste->p, p)) // personne trouvée
    {
        return index; // retourner l'indice
    }
    return rechercherRec(liste->suivant, p, index + 1); // appel récursif avec l'élément suivant et l'indice incrémenté
}