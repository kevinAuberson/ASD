/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : resolutionCartes.h
  Nom du labo : Labo 2 - Récursivité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 13.03.2023
  But         : Header des fonctions de résolution du puzzle

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#ifndef ASD2023_L2_RECURSIVITE_RESOLUTIONCARTES_H
#define ASD2023_L2_RECURSIVITE_RESOLUTIONCARTES_H

#include <string>
#include "pieces.h"
#include "Carte.h"

// nom         pieceNecessaire
// but         Retourne la pièce compatible avec celle en paramètre
//
// param       AttachementType symbole   : symbole a completer
//

// return      bool
// exception   n/a
AttachementType pieceNecessaire(AttachementType symbole);

// nom         pieceCompatible
// but         Vérifier si les deux côtés fournis en paramètres sont compatibles
//
// param       const AttachementType &symbole   : symbole de la 1ère carte
//             const AttachementType &autreSymbole : symbole de la 2ème carte

// return      bool
// exception   n/a
bool pieceCompatible(const AttachementType &symbole, const AttachementType &autreSymbole);

// nom         conversionFormatProf
// but         Convertis un vecteur selon le format du prof
//
// param       const std::vector<Carte> &jeuCartes   : vecteur qui contient toutes les cartes
//

// return      bool
// exception   n/a
[[maybe_unused]] std::string conversionFormatProf(const std::vector<Carte> &jeuCartes);

// nom         resolution
// but         fonction recursive qui va vérifier chauqe possiblités pour trouver la bonne combinaison du jeu
//
// param       size_t positionActuelle   : position actuelle de la boucle
//             std::vector<Carte> &jeuCartes : vecteur qui contient toutes les cartes
//             std::vector<Carte> &solution : vecteur qui contient la solution en cours
//             size_t nombreIter : nombre d'itérations
//
// return      bool
// exception   n/a
void resolution(size_t positionActuelle, std::vector<Carte> &jeuCartes, std::vector<Carte> &solution, size_t nombreIter);

#endif //ASD2023_L2_RECURSIVITE_RESOLUTIONCARTES_H
