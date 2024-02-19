/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : annexe.cpp
  Nom du labo : Labo 1 - Complexité
  Auteur(s)   : Auberson Kevin - Faria Dani - Gonin Guillaume
  Date        : 21.02.2023
  But         :

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#include "annexe.h"
#include <fstream>

using namespace std;

template<typename T, typename U>
void exportToCSV(const vector<T>& n_values, const vector<U>& mesures){
   ofstream out("data.csv");

   if(not out.is_open()) {
      cerr << "Pas pu ouvrir le fichier en écriture" << endl;
      return;
   }

   out << "n";
   for(auto n : n_values) out << "," << n;
   out << endl;

   for(size_t x = 0; x < mesures.size(); x++) {
      for (size_t y = 0; y < mesures[x].size(); y++) {
         out << "," << mesures[x][y];
      }
      out << endl;

   }
}

template<typename T>
vector<T> generateVector(size_t n, unsigned seed, TYPE_OF_SORT t) {
   vector<T> v;
   v.reserve(n);
   default_random_engine rng(seed);
   std::uniform_int_distribution<std::mt19937::result_type> range(1, 99);

   switch (t) {
      case INCREASING:
         for (size_t i = 0; i < n ; i++) {
            v.push_back(T(i));
         }
         break;
      case DECREASING:
         for (size_t i = n; i > 0; i--) {
            v.push_back(T(i));
         }
         break;
      case RANDOM:
         for (size_t i = 0; i < n ; i++) {
            v.push_back(T(i));
         }
         shuffle(v.begin(), v.end(), rng);
         break;
      case ALMOST:
         for (size_t i = 0; i < n ; i++) {
            v.push_back(T(i));
         }
         for (size_t i = 0; i < n; i++) {
            size_t j = rand() % n;
            swap(v[i], v[j]);
         }
         break;
   }
   return v;
}

/******************************************************************************************************************/

string typeToString(TYPE_OF_SORT t) {
   string s;
   switch (t) {
      case INCREASING:
         s = "INCREASING";
         break;
      case DECREASING:
         s = "DECREASING";
         break;
      case RANDOM:
         s = "RANDOM";
         break;
      case ALMOST:
         s = "ALMOST";
         break;
   }
   return s;
}

/******************************************************************************************************************/


void showMessage (size_t size, size_t affect, size_t comp, const string& typeSort){
   std::cout << "OUI " << "for N = " << size << ", Type = " << typeSort << ", Number of comparisons done : " << comp << " Number of assignments done :" << affect << std::endl;
}

/******************************************************************************************************************/


template<typename T>
std::array<size_t,2> callMethodAndGiveActions(void (*methodToCall)(vector<T> &), vector<T> args, TYPE_OF_SORT currentType) {
   std::array<size_t,2> action{};
   OpCounter::counterAffect = 0, OpCounter::counterComp = 0;
   methodToCall(args);

   action[0] = OpCounter::counterAffect;
   action[1] = OpCounter::counterComp;

   OpCounter::resetCounters();

   return action;

}

/******************************************************************************************************************/


template<typename T>
std::array<size_t,2>  callMethodAndGiveActions(void (*methodToCall)(T, T), T begin, T end,TYPE_OF_SORT currentType) {
   std::array<size_t,2> action{};
   OpCounter::counterAffect = 0, OpCounter::counterComp = 0;
   methodToCall(begin, end);

   action[0] = OpCounter::counterAffect;
   action[1] = OpCounter::counterComp;

   OpCounter::resetCounters();

   return action;

}

/******************************************************************************************************************/


template<typename T>
chrono::duration<double, std::milli> callMethodAndGiveTime(void (*methodToCall)(vector<T> &), vector<T> args) {
   auto start = std::chrono::high_resolution_clock::now();
   methodToCall(args);
   auto end = std::chrono::high_resolution_clock::now();

   chrono::duration<double, std::milli> float_ms = end - start;
   return float_ms;
}

/******************************************************************************************************************/


template<typename T>
chrono::duration<double, std::milli> callMethodAndGiveTime(void (*methodToCall)(T, T), T begin, T end) {
   auto start = std::chrono::high_resolution_clock::now();
   methodToCall(begin, end);
   auto stop = std::chrono::high_resolution_clock::now();

   chrono::duration<double, std::milli> float_ms = stop - start;
   return float_ms;
}

