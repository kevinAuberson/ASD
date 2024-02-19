#define CATCH_CONFIG_FAST_COMPILE

#include <iostream>
#include <string>

#include "../avlTree.h"
#include "catch_amalgamated.hpp"

using namespace std;

/**
 * Convertit l'arbre AVL en une représentation sous forme de chaîne de caractères.
 * @param tree L'arbre AVL à convertir.
 * @return La représentation sous forme de chaîne de caractères de l'arbre.
 */
template<typename Key>
std::string str(const avlTree<Key> &tree) {
   std::ostringstream oss;
   oss << tree;
   return oss.str();
}

static const int EASY_VALUES[]     = {2, 4, 6, 8, 12, 14, 16, 18, 20};
static const int MEDIUM_VALUES[]   = {7, 1, 15, 11, 5, 19, 9, 13, 3, 8, 10, 14, 18, 4, 16, 6, 12, 2, 17};
static const int HARDCORE_VALUES[] = {-8, 23, -22, 11, -4, 25, 10, -15, -21, -7, -5, 6, 9, -3, -17, 12,
                                      -23, -12, 24, -25, -6, -13, -20, -2, 5, 18, 7, 15, 13};

const size_t EASY_VALUES_SIZE      = sizeof(EASY_VALUES) / sizeof(EASY_VALUES[0]);
const size_t MEDIUM_VALUES_SIZE    = sizeof(MEDIUM_VALUES) / sizeof(MEDIUM_VALUES[0]);
const size_t HARDCORE_VALUES_SIZE  = sizeof(HARDCORE_VALUES) / sizeof(HARDCORE_VALUES[0]);

/**
 * Génère un arbre AVL à partir d'un tableau de valeurs.
 * @param values Le tableau de valeurs à insérer dans l'arbre.
 * @param size La taille du tableau de valeurs.
 * @return L'arbre AVL généré.
 */
static avlTree<int> generateTree(const int values[], int size) {
   avlTree<int> tree;
   for (int i = 0; i < size; i++) {
      tree.insert(values[i]);
   }
   return tree;
}

static const avlTree<int> emptyTree;
static const avlTree<int> easyTree = generateTree(EASY_VALUES, EASY_VALUES_SIZE);
static const avlTree<int> mediumTree = generateTree(MEDIUM_VALUES, MEDIUM_VALUES_SIZE);
static const avlTree<int> hardTree = generateTree(HARDCORE_VALUES, HARDCORE_VALUES_SIZE);

TEST_CASE("Constructeur par defaut : avlTree()", "[avlTree]") {
   const avlTree<int> tree;

   SECTION("Arbre vide") {
      REQUIRE(tree.height() == 0);
      REQUIRE(str(tree) == ".");
   }
}

TEST_CASE("Constructeur par copie : avlTree(avlTree const &other)", "[avlTree]") {
   const avlTree<int> tree = generateTree(EASY_VALUES, EASY_VALUES_SIZE);

   SECTION("Arbre par copie") {
      const avlTree<int> treeCopy(tree);
      REQUIRE(tree.height() == treeCopy.height());
      REQUIRE(str(tree) == str(treeCopy));
   }
}

TEST_CASE("Destructeur : ~avlTree()", "[avlTree]") {
   avlTree<int> tree;

   SECTION("Destruciton d'un arbre vide") {
      tree.~avlTree<int>();
      REQUIRE(str(tree) == ".");
   }

   SECTION("Destruciton d'un arbre simple") {
      tree = generateTree(EASY_VALUES, EASY_VALUES_SIZE);
      tree.~avlTree<int>();
      REQUIRE(str(tree) == ".");
   }
}

TEST_CASE("Insertion valeur : void insert(Key const &k)", "[avlTree]") {
   avlTree<int> tree;

   SECTION("Insertion dans un arbre vide") {
      tree.insert(42);
      REQUIRE(tree.height() == 1);
      REQUIRE(str(tree) == "42(.,.)");
   }

   SECTION("Insertion valeur < Racine") {
      tree.insert(3);
      tree.insert(2);
      REQUIRE(str(tree) == "3(2(.,.),.)");
   }

   SECTION("Insertion valeur > Racine") {
      tree.insert(3);
      tree.insert(4);
      REQUIRE(str(tree) == "3(.,4(.,.))");
   }

   SECTION("Double insertion de la même valeur") {
      tree.insert(3);
      tree.insert(4);
      tree.insert(4);
      REQUIRE(str(tree) == "3(.,4(.,.))");
   }

   SECTION("Insertion dans un arbre simple") {
      tree = generateTree(EASY_VALUES, EASY_VALUES_SIZE);
      tree.insert(5);
      REQUIRE(str(tree) ==
              "8(4(2(.,.),6(5(.,.),.)),14(12(.,.),18(16(.,.),20(.,.))))");
   }

   SECTION("Insertion dans un arbre moyen") {
      tree = generateTree(MEDIUM_VALUES, MEDIUM_VALUES_SIZE);;
      tree.insert(5);
      REQUIRE(str(tree) ==
              "11(7(3(1(.,2(.,.)),5(4(.,.),6(.,.))),9(8(.,.),10(.,.))),15(13(12(.,.),14(.,.)),18(16(.,17(.,.)),19(.,.))))");
   }

   SECTION("Insertion dans un arbre complexe") {
      tree = generateTree(HARDCORE_VALUES, HARDCORE_VALUES_SIZE);
      tree.insert(-33);
      REQUIRE(str(tree) ==
              "-4(-15(-21(-23(-25(-33(.,.),.),-22(.,.)),-17(-20(.,.),.)),-8(-12(-13(.,.),.),-6(-7(.,.),-5(.,.)))),11(6(-2(-3(.,.),5(.,.)),9(7(.,.),10(.,.))),23(15(12(.,13(.,.)),18(.,.)),25(24(.,.),.))))");
   }
}

