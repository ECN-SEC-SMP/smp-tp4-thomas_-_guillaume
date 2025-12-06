#pragma once
#include "type_def.h"
#include "utilitaires.h"

elementListe *ajouter(personne &p1, elementListe *listeElement);
void afficherElementListe(elementListe *liste);

int rechercher(elementListe *liste, const personne &p);
int rechercherRec(elementListe *liste, const personne &p, int index);
elementListe *supprimer(elementListe *liste, const personne &p);