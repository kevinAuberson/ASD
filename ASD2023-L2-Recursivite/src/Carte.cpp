/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : Carte.cpp
  Nom du labo : Labo 2 - Récursivité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 13.03.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#include "Carte.h"

size_t Carte::next_id = 0;

//*****************************************************************************************************************//

// nom         Carte
// but         Constructeur de la classe
//
// param       const Piece &piece   : Pièce a copier
//             const Pieces &pieces : Vecteur des pieces

// return      bool
// exception   n/a
Carte::Carte(const Piece &piece, const Pieces &pieces) {
   id = next_id++;
   for (AttachementType symbole: piece) {
      symbolesCarte.push_back(symbole);
   }

   for (size_t position = 0;position<PIECES.size();position++) {
      for (const AttachementType &symbole: symbolesCarte) {
         for (const AttachementType &autreSymbole: PIECES[position]) {
            if (pieceNecessaire(symbole) == autreSymbole) {
               piecesCompatible.push_back(PIECES[position]);
               position++;
            }
         }
      }
   }
}
//*****************************************************************************************************************//

// nom         tournerCarte
// but         Tourne une carte dans le sens anti-horraire
//
// param

// return      bool
// exception   n/a
void Carte::tournerCarte() {
   //Sens anti-horaire
   AttachementType tmp = symbolesCarte[HAUT];
   symbolesCarte[HAUT] = symbolesCarte[DROITE];
   symbolesCarte[DROITE] = symbolesCarte[BAS];
   symbolesCarte[BAS] = symbolesCarte[GAUCHE];
   symbolesCarte[GAUCHE] = tmp;
}
//*****************************************************************************************************************//

// nom         getSymboles
// but         Retourne le vecteur de symboles de la carte
//
// param

// return      bool
// exception   n/a
std::vector<AttachementType> &Carte::getSymboles()  {
   return symbolesCarte;
}
//*****************************************************************************************************************//

// nom         getValeurCote
// but         REnvoie la valeure symbole d'un côté
//
// param       sens cote   : valeur du cote selon le enum sens
//

// return      bool
// exception   n/a
AttachementType Carte::getValeurCote(sens cote) {
   return symbolesCarte[cote];
}
//*****************************************************************************************************************//

// nom         getID
// but         Retroune l'ID de la carte
//
// param

// return      bool
// exception   n/a
size_t Carte::getID() const {
   return id;
}
//*****************************************************************************************************************//