TEST_CASE("Opérateur = : avlTree &operator=(avlTree const &other)", "[avlTree]") {
   avlTree<int> tree = generateTree(EASY_VALUES, EASY_VALUES_SIZE);

   SECTION("Test avec autre arbre") {
      const avlTree<int> treeCopy = tree;
      REQUIRE(str(tree) == str(treeCopy));
   }

   SECTION("Test avec lui même") {
      avlTree<int> *treeAdr = &tree;
      tree = tree;
      REQUIRE(treeAdr == &tree);
   }
}

TEST_CASE("Contiens valeur : bool contains(Key const& k) const noexcept ;", "[avlTree]") {
   const avlTree<int> tree = generateTree(EASY_VALUES, EASY_VALUES_SIZE);;

   SECTION("Sur un arbre vide") {
      REQUIRE(emptyTree.contains(69) == false);
   }

   // L'arbre est censé contenir 2 et 12
   SECTION("Test positif sur une arbre simple") {
      REQUIRE(tree.contains(2) == true);
      REQUIRE(tree.contains(12) == true);
   }

   // L'arbre n'est PAS censé contenir 42 et 11
   SECTION("Test négatif sur une arbre simple") {
      REQUIRE(tree.contains(42) == false);
      REQUIRE(tree.contains(11) == false);
   }
}

TEST_CASE("min()", "[avlTree]") {
   SECTION("Sur un arbre vide") {
      REQUIRE(emptyTree.min() == 0);
   }

   // L'arbre est censé contenir 1
   SECTION("Test positif sur une arbre moyen") {
      REQUIRE(mediumTree.min() == 1);
   }

   // L'arbre est censé contenir -25
   SECTION("Test positif sur une arbre complexe") {
      REQUIRE(hardTree.min() == -25);
   }
}

TEST_CASE("max", "[avlTree]") {
   SECTION("Sur un arbre vide") {
      REQUIRE(emptyTree.max() == 0);
   }

   // L'arbre est censé contenir 25
   SECTION("Test positif sur une arbre complexe") {
      REQUIRE(hardTree.max() == 25);
   }
}

TEST_CASE("eraseMin()", "[avlTree]") {
   avlTree<int> tree = generateTree(EASY_VALUES, EASY_VALUES_SIZE);;

   SECTION("Valeur min d'un arbre simple est supprimée") {
      tree.eraseMin();
      REQUIRE_FALSE(tree.contains(2));
   }
}

TEST_CASE("eraseMax()", "[avlTree]") {
   avlTree<int> tree = generateTree(EASY_VALUES, EASY_VALUES_SIZE);;

   SECTION("Valeur max d'un arbre simple est supprimée") {
      tree.eraseMax();
      REQUIRE_FALSE(tree.contains(20));
   }
}

TEST_CASE("void erase(Key const& k) noexcept ;", "[avlTree]") {
   avlTree<int> tree = generateTree(EASY_VALUES, EASY_VALUES_SIZE);;

   SECTION("Le Noeud est supprimé") {
      tree.erase(10);
      REQUIRE_FALSE(tree.contains(10));
   }

   SECTION("Le Noeud est supprimé car innexistant") {
      tree.erase(13);
      REQUIRE(str(tree) == str(easyTree));
   }
}

TEST_CASE("unsigned char height() const noexcept;", "[avlTree]") {
   avlTree<int> tree;

   SECTION("Arbre vide -> hauteur = 0") {
      REQUIRE(tree.height() == 0);
   }

   SECTION("Arbre +2 valeurs -> hauteur = 2") {
      tree.insert(1);
      tree.insert(2);
      tree.insert(3);
      REQUIRE(tree.height() == 2);
   }

   SECTION("Arbre ajout de valeur déja contenue et suppression -> hauteur = 1") {
      tree.insert(1);
      tree.insert(2);
      tree.erase(2);
      REQUIRE(tree.height() == 1);
   }
}

