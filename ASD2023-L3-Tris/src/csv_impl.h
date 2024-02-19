/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : csv_impl.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier contenant les fonctions Templates CSV

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef ASD_LABOS_2021_CSV_IMPL_H
#define ASD_LABOS_2021_CSV_IMPL_H

template<typename T>
void vecteurVersCSV(const std::string &emplacementFichier, const std::string &nomFichier,
                    const std::vector<std::vector<T>> &donnees, const std::vector<std::string> &nomTris,
                    const std::vector<std::size_t> &taillesTris) {

   std::string messageReussite = "Le fichier " + nomFichier + " a bien ete cree";
   std::string messageEchec    = "ERREUR : Le fichier " + nomFichier + " n'a pu etre cree";

   std::string texteCSV = "Nombre de valeurs, ";

   //Création de la première ligne du tableau csv (Nombre de valeurs)
   for (size_t i = 0; i < donnees.size(); i++) {
      texteCSV += std::to_string(taillesTris[i]);
      if (i < donnees.size() - 1) {
         texteCSV += ", ";
      }
   }

   //Saut de ligne
   texteCSV += "\n";

   for (size_t colonne = 0; colonne < donnees.size(); colonne++) {

      //Création de la  ligne x du tableau csv (nomDesTris)
      texteCSV += nomTris[colonne] + " [ms]" + ", ";

      for (size_t ligne = 0; ligne < donnees.size(); ligne++) {
         if (colonne < donnees[ligne].size()) {
            texteCSV += std::to_string(donnees[ligne][colonne]);
         } else {
            texteCSV += " ";
         }

         if (ligne < donnees.size() - 1) {
            texteCSV += ", ";
         }
      }

      texteCSV += "\n";
   }

   exporterCSV(texteCSV, emplacementFichier + nomFichier);

}

#endif //ASD_LABOS_2021_CSV_IMPL_H
