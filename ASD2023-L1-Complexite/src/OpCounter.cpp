/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : OpCounter.cpp
  Nom du labo : Labo 1 - Complexité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 21.02.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#include "OpCounter.h"

OpCounter &OpCounter::operator=(const OpCounter &rhs) {
   OpCounter::counterAffect++;
    setValue(rhs.getValue());
    return *this;
}

bool OpCounter::operator< (const OpCounter& rhs) const{
    OpCounter::counterComp++;
    return value < rhs.getValue();
}

bool OpCounter::operator> (const OpCounter& rhs) const{
    OpCounter::counterComp++;
    return value > rhs.getValue();
}

bool OpCounter::operator== (const OpCounter &rhs) const {
   OpCounter::counterComp++;
    return value == rhs.getValue();
}

bool OpCounter::operator<=(const OpCounter &rhs) const{
   OpCounter::counterComp++;
    return value <= rhs.getValue();
}

bool OpCounter::operator>=(const OpCounter &rhs) const{
   OpCounter::counterComp++;
    return value >= rhs.getValue();
}

void OpCounter::resetCounters() {
   OpCounter::counterComp = 0;
   counterAffect = 0;
}

OpCounter::OpCounter(size_t value) {
    OpCounter::counterAffect++;
    this->value = value;
}

int OpCounter::getValue() const {
    return value;
}

void OpCounter::setValue(int v) {
    value = v;
}

OpCounter::OpCounter() {

}


