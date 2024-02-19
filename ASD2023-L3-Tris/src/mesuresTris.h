/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : mesuresTris.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier d'en-tête des fonctions pour les mesures de temps

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef ASD_LABOS_2021_MESURESTRIS_H
#define ASD_LABOS_2021_MESURESTRIS_H

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <string>

#include "triParBase.h"
#include "triRapide.h"
#include "some_bits.h"
#include "csv.h"

/*******************************************************************************************************************/

// liste des différents type de tris
enum TYPE_TRI {
    CROISSANT, DECROISSANT, ALEATOIRE, PRESQUE_TRIE
};

/*******************************************************************************************************************/

// nom         index_fn
// but         Calcule la position de l'index de la valeur passée en paramètre
//
// param       size_t : valeur d'un itérateur
//
// return      size_t : position de l'index
// exception   n/a
size_t index_fn(size_t valeur);

/*******************************************************************************************************************/

// nom         calculTempsTri
// but         Calcule le temps effectuer par la fonction passée par paramètre
//
// param       void (*tri)(T,T) : fonction passée en paramètre
//             T first : Itérateur de début
//             T last  : Itérateur de fin
//
// return      chrono::duration<double, std::milli> : temps en milliseconde de la fonction du tri effectué
// exception   n/a
template<typename T>
std::chrono::duration<double, std::milli> calculTempsTri(void (*tri)(T, T), T first, T last);

/*******************************************************************************************************************/

// nom         genererVecteur
// but         Génére un vecteur de type T d'une taille choisie et pré-Triée selon le choix
//
// param       size_t taille : Nombre de valeurs contenues dans le vecteur
//             TYPE_TRI      : Choix du type de tri : CROISSANT, DECROISSANT, ALEATOIRE ou PRESQUE_TRIE
//
// return      vector<T> : vecteur générer
// exception   n/a
template<typename T>
std::vector<T> genererVecteur(size_t taille, TYPE_TRI typeTri);

/*******************************************************************************************************************/

// nom         calculTempsTris
// but         Fonction principale qui permet de calculer en milliseconde les différants types de tris selon les
//             tailles indiquées
//
// param       const vector<TYPE_TRI> &typesTri : Tableau des différents tri à faire
//             const vector<size_t>& tailles    : tableau des tailles de vecteur à tester
//
// return      void
// exception   n/a
template<typename T, typename Iterator>
void calculTempsTris(const std::vector<TYPE_TRI> &typesTri, const std::vector<std::size_t>& tailles);

/*******************************************************************************************************************/

#include "mesureTris_impl.h"

#endif //ASD_LABOS_2021_MESURESTRIS_H
