#include "utilitaire_generation.h"
#include "utilitaires.h"

personne* genererPersonne(){
    std::string nom = genererNomPrenom("Noms_TP4.txt", 1000);
    std::string prenom = genererNomPrenom("Prenoms_TP4.txt", 11612);
    std::string tel = genererTel();
    personne* p1 = new personne{nom, prenom, tel};
    return p1;
}