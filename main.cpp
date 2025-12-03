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
using namespace std;


int main(){
    new personne p1 = genererPersonne();
    string nom = genererNomPrenom("Noms_TP4.txt", 1000);
    string prenom = genererNomPrenom("Prenoms_TP4.txt", 11612);
    string tel = genererTel();
    cout<< nom<<" "<<prenom<<" "<<tel<<endl;
    return 0;
}