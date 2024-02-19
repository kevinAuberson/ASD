#include <iostream>
#include "pieces.h"
#include "resolutionCartes.h"

using namespace std;


int main() {

   vector<Carte> jeuCarte;
   vector<Carte> solutions;
   size_t nombreIter = 0;

   for (Piece carte: PIECES) { //créer le jeu de carte tel que le prof la choisi
      jeuCarte.emplace_back(carte, PIECES);
   }

   cartesDisponnibles = jeuCarte;

   resolution(0, jeuCarte, cartesDisponnibles, nombreIter);

   // Résulat attendu
   cout << "---------------------------" << endl;
   cout << "1b 5d 4a 7a 6a 2a 8a 3a 9d " << endl;

}