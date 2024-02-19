/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : mainTestTris.cpp
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Programme principal pour le test des différents tris

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include "testTris_impl.h"

using namespace std;

int main() {

   cout << "=======================================================================================" << endl << endl;

   //Test partition---------------------------------------------------------------
   std::vector<size_t> vPartition = genererVecteur<size_t>(25, ALEATOIRE);
   testPartition<size_t, vector<size_t>::iterator>(vPartition);
   //Fin du test partition   -----------------------------------------------------

   cout << "=======================================================================================" << endl << endl;

   //Test Tri rapide--------------------------------------------------------------
   std::vector<size_t> vTriRapide = genererVecteur<size_t>(25, ALEATOIRE);
   testTriRapide<size_t, vector<size_t>::iterator>(vTriRapide);
   //Fin du test du tri rapide-----------------------------------------------------

   cout << "=======================================================================================" << endl << endl;

   //Test Tri comptage---------------------------------------------------------------
   std::vector<size_t> vTriComptage = genererVecteur<size_t>(25, ALEATOIRE);
   testTriComptage<size_t>(vTriComptage);
   //Fin du test du tri comptage-----------------------------------------------------

   cout << "=======================================================================================" << endl << endl;

   //Test Tri radix---------------------------------------------------------------
   std::vector<size_t> vTriParBase1 = genererVecteur<size_t>(25, ALEATOIRE);
   testTriParBase<size_t, vector<size_t>::iterator, 1>(vTriParBase1);
   cout << "---------------------------------------------------------------------------------------" << endl << endl;
   std::vector<size_t> vTriParBase2 = genererVecteur<size_t>(25, ALEATOIRE);
   testTriParBase<size_t, vector<size_t>::iterator, 2>(vTriParBase2);
   cout << "---------------------------------------------------------------------------------------" << endl << endl;
   std::vector<size_t> vTriParBase4 = genererVecteur<size_t>(25, ALEATOIRE);
   testTriParBase<size_t, vector<size_t>::iterator, 3>(vTriParBase4);
   cout << "---------------------------------------------------------------------------------------" << endl << endl;
   std::vector<size_t> vTriParBase8 = genererVecteur<size_t>(25, ALEATOIRE);
   testTriParBase<size_t, vector<size_t>::iterator, 8>(vTriParBase8);
   cout << "---------------------------------------------------------------------------------------" << endl << endl;
   std::vector<size_t> vTriParBase16 = genererVecteur<size_t>(25, ALEATOIRE);
   testTriParBase<size_t, vector<size_t>::iterator, 16>(vTriParBase16);
   //Fin du test du tri radix-----------------------------------------------------

   cout << "=======================================================================================" << endl << endl;

   return EXIT_SUCCESS;
}