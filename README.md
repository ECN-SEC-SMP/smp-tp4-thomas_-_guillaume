# SMP – TP4 – Liste personnes

## 1) Introduction
Objectif: Réaliser un algorithme permettant de manipuler els structures de données et de comparer les temps d'exécution des opérations de base (ajout, recherche, suppression, affichage).

---
## 2) Fichiers utilisés
- `repertoire.h/.cpp` : Contient les fonctions pour afficher, ajouter, rechercher et supprimer les éléments dans un élément liste.
- `utilitaire_generation.h/.cpp` : Contient les méthodes pour renvoyer des prénoms, noms et numéros de téléphones aléatoire.
- `main.cpp` : Jeux d'essais des différentes méthodes.
- `utilitaires.h/.cpp` : Contient les méthodes pour générerer les personnes et éléments liste, afficher les informations d'une personne et tester l'égalité et comparer.
- `type_def.h` : Contient les structures de personnes et d'éléments listes. 

---
## 3) Structures
### A. `personne(string nom, string prenom, string telephone)`
- **Spécification** : Structure pour une personne qui contient un nom, un prénom et un numéro de téléphone.
- **Principe** : Tous les champs sont des chaines de caractères.

### B. `elementListe(personne p, elementListe *suivant, elementListe *precedent)`
- **Spécification** : Structure pour elementListe qui contient une personne et un pointeur suivant pour pointer vers l'élément suivant et un pointeur précédent pour pointer sur l'élément précédent.

---
## 4) Fonctions

---
## 5) Validations

---
## 5) Conclusion