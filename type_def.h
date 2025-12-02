#pragma once

typedef struct elementListe
{
  personne personne;
  struct elementListe *suivant;   // pointeur vers l'élément suivant
  struct elementListe *precedent; // pointeur vers l'élément précédent
} elementListe;