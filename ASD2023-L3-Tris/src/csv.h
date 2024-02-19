/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : csv.h
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier d'en-tête des fonctions csv

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/

#ifndef ASD_LABOS_2021_CSV_H
#define ASD_LABOS_2021_CSV_H

#include <fstream>
#include <vector>
#include <string>

/*******************************************************************************************************************/

// nom         exporterCSV
// but         exporte les données dans un fichier CSV passé en paramètre
//
// param       const char *donnees              : données
//             const string &emplacementFichier : chemin source pour la création du fichier
//
//
// return      bool : renvoie une confirmation
// exception   n/a
bool exporterCSV(const std::string& donnees, const std::string &emplacementFichier);

/*******************************************************************************************************************/

// nom         vecteurVersCSV
// but         Converti le contenu de vecteurs en string au format csv
//
// param       const std::string &emplacementFichier : Emplacement du fichier
//             const std::string &nomFichier : Nom du fichier
//             const std::vector<std::vector<T>> &donnees : Données de type T contenues dans vecteur
//             const std::vector<std::string> &nomTris : Nom des tris effectués dans les mesures
//             const std::vector<std::size_t> &taillesTris : Taille des tris effectués dans les mesures
//
// return      void
// exception   n/a
template<typename T>
void vecteurVersCSV(const std::string &emplacementFichier, const std::string &nomFichier,
                    const std::vector<std::vector<T>> &donnees, const std::vector<std::string> &nomTris,
                    const std::vector<std::size_t> &taillesTris);

/*******************************************************************************************************************/

#include "csv_impl.h"

#endif //ASD_LABOS_2021_CSV_H
