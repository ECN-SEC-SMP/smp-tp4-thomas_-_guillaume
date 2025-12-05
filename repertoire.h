#pragma once

#include "type_def.h"

int rechercher(elementListe *liste, const personne &p);
int rechercherRec(elementListe *liste, const personne &p, int index);
elementListe *supprimer(elementListe *liste, const personne &p);