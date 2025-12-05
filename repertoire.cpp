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

elementListe *supprimer(elementListe *liste, const personne &p)
{
    elementListe *actual = liste;
    elementListe *prec = liste->precedent;

    while (actual != nullptr)
    {
        // app
        if (egalitePersonne(actual->p, p))
        {
            if (prec != nullptr)
            {
                // changement du pointeur precedent qui pointe sur le nouveau suivant
                prec->suivant = actual->suivant;
            }
            if (actual->suivant != nullptr)
            {
                // changement du pointeur suivant qui pointe sur le nouveau precedent
                actual->suivant->precedent = prec;
            }
            delete actual;
            // delete pointeur
        }
        else
        {
            prec = actual;
        }
    }
    return liste;
}