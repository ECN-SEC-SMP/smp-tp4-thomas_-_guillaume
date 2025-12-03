/*
 * Nom1 Nom2
 * TP4 
 * 
 * .......
 * 
 */


#include <iostream>
#include "utilitaire_generation.h"
#include "type_def.h"
#include "utilitaires.h"

int main(){
    personne* p1 = genererPersonne();
    affichagePersonne(p1);
    std::string nom = genererNomPrenom("Noms_TP4.txt", 1000);
    std::string prenom = genererNomPrenom("Prenoms_TP4.txt", 11612);
    std::string tel = genererTel();
    cout<< nom<<" "<<prenom<<" "<<tel<<endl;
    return 0;
}