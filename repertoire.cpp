#include "repertoire.h"

elementListe *ajouter(personne &p1, elementListe *listeElement)
{
    elementListe *teteListe = listeElement;
    elementListe *actuel = listeElement;
    while (actuel != nullptr)
    {
        if (egalitePersonne(p1, actuel->p))
        {
            return teteListe;
        }
        // Si p1 est devant actuel->p
        if (!comparerPersonne(p1, actuel->p))
        {
            elementListe *newElement = new elementListe;
            newElement->p = p1;
            newElement->suivant = actuel;              // p1 est avant actuel
            newElement->precedent = actuel->precedent; // p1 est après actuel->prec
            if (actuel->precedent != nullptr)
            {
                actuel->precedent->suivant = newElement; // oui
            }
            actuel->suivant = newElement; // ligne de fdp
            return teteListe;
        }
        else if (actuel->suivant == nullptr)
        {
            elementListe *newElement = new elementListe;
            newElement->p = p1;
            newElement->suivant = nullptr;
            newElement->precedent = actuel;
            if (actuel->precedent != nullptr)
            {
                actuel->suivant = newElement;
            }
            return teteListe;
        }
        actuel = actuel->suivant;
    }
    return teteListe;
}