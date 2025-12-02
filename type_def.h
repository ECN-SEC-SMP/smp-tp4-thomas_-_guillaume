#pragma once
#include <string>

typedef struct
{
  std::string nom;
  std::string prenom;
  std::string telephone;
} personne;

typedef struct elementListe
{
  personne personne;
  struct elementListe *suivant;   // pointeur vers l'élément suivant
  struct elementListe *precedent; // pointeur vers l'élément précédent
} elementListe;