/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : triRapide.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier d'en-tête des fonctions triRapide

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/


#ifndef ASD_LABOS_2021_TRIRAPIDE_H
#define ASD_LABOS_2021_TRIRAPIDE_H
#include <ctime>


// nom         partition
// but         Génere une valeur aléatoire permetant de trouver un nouveau pivot
//
// param       Iterator first   : Itérateur indiquant le début de la plage (gauche)
//             Iterator last    : Itérateur indiquant la fin de la plage (droite)
//
// return      size_t : valeure aléatoire permetant de trouver un nouveau pivot
// exception   n/a
template<typename Iterator>
std::size_t aleatoire(Iterator first, Iterator last);

// nom         partition
// but         Trie un vecteur selon un pivot et retourne le nouveau pivot (1 itération par appel)
//
// param       Iterator first   : Itérateur indiquant le début de la plage (gauche)
//             Iterator last    : Itérateur indiquant la fin de la plage (droite)
//
// return      Iterator : retroune l'itérateur du pivot calculé
// exception   n/a
template<typename Iterator>
Iterator partition(Iterator first, Iterator last);

// nom         tri_rapide
// but         Trie un vecteur avec l'algorithme de tri rapide (pivots)
//
// param       Iterator first   : Itérateur indiquant le début de la plage (gauche)
//             Iterator last    : Itérateur indiquant la fin de la plage (droite)
//
// return      void
// exception   n/a
template<typename Iterator>
void tri_rapide(Iterator first, Iterator last);

#include "triRapide_impl.h"

#endif //ASD_LABOS_2021_TRIRAPIDE_H
