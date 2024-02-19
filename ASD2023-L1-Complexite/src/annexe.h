/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : annexe.h
  Nom du labo : Labo 1 - Complexité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 21.02.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef LABO_1_ANNEXE_H
#define LABO_1_ANNEXE_H

#endif //LABO_1_ANNEXE_H
#include <iostream>
#include <vector>
#include <chrono>
#include <array>
#include <numeric>
#include <algorithm>
#include <random>
#include <cassert>
#include <cstdlib>

#include "OpCounter.h"
#include "tri.h"

enum TYPE_OF_SORT {
    INCREASING, DECREASING, RANDOM, ALMOST
};

template<typename T>
std::vector<T> generateVector(size_t n, unsigned seed, TYPE_OF_SORT t) ;

void testTri(const size_t nbrValeur);

string typeToString(TYPE_OF_SORT t);

void showMessage (size_t size, size_t affect, size_t comp, const string& typeSort, const string&  sortName);

template<typename T>
std::array<size_t,2> callMethodAndGiveActions(void (*methodToCall)(vector<T> &), vector<T> args, TYPE_OF_SORT currentType);

template<typename T>
std::array<size_t,2> callMethodAndGiveActions(void (*methodToCall)(T, T), T begin, T end,TYPE_OF_SORT currentType);

template<typename T>
chrono::duration<double, std::milli> callMethodAndGiveTime(void (*methodToCall)(vector<T> &), vector<T> args);

template<typename T>
chrono::duration<double, std::milli> callMethodAndGiveTime(void (*methodToCall)(T, T), T begin, T end);

void calculateTime(const vector<size_t>& nTested, const vector<TYPE_OF_SORT>& types, unsigned seed);

void countOperation (const vector<size_t>& nTested, const vector<TYPE_OF_SORT>& types, unsigned seed);

template<typename T>
void exportToCSV(const vector<T>& v);