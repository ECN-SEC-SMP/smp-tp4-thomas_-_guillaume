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


| Structure | Création (N=1000) | Affichage (N=1000) | Recherche (100 pers.) | Suppression (100 pers.) |
|-----------|-------------------|---------------------|------------------------|--------------------------|
| Tableau   | 6.3e-05 s         | 0.01363 s           | 0.000109 s             | 0.005899 s               |
| Liste     | 0.013436 s        | 0.014343 s          | 0.001133 s             | 0.002468 s               |

### Analyse des performances

#### Création
- **Tableau**  
  Les personnes sont simplement copiées les unes à la suite des autres en mémoire.  
  Une seule passe suffit → temps de création très faible.
- **Liste chaînée**  
  Chaque nouvelle personne doit être insérée au bon endroit dans une liste déjà triée.  
  Pour l’insérer, il faut d’abord parcourir la liste pour trouver sa position, et plus la liste est longue, plus cela prend de temps.  
  Au final, la création d’une liste triée est beaucoup plus lente que la création du tableau.

#### Affichage
- **Tableau et liste**  
  Pour afficher, on parcourt tous les éléments et on les envoie vers la sortie (console).  
  Le temps passé est surtout dû à l’affichage lui-même (I/O), pas à la structure de données.  
  C’est pour ça que les temps sont très proches pour les deux structures.

#### Recherche
- **Tableau**  
  La recherche se fait en regardant les personnes une par une depuis le début jusqu’à trouver la bonne.  
  Les données étant stockées côte à côte en mémoire, le processeur les lit très efficacement → temps de recherche plus faible.
- **Liste chaînée**  
  Même principe : on parcourt les éléments un par un.  
  En revanche, chaque accès passe par un pointeur vers l’élément suivant, ce qui est moins efficace pour le processeur → temps de recherche plus élevé que pour le tableau.

#### Suppression
- **Tableau**  
  Une fois la personne trouvée, tous les éléments qui suivent doivent être décalés d’une case pour boucher le “trou”.  
  Pour plusieurs suppressions, ce décalage répété coûte cher en temps → le tableau est désavantagé.
- **Liste chaînée**  
  Une fois la personne trouvée, il suffit de mettre à jour quelques pointeurs (précédent/suivant).  
  Aucun décalage massif de données → chaque suppression est rapide, ce qui explique les meilleurs temps sur 100 suppressions.

#### Synthèse
- Le **tableau** est plus adapté quand on fait surtout de la **recherche** et du **parcours** (lecture des données), avec peu de modifications.
- La **liste chaînée** devient intéressante quand on fait beaucoup de **suppressions** (et insertions), car ces opérations sont plus rapides une fois l’élément trouvé.

Globalement, les mesures obtenues sont cohérentes avec le comportement attendu des deux structures.

---
## 5) Conclusion