/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : OpCounter.h
  Nom du labo : Labo 1 - Complexité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 21.02.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef LABO_1_OPCOUNTER_H
#define LABO_1_OPCOUNTER_H

#include "cstdlib"
#include <iostream>


class [[maybe_unused]] OpCounter {


public:
    OpCounter();

    OpCounter(size_t i);

    OpCounter &operator= (const OpCounter &rhs);

    bool operator<  (const OpCounter &rhs) const;
    bool operator>  (const OpCounter &rhs) const;
    bool operator== (const OpCounter &rhs) const;
    bool operator<= (const OpCounter &rhs) const;
    bool operator>= (const OpCounter &rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const OpCounter& val) {
       os << val.getValue();
       return os;
    }

    static inline long counterAffect = 0;
    static inline long counterComp = 0;

    static void resetCounters();

    int getValue() const;
    void setValue(int v);

    std::size_t value;
};


#endif