/******************************************************************************************************************/



void calculateTime(const vector<size_t>& nTested, const vector<TYPE_OF_SORT>& types, unsigned seed) {
   vector<size_t> size;
   vector<vector<double>> results;

   for (size_t n: nTested) {
      size.push_back(n);
      for (TYPE_OF_SORT currentType: types) {
         vector<int> v = generateVector<int>(n, seed, currentType);

         chrono::duration<double, std::milli> tB = callMethodAndGiveTime<int>(&tri_bulles, v);

         chrono::duration<double, std::milli> tI = callMethodAndGiveTime<int>(&tri_par_insertion, v);

         chrono::duration<double, std::milli> tS = callMethodAndGiveTime<int>(&tri_par_selection, v);

         chrono::duration<double, std::milli> tSo = callMethodAndGiveTime(&sort, v.begin(), v.end());

         chrono::duration<double, std::milli> tSS = callMethodAndGiveTime(&stable_sort, v.begin(), v.end());
         vector<double> result {tB.count(), tI.count(), tS.count(), tSo.count(), tSS.count()};
         results.push_back(result);

         std::cout << "Bubble sort for N = " << n << ", Type = " << typeToString(currentType) << ", Time taken : "
                   << tB.count()
                   << " milliseconds" << std::endl;
         std::cout << "Insert sort for N = " << n << ", Type = " << typeToString(currentType) << ", Time taken : "
                   << tI.count()
                   << " milliseconds" << std::endl;
         std::cout << "Select sort for N = " << n << ", Type = " << typeToString(currentType) << ", Time taken : "
                   << tS.count()
                   << " milliseconds" << std::endl;
         std::cout << "Normal sort for N = " << n << ", Type = " << typeToString(currentType) << ", Time taken : "
                   << tSo.count()
                   << " milliseconds" << std::endl;
         std::cout << "Stable sort for N = " << n << ", Type = " << typeToString(currentType) << ", Time taken : "
                   << tSS.count()
                   << " milliseconds" << std::endl;
         std:cout  << "-----------------------------------------------------------------------------------------"
         << std::endl;
      }
   }

   exportToCSV(size,results);
}

/******************************************************************************************************************/


void countOperation (const vector<size_t>& nTested, const vector<TYPE_OF_SORT>& types, unsigned seed) {
   for (size_t n: nTested) {
      for (TYPE_OF_SORT currentType: types) {
         vector<OpCounter> v = generateVector<OpCounter>(n, seed, currentType);

         std::array<size_t,2> actionBulles = callMethodAndGiveActions(&tri_bulles, v, currentType);
         std::array<size_t,2> actionInsert = callMethodAndGiveActions(&tri_par_insertion, v, currentType);
         std::array<size_t,2> actionSelect = callMethodAndGiveActions(&tri_par_selection, v, currentType);
         std::array<size_t,2> actionSort = callMethodAndGiveActions(&sort, v.begin(), v.end(), currentType);
         std::array<size_t,2> actionStable = callMethodAndGiveActions(&stable_sort, v.begin(), v.end(), currentType);

         std::cout << "Bubble sort for N = " << n << ", Type = " << typeToString(currentType) << ", Number of comparisons done : "
                   << actionBulles[1] << " Number of assignments done :" << actionBulles[0] << std::endl;
         std::cout << "Insert sort for N = " << n << ", Type = " << typeToString(currentType) << ", Number of comparisons done : "
                   << actionInsert[1] << " Number of assignments done :" << actionInsert[0] << std::endl;
         std::cout << "Select sort for N = " << n << ", Type = " << typeToString(currentType) << ", Number of comparisons done : "
                   << actionSelect[1] << " Number of assignments done :" << actionSelect[0] << std::endl;
         std::cout << "Sort for N = " << n << ", Type = " << typeToString(currentType) << ", Number of comparisons done : "
                   << actionSort[1] << " Number of assignments done :" << actionSort[0] << std::endl;
         std::cout << "Stable sort for N = " << n << ", Type = " << typeToString(currentType) << ", Number of comparisons done : "
                   << actionStable[1] << " Number of assignments done :" << actionStable[0] << std::endl;

         std:cout  << "-----------------------------------------------------------------------------------------" << endl;

      }
   }

}