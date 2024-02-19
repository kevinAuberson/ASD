/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : mesureTris_impl.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier contenant les fonctions Templates pour les mesures de tris

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef ASD_LABOS_2021_MESURETRIS_IMPL_H
#define ASD_LABOS_2021_MESURETRIS_IMPL_H


/*******************************************************************************************************************/

template<typename T>
std::chrono::duration<double, std::milli> calculTempsTri(void (*tri)(T, T), T first, T last) {
   auto debut = std::chrono::high_resolution_clock::now();
   tri(first, last);
   auto fin = std::chrono::high_resolution_clock::now();

   std::chrono::duration<double, std::milli> temps_ms = fin - debut;

   return temps_ms;
}

/*******************************************************************************************************************/

template<typename T>
std::vector<T> genererVecteur(size_t taille, TYPE_TRI typeTri) {
   std::vector<T> vecteur;
   std::random_device randomSeed;
   std::mt19937 randomAleatoire(randomSeed());

   vecteur.reserve(taille);

   switch (typeTri) {
      case CROISSANT:
         for (size_t i = 1; i <= taille; i++) {
            vecteur.push_back(T(i));
         }
         break;

      case DECROISSANT:
         for (size_t i = taille; i >= 1; i--) {
            vecteur.push_back(T(i));
         }
         break;

      case ALEATOIRE:
         for (size_t i = 1; i <= taille; i++) {
            vecteur.push_back(T(i));
         }
         shuffle(vecteur.begin(), vecteur.end(), randomAleatoire);
         break;

      case PRESQUE_TRIE:
         for (size_t i = 1; i <= taille; i++) {
            vecteur.push_back(T(i));
         }

         std::mt19937 randomRange(randomSeed());
         std::uniform_int_distribution<> distrib(1, (int) taille);

         int debut = distrib(randomRange);
         int fin = distrib(randomRange);

         if (debut > fin) {
            int tmp = debut;
            debut = fin;
            fin = tmp;
         }

         if (debut == fin)
            fin++;

         std::mt19937 randomPresqueTrie(randomSeed());
         std::shuffle(vecteur.begin() + debut, vecteur.begin() + fin, randomPresqueTrie);

         break;
   }
   return vecteur;
}
/*******************************************************************************************************************/

template<typename T, typename Iterator>
void calculTempsTris(const std::vector<TYPE_TRI> &typesTri, const std::vector<std::size_t>& tailles) {

   const std::size_t NB_TRI = 4;
   const std::size_t nbVal  = tailles.size() * NB_TRI;

   const std::string EMPLACEMENT_FICHIERS  = "../../rapport/csv/";
   const std::string MESSAGE_CALCUL        = "Calcul des donnees en cours veuillez patientez...";
   const std::string MESSAGE_EXPORTATION   = "Fin du calcul des donnees \n"
                                             "Exportation au format csv veuillez patientez...";
   const std::string MESSAGE_FIN           = "Fin de l'exportation au format csv";

   const std::vector<std::string> NOM_TRIS = {"Tri rapide", "Tri par base 1", "Tri par base 2", "Tri par base 4",
                                              "Tri par base 8", "Tri par base 16"};


   std::vector<std::vector<double>> resultatsCroissant;
   std::vector<std::vector<double>> resultatsDecroissant;
   std::vector<std::vector<double>> resultatsAleatoire;
   std::vector<std::vector<double>> resultatsPresqueTrie;

   resultatsCroissant.reserve(nbVal);
   resultatsDecroissant.reserve(nbVal);
   resultatsAleatoire.reserve(nbVal);
   resultatsPresqueTrie.reserve(nbVal);

   std::cout << MESSAGE_CALCUL << std::endl;

   for(unsigned long long taille : tailles){
      for(const TYPE_TRI& tri : typesTri){

         std::vector<T> vTriRapide    = genererVecteur<T>(taille,tri);
         std::vector<T> vTriParBase1  = genererVecteur<T>(taille,tri);
         std::vector<T> vTriParBase2  = genererVecteur<T>(taille,tri);
         std::vector<T> vTriParBase4  = genererVecteur<T>(taille,tri);
         std::vector<T> vTriParBase8  = genererVecteur<T>(taille,tri);
         std::vector<T> vTriParBase16 = genererVecteur<T>(taille,tri);

         std::chrono::duration<double, std::milli> tTR    = calculTempsTri<Iterator>(&tri_rapide, vTriRapide.begin(),vTriRapide.end());
         std::chrono::duration<double, std::milli> tTPB1  = calculTempsTri<Iterator>(&tri_par_base<Iterator, 1>, vTriParBase1.begin(), vTriParBase1.end());
         std::chrono::duration<double, std::milli> tTPB2  = calculTempsTri<Iterator>(&tri_par_base<Iterator, 2>, vTriParBase2.begin(), vTriParBase2.end());
         std::chrono::duration<double, std::milli> tTPB4  = calculTempsTri<Iterator>(&tri_par_base<Iterator, 4>, vTriParBase4.begin(), vTriParBase4.end());
         std::chrono::duration<double, std::milli> tTPB8  = calculTempsTri<Iterator>(&tri_par_base<Iterator, 8>, vTriParBase8.begin(), vTriParBase8.end());
         std::chrono::duration<double, std::milli> tTPB16 = calculTempsTri<Iterator>(&tri_par_base<Iterator, 16>,vTriParBase16.begin(),vTriParBase16.end());

         std::vector<double> resultats {tTR.count(), tTPB1.count(),  tTPB2.count(), tTPB4.count(), tTPB8.count(), tTPB16.count()};

         switch (tri) {
            case CROISSANT:
               resultatsCroissant.push_back(resultats);
               break;

            case DECROISSANT:
               resultatsDecroissant.push_back(resultats);
               break;

            case ALEATOIRE:
               resultatsAleatoire.push_back(resultats);
               break;

            case PRESQUE_TRIE:
               resultatsPresqueTrie.push_back(resultats);
               break;

         }
      }
   }

   std::cout << MESSAGE_EXPORTATION << std::endl;

   for(const TYPE_TRI& tri : typesTri){
      switch (tri) {
         case CROISSANT:
            vecteurVersCSV(EMPLACEMENT_FICHIERS, "croissant.csv", resultatsCroissant, NOM_TRIS, tailles);
            break;

         case DECROISSANT:
            vecteurVersCSV(EMPLACEMENT_FICHIERS, "decroissant.csv", resultatsDecroissant, NOM_TRIS, tailles);
            break;

         case ALEATOIRE:
            vecteurVersCSV(EMPLACEMENT_FICHIERS, "aleatoire.csv", resultatsAleatoire, NOM_TRIS, tailles);
            break;

         case PRESQUE_TRIE:
            vecteurVersCSV(EMPLACEMENT_FICHIERS, "presqueTrie.csv", resultatsPresqueTrie, NOM_TRIS, tailles);
            break;

      }
   }

   std::cout << MESSAGE_FIN << std::endl;
}

/*******************************************************************************************************************/


#endif //ASD_LABOS_2021_MESURETRIS_IMPL_H
