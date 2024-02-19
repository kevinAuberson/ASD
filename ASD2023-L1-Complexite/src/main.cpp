/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : main.cpp
  Nom du labo : Labo 1 - Complexité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 21.02.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>


#include "annexe.h"

using namespace std;

int main() {

    vector<size_t> nTested = {100, 1000, 10000};
    vector<TYPE_OF_SORT> types = {INCREASING, DECREASING, RANDOM, ALMOST};
    unsigned seed = 98765;

    calculateTime(nTested, types, seed);

    countOperation(nTested, types, seed);
    return EXIT_SUCCESS;
}
