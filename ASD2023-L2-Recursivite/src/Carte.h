/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : Carte.h
  Nom du labo : Labo 2 - Récursivité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 13.03.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef ASD2023_L2_RECURSIVITE_CARTE_H
#define ASD2023_L2_RECURSIVITE_CARTE_H

#include <array>
#include <string>
#include "pieces.h"
#include "resolutionCartes.h"

enum sens {
    HAUT, DROITE, BAS, GAUCHE
};

class Carte {

public:
    Carte(const Piece &piece, const Pieces& pieces);

    void tournerCarte();
    AttachementType getValeurCote(sens cote);

    std::vector<AttachementType>& getSymboles();
    size_t getID() const;

private:
    static size_t next_id;
    size_t id;

    std::vector<AttachementType> symbolesCarte;
    Pieces piecesCompatible;
};

#endif //ASD2023_L2_RECURSIVITE_CARTE_H
