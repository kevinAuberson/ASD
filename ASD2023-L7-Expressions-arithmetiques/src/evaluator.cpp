/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : evaluator.cpp
  Nom du labo : Labo 7 - Expressions arithmetiques
  Auteur(s)   : Auberson Kevin - Faria Dani - Delay Benoit
  Date        : 28.05.2023
  But         : Implémentation de l'algorithme de Dijkstra

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#include "evaluator.h"
#include <cctype>
#include <stack> // std::stack
#include <string>



int evalue(std::string const& expression) {

    if (expression.empty())
        throw bad_expression();

    std::stack<char> pileOp;
    std::stack<int> pileVal;

    size_t nbrElements = expression.size();
    size_t pos = 0;

    int resultat = 0;
    char element;
    std::string nombre;

    // réparti les différents caractères dans la pile opérateur et pile valeur
    while (nbrElements) {
        element = expression[pos];
        if (element == '(' or element == ' ') {
            ++pos;
            --nbrElements;
            continue;
        }
        else if (element == '+' or element == '-' or element == '*' or element == '/' or element == '%') {
            pileOp.push(element);

        }
        else if (isdigit(element)) {
            nombre += element;

            // pour les nombres
            if (!isdigit(expression[pos + 1])) {
                pileVal.push(std::stoi(nombre));
                nombre = "";
            }
        }
        // calcul des expressions entre parenthèse
        else if (element == ')') {

            if (pileVal.size() < 2) {
                throw bad_expression();
            }

            int v2 = pileVal.top();
            pileVal.pop();
            int v1 = pileVal.top();
            pileVal.pop();

            char op = pileOp.top();
            pileOp.pop();


            switch (op) {
                case '+':
                    resultat = v1 + v2;
                    break;
                case '-':
                    resultat = v1 - v2;
                    break;
                case '*':
                    resultat = v1 * v2;
                    break;
                case '/':
                    resultat = v1 / v2;
                    break;
                case '%':
                    resultat = v1 % v2;
                    break;
                default:
                    resultat = 0;
                    break;
            }

            pileVal.push(resultat);

        } else {
            throw bad_expression();
        }
        ++pos;
        --nbrElements;
    }

    if (!pileOp.empty())
        throw bad_expression();

    return resultat;

}
