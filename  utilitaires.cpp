#include "utilitaire_generation.h"
#include "utilitaires.h"

personne genererPersonne(){
    string nom = genererNomPrenom("Noms_TP4.txt", 1000);
    string prenom = genererNomPrenom("Prenoms_TP4.txt", 11612);
    string tel = genererTel();
    return new personne(nom, prenom, tel);
}