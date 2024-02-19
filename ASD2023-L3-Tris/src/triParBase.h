/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : triParBase.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier d'en-tête des fonctions triParBase

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef ASD_LABOS_2021_TRIPARBASE_H
#define ASD_LABOS_2021_TRIPARBASE_H

#include <iterator>
#include <type_traits>
#include <limits>
#include <algorithm>
#include <vector>
#include "some_bits.h"

// nom         tri_comptage
// but         Trie un vecteur par groupes de caractèristiques
//
// param       Iterator first          :  Itérateur indiquant le début de la plage (gauche)
//             Iterator last           :  Itérateur indiquant la fin de la plage (droite)
//             Iterator output_first   :  Itérateur indiquant la zone a écrire
//             Fn index_fn             :  Indique de quel groupe appartient l'itérateur en cours
//             size_t N                :  Nombre de groupes (compteurs)
//
// return      void
// exception   n/a
template<typename Iterator, typename Fn>
void tri_comptage(Iterator first, Iterator last, Iterator output_first, Fn index_fn, size_t N);

// nom         tri_par_base
// but         Trie un vecteur par dans l'ordre croissant en se basant sur des groupes de caractèristiques
//
// param       Iterator first   : Itérateur indiquant le début de la plage (gauche)
//             Iterator last    : Itérateur indiquant la fin de la plage (droite)
//             size_t   NBITS   : Nombre de Bits utilisés pour le shift à gauche
//
// return      void
// exception   n/a
template<typename Iterator, size_t NBITS>
void tri_par_base(Iterator first, Iterator last);

#include "triParBase_impl.h"

#endif //ASD_LABOS_2021_TRIPARBASE_H
