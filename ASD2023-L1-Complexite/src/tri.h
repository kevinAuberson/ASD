/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : tri.h
  Nom du labo : Labo 1 - Complexité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 21.02.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef LABO_1_TRI_H
#define LABO_1_TRI_H

#include <vector>
#include "OpCounter.h"

template<typename T>
void tri_bulles(std::vector<T>& t);

template<typename T>
void tri_par_selection(std::vector<T>& t);

template<typename T>
void tri_par_insertion(std::vector<T>& t);


template<typename T>
void tri_bulles(T begin, T end);

template<typename T>
void tri_par_selection(T begin, T end);

template<typename T>
void tri_par_insertion(T begin, T end);

#include "tri_impl.h"

#endif //LABO_1_TRI_H
