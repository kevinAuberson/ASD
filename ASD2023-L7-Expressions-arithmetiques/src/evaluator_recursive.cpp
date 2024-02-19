#include "evaluator.h"
#include <cctype>
#include <string>

/**
 * Fonction pour convertir le string en int
 * @param str Expression a convertir en string
 * @return int du string
 */
int strVersInt(std::string &str) {
    int val;
    if (!str.empty()) {
        val = std::stoi(str);
        str = "";
        return val;
    } else
        throw bad_expression();
}

/**
 * Fonction recursive qui prend en parametre une expression et retourne son résultat
 * @param expression
 * @return valeur de l'expression évaluée
 */
int evalue(std::string const &expression) {
    if (expression.empty())
        throw bad_expression();

    char    op;
    int     valGauche,
            valDroite,
            nmbPaireParentheses = 0,
            resultat,
            debut,
            fin,
            index = 0;

    std::string tempStr,
                exp;

    bool estValGauche = true;

    // Vérifie si le nombre de parenthèses sont correctes
    // et copie chaque valeur sans les  éventuelles paranthèses dans le string exp
    for (char e: expression) {
        if (e != ' ')
            exp.push_back(e);

        if (e == '(')
            ++nmbPaireParentheses;

        else if (e == ')')
            --nmbPaireParentheses;
    }

    if (nmbPaireParentheses != 0)
        throw bad_expression();


    //Calcule les bornes du prochain élément a calucler
    for (char c: exp) {
        if (c == '(')
            debut = index;
        if (c == ')') {
            fin = index;
            break;
        }
        index++;
    }

    // Copie la valeur à calculer comprise entres les bornes trouvées
    std::string expToEvaluate = exp.substr(
            static_cast<uint32_t>(debut + 1),
            static_cast<uint32_t>(fin - debut - 1));

    //Boucle pour stocker la valeur de gauche jusqu'a ce que on tombe sur un opérateur
    for (char e: expToEvaluate) {

        switch (e) {

            case '-':
                if ((estValGauche && tempStr.empty()) or !estValGauche) {
                    tempStr.push_back('-');
                } else {
                    op = e;
                    valGauche = strVersInt(tempStr);
                    estValGauche = false;
                }
                break;

            case '+':
            case '/':
            case '%':
            case '*':
                op = e;
                valGauche = strVersInt(tempStr);
                estValGauche = false;
                break;

            default:
                if (isdigit(e)) {
                    tempStr.push_back(e);
                } else
                    throw bad_expression();
                break;
        }

    }

    // On stocke le reste  qui est forcément la valeur a droite de l'opérateur
    valDroite = strVersInt(tempStr);

    switch (op) {

        case '+':
            resultat = valGauche + valDroite;
            break;
        case '-':
            resultat = valGauche - valDroite;
            break;
        case '*':
            resultat = valGauche * valDroite;
            break;
        case '/':
            resultat = valGauche / valDroite;
            break;
        case '%':
            resultat = valGauche % valDroite;
            break;

        default:
            resultat = 0;
            break;
    }

    //Reprends les bornes et remplace l'expression calculée par son résultat
    exp = exp.replace(static_cast<uint32_t>(debut), static_cast<uint32_t>(fin - debut + 1), std::to_string(resultat));

    // Si il reste une paranthèse ouvrante, on relance la fonction récursive,
    // sinon on retourne en int le string de la valeur restante
    if (exp[0] != '(')
        return std::stoi(exp);

    else
        return evalue(exp);
}