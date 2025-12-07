#include "repertoire.h"

// Fonction pour ajouter une personne dans une liste
elementListe *ajouter(personne &p1, elementListe *listeElement)
{
    // *** CAS LISTE VIDE ***
    if (listeElement == nullptr)
    {
        elementListe *newElement = new elementListe;
        newElement->p = p1;
        newElement->suivant = nullptr;
        newElement->precedent = nullptr;
        return newElement; // nouvelle tête de liste
    }

    // On garde la tête de liste pour retourner la
    elementListe *teteListe = listeElement;
    elementListe *actuel = listeElement;
    while (actuel->precedent != nullptr)
        actuel = actuel->precedent;

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
            return teteListe;               // On retourne la tête de liste
        }
        else if (actuel->suivant == nullptr) // Si on arrive à la fin de la liste
        {
            // On créé le nouveau élément liste qui doit se trouver devant actuel->p
            elementListe *newElement = new elementListe;
            newElement->p = p1;
            newElement->suivant = nullptr;  // Le nouvel élément n'a pas de suivant car dernier de la liste
            newElement->precedent = actuel; // Le nouvel élément à pour précédent l'ancien dernier élément
            actuel->suivant = newElement;
            return teteListe;
        }
        actuel = actuel->suivant;
    }
    return teteListe;
}

// Fonction pour afficher les personnes dans un liste élément
void afficherElementListe(elementListe *listeElement)
{
    elementListe *actuel = listeElement;
    while (actuel != nullptr)
    {
        affichagePersonne(actuel->p);
        actuel = actuel->suivant;
    }
}

// Fonction renvoyant l'index d'une personne dans une liste
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

// Version récursive de la fonction rechercher (obligé d'ajouter un paramètre index)
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

// Fonction pour supprimer une personne d'une liste
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
        actual = actual->suivant;
    }
    return liste;
}