#include "repertoire.h"

elementListe* ajouter(personne* p1, elementListe* listeElement){
    elementListe *actuel = listeElement;
    while (actuel != nullptr) {
        if (!comparerPersonne(p1,actuel->personne)) {
            elementListe* newElement = new elementListe(p1, actuel, actuel->precedent);
            actuel->precedent->suivant = newElement;
            actuel->precedent = newElement;
        }
        actuel = actuel->suivant;
    }
    return actuel;
}