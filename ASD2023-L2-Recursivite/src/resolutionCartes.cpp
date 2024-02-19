/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : resolutionCartes.cpp
  Nom du labo : Labo 2 - Récursivité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 13.03.2023
  But         : Fonction de résolution du puzzle

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include "resolutionCartes.h"

using namespace std;

AttachementType pieceNecessaire(AttachementType symbole) {
   switch (symbole) {
      case FILLE_BAS:
         return FILLE_HAUT;
      case FILLE_HAUT:
         return FILLE_BAS;

      case DAME_HAUT:
         return DAME_BAS;
      case DAME_BAS:
         return DAME_HAUT;

      case ARROSOIR_DROIT:
         return ARROSOIR_GAUCHE;
      case ARROSOIR_GAUCHE:
         return ARROSOIR_DROIT;

      case GATEAU_DROIT:
         return GATEAU_GAUCHE;
      case GATEAU_GAUCHE:
         return GATEAU_DROIT;

      case ARROSOIR_INVERSE:
      case NONE:
         return NONE;

   }
}

//*****************************************************************************************************************//

[[maybe_unused]] std::string conversionFormatProf(const std::vector<Carte> &jeuCartes) {
   //Les cartes sont identifiées de "a" jusqu'à "d" dans le sens anti-horaire en partant du coté haut de celle-ci
   std::string ID;
   std::string combinaison;
   size_t idCarte;
   size_t count = 0;
   AttachementType haut;

   for (Carte carte: jeuCartes) {
      idCarte = carte.getID();
      ID = std::to_string(idCarte + 1);
      haut = carte.getSymboles()[HAUT];

      if (haut == PIECES[idCarte][HAUT]) {
         combinaison += ID + "a";

      } else if (haut == PIECES[idCarte][DROITE]) {
         combinaison += ID + "b";

      } else if (haut == PIECES[idCarte][BAS]) {
         combinaison += ID + "c";

      } else if (haut == PIECES[idCarte][GAUCHE]) {
         combinaison += ID + "d";

      } else {
         combinaison += "erreur";
      }

      if (count < jeuCartes.size()) {
         combinaison += " ";
      }

      count++;
   }

   return combinaison;

}

//*****************************************************************************************************************//

bool pieceCompatible(const AttachementType &symbole, const AttachementType &autreSymbole) {
   switch (symbole) {
      case FILLE_BAS:
         return autreSymbole == FILLE_HAUT;
      case FILLE_HAUT:
         return autreSymbole == FILLE_BAS;

      case DAME_HAUT:
         return autreSymbole == DAME_BAS;
      case DAME_BAS:
         return autreSymbole == DAME_HAUT;

      case ARROSOIR_DROIT:
         return autreSymbole == ARROSOIR_GAUCHE;
      case ARROSOIR_GAUCHE:
         return autreSymbole == ARROSOIR_DROIT;

      case GATEAU_DROIT:
         return autreSymbole == GATEAU_GAUCHE;
      case GATEAU_GAUCHE:
         return autreSymbole == GATEAU_DROIT;

      case ARROSOIR_INVERSE:
      case NONE:
         return autreSymbole == NONE;

   }
}

//*****************************************************************************************************************//


//*****************************************************************************************************************//
