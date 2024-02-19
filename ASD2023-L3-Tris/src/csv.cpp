/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : csv.cpp
  Nom du labo : Labo 3 - Tri
  Auteur(s)   : Auberson Kevin - Faria Dos Santos Dani Tiago - Gonin Guillaume
  Date        : 01.04.2023
  But         : Fichier contenant la fonction d'exportation d'un string dans un fichier .csv

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#include "csv.h"

/*******************************************************************************************************************/

bool exporterCSV(const std::string& donnees,const std::string& emplacementFichier)
{
   std::fstream fichierCsv;
   fichierCsv.open(emplacementFichier, std::ios::out);
   if (fichierCsv) {
      fichierCsv << donnees;
      return true;
   }
   else {
      return false;
   }

}

/*******************************************************************************************************************/
