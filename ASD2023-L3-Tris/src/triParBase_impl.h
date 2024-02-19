/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : triParBase_impl.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier contenant les fonctions Templates triParBase

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef TRI_PAR_BASE
#define TRI_PAR_BASE


/*******************************************************************************************************************/

template<typename Iterator, typename Fn>
void tri_comptage(Iterator first, Iterator last, Iterator output_first, Fn index_fn, size_t N) {

   // Création d'un vecteur qui contiendra le nombre d'index avec le nombre de valeurs pour chaque index.
   std::vector<size_t> compteurs(N, 0);

   // Parcours le tableau 1 fois afin de savoir combien de valeur il y'a par index
   for (Iterator it = first; it != last; it++) {
      compteurs[index_fn(*it)]++;
   }

   // Réserve les places pour les valeurs des index
   size_t index = 0;
   for (size_t i = 0; i < N; i++) {
      size_t tmp = compteurs[i];
      compteurs[i] = index;
      index += tmp;
   }

   // Prends les valeurs dans l'ordre (gauche --> droite) et les classes selon leur index déjà prè-réservés
   for (Iterator it = first; it != last; it++) {
      *(output_first + static_cast<typename Iterator::difference_type>(compteurs[index_fn(*it)])) = *it;
      compteurs[index_fn(*it)]++;
   }

}
/*******************************************************************************************************************/

template<typename Iterator, size_t NBITS>
void tri_par_base(Iterator first, Iterator last) {
   using T = typename Iterator::value_type;
   static_assert(std::is_unsigned<T>::value);

   size_t nbrIterations = std::numeric_limits<T>::digits / NBITS;
   std::vector<T> vTemp(size_t(last - first));

   // Effectue le tri par base avec un déclage vers la gauche de NBITS
   for (size_t i = 0; i < nbrIterations; i += 2) {
      tri_comptage(first, last, vTemp.begin(), SomeBits<T>(NBITS, i), 1 << NBITS);
      tri_comptage(vTemp.begin(), vTemp.end(), first, SomeBits<T>(NBITS, i + 1), 1 << NBITS);
   }
}
/*******************************************************************************************************************/

#endif