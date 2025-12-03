#pragma once
#include "type_def.h"

personne *genererPersonne();
elementListe *creerElementListe(const personne &p);
void affichagePersonne(personne *p);
bool comparerPersonne(personne* p1, personne* p2);