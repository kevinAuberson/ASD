/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : mainMesureTris.cpp
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Programme principal pour le calcul des temps des différents tris

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include "mesuresTris.h"

using namespace std;

int main() {

   const vector<TYPE_TRI> tris  = {CROISSANT, DECROISSANT, ALEATOIRE, PRESQUE_TRIE};
   const vector<size_t> tailles = {10,100,1000,10000,100000,1000000};

   calculTempsTris<unsigned int, vector<unsigned int>::iterator>(tris,tailles);

   return EXIT_SUCCESS;

}