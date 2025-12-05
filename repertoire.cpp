#include "repertoire.h"

// Fonction pour ajouter une personne dans une liste
elementListe *ajouter(personne &p1, elementListe *listeElement)
{
    // On garde la tête de liste pour retourner la
    elementListe *teteListe = listeElement;
    elementListe *actuel = listeElement;
    while (actuel->precedent != nullptr) actuel = actuel->precedent;

    while (actuel != nullptr)
    {
        if (egalitePersonne(p1, actuel->p))
        {
            return teteListe;
        }
        // Si p1 est devant actuel->p
        if (!comparerPersonne(p1, actuel->p))
        {
            // On créé le nouveau élément liste qui doit se trouver devant actuel->p
            elementListe *newElement = new elementListe;
            newElement->p = p1;
            newElement->suivant = actuel;              // p1 est devant actuel
            newElement->precedent = actuel->precedent; // p1 est après le précédent de actuel
            if (actuel->precedent != nullptr)          // S'il y a un élément derrière actuel
            {
                actuel->precedent->suivant = newElement; // On met à jour le suivant de l'élément précédent
            }
            actuel->precedent = newElement; // L'élément précédent de actuel est l'élément ajouté
            return teteListe; // On retourne la tête de liste
        }
        else if (actuel->suivant == nullptr) // Si on arrive à la fin de la liste
        {
            // On créé le nouveau élément liste qui doit se trouver devant actuel->p
            elementListe *newElement = new elementListe;
            newElement->p = p1;
            newElement->suivant = nullptr; // Le nouvel élément n'a pas de suivant car dernier de la liste
            newElement->precedent = actuel; // Le nouvel élément à pour précédent l'ancien dernier élément
            actuel->suivant = newElement;
            return teteListe;
        }
        actuel = actuel->suivant;
    }
    return teteListe;
}

void afficherElementListe(elementListe *listeElement) {
    elementListe *actuel = listeElement;
    while (actuel != nullptr) {
        affichagePersonne(actuel->p);
        actuel = actuel->suivant;
    }
}