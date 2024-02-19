/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : testTris.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier d'en-tête des fonctions pour les test des Tris

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef ASD_LABOS_2021_TESTTRIS_H
#define ASD_LABOS_2021_TESTTRIS_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>

/*******************************************************************************************************************/

// nom         afficherVecteur
// but         Affiche les valeurs contenues dans un vecteur
//
// param       const std::vector<T>& vecteur : Vecteur à afficher
//
// return      void
// exception   n/a
template<typename T>
void afficherVecteur(const std::vector<T>& vecteur);

//*****************************************************************************************************************//

// nom         testPartition
// but         teste la fonction "partition" sur un vecteur passé en paramètres
//
// param       const std::vector<T>& vecteur : Vecteur à trier
//
// return      void
// exception   n/a
template<typename T, typename Iterator>
void testPartition(std::vector<T> vecteur);

//*****************************************************************************************************************//

// nom         testTriRapide
// but         teste la fonction "triRapide" sur un vecteur passé en paramètres
//
// param       const std::vector<T>& vecteur : Vecteur à trier
//
// return      void
// exception   n/a
template<typename T, typename Iterator>
void testTriRapide(std::vector<T> vecteur);

//*****************************************************************************************************************//

// nom         testTriComptage
// but         teste la fonction "triComptage" sur un vecteur passé en paramètres
//
// param       const std::vector<T>& vecteur : Vecteur à trier
//
// return      void
// exception   n/a
template<typename T>
void testTriComptage(std::vector<T> vecteur);

//*****************************************************************************************************************//

// nom         testTriParBase
// but         teste la fonction "triParBase" sur un vecteur passé en paramètres
//
// param       const std::vector<T>& vecteur : Vecteur à trier
//             size_t NBITS : nombre de bits pour le décalage du tri
//
// return      void
// exception   n/a
template<typename T, typename Iterator, size_t NBITS>
void testTriParBase(std::vector<T> vecteur);

//*****************************************************************************************************************//

#include "testTris_impl.h"

#endif //ASD_LABOS_2021_TESTTRIS_H
