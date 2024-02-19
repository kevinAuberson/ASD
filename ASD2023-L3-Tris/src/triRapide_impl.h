/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : triRapide_impl.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier contenant les fonctions Templates triRapide

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef TRI_RAPIDE
#define TRI_RAPIDE

/*******************************************************************************************************************/

template<typename Iterator>
size_t aleatoire(Iterator first, Iterator last) {

   static bool pass = true;
   if (pass) {
      srand((unsigned) time(nullptr));
      pass = false;
   }

   return (size_t)rand() % static_cast<size_t>(std::distance(first, last));
}

/*******************************************************************************************************************/

template<typename Iterator>
Iterator partition(Iterator first, Iterator last) {

   Iterator gauche = first;
   Iterator droite = last;

   while (gauche < droite) {
      while (*gauche < *last) {
         gauche++;
      }

      while (droite > first && *last <= *droite) {
         droite--;
      }

      // Fin si les deux itérateurs se croisent
      if (gauche >= droite) {
         break;
      }

      std::iter_swap(gauche, droite);
   }

   //Effectue le dernier swap et retourne le prochain pivot
   std::iter_swap(gauche, last);
   return gauche;

}

/*******************************************************************************************************************/

template<typename Iterator>
void tri_rapide(Iterator first, Iterator last) {

   while (first < last) {

      // Prend un pivot aléatoire valable
      Iterator pivot = first + static_cast<typename std::iterator_traits<Iterator>::difference_type>(aleatoire(first,last));
      std::iter_swap(last, pivot);

      Iterator it = partition(first, last);

      // Après le tri partition, vérifie si il reste des valeurs à gauche du pivot à traiter, sinon trie la partie droite
      if ((it - first) < (last - it)) {
         tri_rapide(first, it - 1);
         first = it + 1;
      }
      else {
         tri_rapide(it + 1, last);
         last = it - 1;

      }
   }
}
/*******************************************************************************************************************/

#endif //TRI_RAPIDE