TEST_CASE("std::ostream& showIndented(std::ostream& out = std::cout) const;", "[avlTree]") {
   ostringstream oss;

   SECTION("Arbre vide") {
      emptyTree.showIndented(oss);
      REQUIRE(oss.str() == ".\n");
   }

   SECTION("Arbre simple") {
      easyTree.showIndented(oss);
      REQUIRE(oss.str() ==
              "8\n"
              "|_ 4\n"
              "|  |_ 2\n"
              "|  |_ 6\n"
              "|_ 14\n"
              "   |_ 12\n"
              "   |_ 18\n"
              "      |_ 16\n"
              "      |_ 20\n");
   }

   SECTION("Arbre moyen") {
      mediumTree.showIndented(oss);
      REQUIRE(oss.str() ==
              "11\n"
              "|_ 7\n"
              "|  |_ 3\n"
              "|  |  |_ 1\n"
              "|  |  |  |_ .\n"
              "|  |  |  |_ 2\n"
              "|  |  |_ 5\n"
              "|  |     |_ 4\n"
              "|  |     |_ 6\n"
              "|  |_ 9\n"
              "|     |_ 8\n"
              "|     |_ 10\n"
              "|_ 15\n"
              "   |_ 13\n"
              "   |  |_ 12\n"
              "   |  |_ 14\n"
              "   |_ 18\n"
              "      |_ 16\n"
              "      |  |_ .\n"
              "      |  |_ 17\n"
              "      |_ 19\n");


   }

   SECTION("Arbre complexe") {
      hardTree.showIndented(oss);
      REQUIRE(oss.str() ==
              "-4\n"
              "|_ -15\n"
              "|  |_ -21\n"
              "|  |  |_ -23\n"
              "|  |  |  |_ -25\n"
              "|  |  |  |_ -22\n"
              "|  |  |_ -17\n"
              "|  |     |_ -20\n"
              "|  |     |_ .\n"
              "|  |_ -8\n"
              "|     |_ -12\n"
              "|     |  |_ -13\n"
              "|     |  |_ .\n"
              "|     |_ -6\n"
              "|        |_ -7\n"
              "|        |_ -5\n"
              "|_ 11\n"
              "   |_ 6\n"
              "   |  |_ -2\n"
              "   |  |  |_ -3\n"
              "   |  |  |_ 5\n"
              "   |  |_ 9\n"
              "   |     |_ 7\n"
              "   |     |_ 10\n"
              "   |_ 23\n"
              "      |_ 15\n"
              "      |  |_ 12\n"
              "      |  |  |_ .\n"
              "      |  |  |_ 13\n"
              "      |  |_ 18\n"
              "      |_ 25\n"
              "         |_ 24\n"
              "         |_ .\n");
   }
}

TEST_CASE("friend std::ostream &operator<<<>(std::ostream &, avlTree<Key> const &);", "[avlTree]") {
   SECTION("Arbre vide") {
      REQUIRE(str(emptyTree) == str(emptyTree));
   }

   SECTION("Arbre simple") {
      REQUIRE(str(easyTree) ==
              "8(4(2(.,.),6(.,.)),14(12(.,.),18(16(.,.),20(.,.))))");
   }

   SECTION("Arbre moyen") {
      REQUIRE(str(mediumTree) ==
              "11(7(3(1(.,2(.,.)),5(4(.,.),6(.,.))),9(8(.,.),10(.,.))),15(13(12(.,.),14(.,.)),18(16(.,17(.,.)),19(.,.))))");
   }

   SECTION("Arbre complexe") {
      REQUIRE(str(hardTree) ==
              "-4(-15(-21(-23(-25(.,.),-22(.,.)),-17(-20(.,.),.)),-8(-12(-13(.,.),.),-6(-7(.,.),-5(.,.)))),11(6(-2(-3(.,.),5(.,.)),9(7(.,.),10(.,.))),23(15(12(.,13(.,.)),18(.,.)),25(24(.,.),.))))");
   }
}

TEST_CASE("friend std::istream &operator>><>(std::istream &, avlTree<Key> &);", "[avlTree]") {
   avlTree<int> tree;
   stringstream ss;

   SECTION("Arbre vide") {
      ss << ".";
      ss >> tree;
      REQUIRE(str(tree) == ".");
   }

   SECTION("Arbre simple") {
      ss << easyTree;
      ss >> tree;
      REQUIRE(str(tree) == str(easyTree));
   }

   SECTION("Arbre moyen") {
      ss << mediumTree;
      ss >> tree;
      REQUIRE(str(tree) == str(mediumTree));
   }

   SECTION("Arbre complexe") {
      ss << easyTree;
      ss >> tree;
      REQUIRE(str(tree) == str(easyTree));
   }
}