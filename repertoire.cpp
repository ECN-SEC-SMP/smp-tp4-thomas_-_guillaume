#include "repertoire.h"

elementListe* ajouter(personne &p1, elementListe* listeElement){
    elementListe *actuel = listeElement;
    while (actuel != nullptr) {
        if (egalitePersonne(p1, actuel->p))
        {
            return listeElement;
        }
        // Si p1 est devant actuel->p
        if (!comparerPersonne(p1,actuel->p)) {
            elementListe* newElement = new elementListe;
            newElement->p = p1;
            newElement->suivant = actuel;
            newElement->precedent = actuel->precedent;
            if (actuel->precedent != nullptr)
            {
                actuel->precedent->suivant = newElement;
            }
            actuel->suivant = newElement;
        }
        if (actuel->suivant == nullptr)
        {
            elementListe* newElement = new elementListe;
            newElement->p = p1;
            newElement->suivant = nullptr;
            newElement->precedent = actuel;
            if (actuel->precedent != nullptr)
            {
                actuel->suivant = newElement;
            }
        }
        actuel = actuel->suivant;
    }
    return actuel;
}