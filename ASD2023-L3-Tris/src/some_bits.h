/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : some_bits.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier contenant le foncteur pour extraire certains bits d'un nombre de type T

  Remarque(s) : Ce fichier à été fournis pour le laboratoire, mis a part les commentaires rien n'a été modifié ni
                même son nom. (Pour respecter la "norme" il aurait fallu renomer ce fichier someBits_impl.h et
                créer un fichier .h contenant une invocation commentée du foncteur ci-dessous.)

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef SOME_BITS
#define SOME_BITS

template<typename T>
class SomeBits {
    size_t shift;
    T mask;
public:
    SomeBits(size_t nombreDeBits, size_t part)
            : shift(part * nombreDeBits),
              mask((T(1u) << nombreDeBits) - T(1u)) {

    }
    T operator()(T const& t) {
        return T(mask & (t >> shift));
    }
};

#endif //SOME_BITS