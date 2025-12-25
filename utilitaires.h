#pragma once
#include "type_def.h"
#include "utilitaire_generation.h"

#include <iostream>
#include <ostream>

personne *genererPersonne();
elementListe *creerElementListe(const personne &p);
void affichagePersonne(personne &p);
bool egalitePersonne(const personne &p1, const personne &p2);
bool comparerPersonne(personne &p1, personne &p2);