/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : testTris_impl.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier contenant les fonctions Templates pour les test des Tris

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef ASD_LABOS_2021_TESTTRIS_IMPL_H
#define ASD_LABOS_2021_TESTTRIS_IMPL_H

#include "mesuresTris.h"
#include "triParBase.h"
#include "triRapide.h"

/*******************************************************************************************************************/

template<typename T>
void afficherVecteur(const std::vector<T>& vecteur) {
   std::cout << "[";
   for (const T &val: vecteur) {
      std::cout << val << ", ";
   }
   std::cout << "\b\b]" << std::endl << std::endl;
}

//*****************************************************************************************************************//

template<typename T, typename Iterator>
void testPartition(std::vector<T> vecteur) {
   std::cout << "Avant partition : " << std::endl;
   afficherVecteur(vecteur);

   auto pivot = partition<Iterator>(vecteur.begin(), vecteur.end() - 1);
   std::cout << "Pivot : " << *pivot << std::endl << std::endl;

   std::cout << "Apres partition : " << std::endl;
   afficherVecteur(vecteur);
}

//*****************************************************************************************************************//

template<typename T, typename Iterator>
void testTriRapide(std::vector<T> vecteur) {
   std::cout << "Avant tri rapide : " << std::endl;
   afficherVecteur(vecteur);

   tri_rapide<Iterator>(vecteur.begin(), vecteur.end()-1);

   std::cout << "Apres tri rapide : " << std::endl;
   afficherVecteur(vecteur);
}

//*****************************************************************************************************************//
template<typename T>
void testTriComptage(std::vector<T> vecteur) {
   const size_t DECIMALES = 10;
   std::vector<T> vecteurTrie(vecteur.size());

   std::cout << "Avant tri comptage : " << std::endl;
   afficherVecteur(vecteur);

   tri_comptage(vecteur.begin(), vecteur.end(), vecteurTrie.begin(), index_fn, DECIMALES);

   std::cout << "Apres tri comptage : " << std::endl;
   afficherVecteur(vecteurTrie);
}

//*****************************************************************************************************************//

template<typename T, typename Iterator,size_t NBITS>
void testTriParBase(std::vector<T> vecteur) {
   std::cout << "Avant tri par base " << NBITS << " : " << std::endl;
   afficherVecteur(vecteur);

   tri_par_base<Iterator, NBITS>(vecteur.begin(), vecteur.end());

   std::cout << "Avant tri par base " << NBITS << " : " << std::endl;
   afficherVecteur(vecteur);
}

//*****************************************************************************************************************//

#endif //ASD_LABOS_2021_TESTTRIS_IMPL_H
