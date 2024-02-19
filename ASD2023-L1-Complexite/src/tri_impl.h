/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : tri.cpp
  Nom du labo : Labo 1 - Complexité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 21.02.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

using namespace std;


template<typename T>
void tri_bulles(std::vector<T>& t){
   if (!t.empty()) {
      for (size_t i = 0; i < t.size() - 1; ++i) {
         for (size_t j = 1; j < t.size() - i; ++j) {
            if (t.at(j - 1) > t.at(j))
               swap(t.at(j - 1), t.at(j)); // permutation
         }
      }
   }
}

template<typename T>
void tri_par_selection(std::vector<T>& t){
   if (!t.empty()) {
      size_t iMin;
      for (size_t i = 0; i < t.size() - 1; ++i) {
         iMin = i;
         for (size_t j = i + 1; j < t.size(); ++j) {
            if (t.at(j) < t.at(iMin))
               iMin = j;
         }
         swap(t.at(i), t.at(iMin)); // permutation
      }
   }
}

template <typename T>
void tri_par_insertion(vector<T>& t) {
   int n = t.size();
   for (int i = 1; i < n; i++) {
      T tmp = t[i];
      int j = i - 1;
      while (j >= 0 && t[j] > tmp) {
         t[j + 1] = t[j];
         j--;
      }
      t[j + 1] = tmp;
   }
}


/********************************************************************/

template<typename Iterator>
void tri_bulles(Iterator begin, Iterator end){
   if(!(begin == end)){
      for (Iterator it1 = begin; it1 != end + 1; ++it1) {
         for (Iterator it2 = begin + 1; it2 < end + 1; ++it2) {
            if (*(it2-1) > *it2)
               swap(*(it2 -1),*it2); // permutation
         }
      }
   }
}

template< typename Iterator>
void tri_par_selection(Iterator begin, Iterator end){
   if(!(begin == end)){
      Iterator iMin;
      for (Iterator it1 = begin; it1 != end + 1; ++it1) {
         iMin = it1;
         for (Iterator it2 = it1 + 1; it2 < end + 1; ++it2) {
            if (*it2 < *iMin)
               iMin = it2;
         }
         swap(*it1, *iMin); // permutation
      }
   }
}

template< typename Iterator>
void tri_par_insertion(Iterator begin, Iterator end){

    std::iter_swap(begin, std::min_element(begin, end + 1));
    for (Iterator it1 = begin; ++it1 < end + 1; begin = it1){

        for (Iterator it2 = it1; *it2 < *begin; --it2, --begin){
            std::iter_swap(begin, it2);
        }
    }

}