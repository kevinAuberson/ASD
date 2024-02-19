# Rapport 

# Analyse
Il y a 9 pièces, chaque pièce peut avoir 4 états :
- Haut : a
- Droite : b
- Bas : c
- Gauche : D

On peut donc considérer 4 x 9 pièces possibles à un emplacement donné.
Pour le deuxième emplacement, il y aura 8 x 4 pièces possibles.
Pour le troisième ... 7 x 4
...
Pour le dernier ...1 x 4

... Il y a $(4^n) \cdot (n!)$ possibilités et si on se fie à la boite une seule est juste.

Donc on aura une formule du type $\displaystyle \frac{1}{(4^n)x(n!)}$ pour déterminer ses probabilités.

Le meilleur cas est un $O(1)$ et le pire un $O(4^{n}\cdot n!)$ où $n=9$.

Le nombre de possibilités numériques est de **95'126'814'720**, la solution offerte par le professeur est la : **1b 5d 4a 7a 6a 2a 8a 3a 9d**

## Idée de base

Nous voulions partir sur le principe de poser une première carte en haut à gauche et ainsi vérifier toutes les positions comme expliqué dans le diagramme ci-dessous :

![alt text](https://github.com/kevinAuberson/ASD2023-L2-Recursivite/blob/main/rapport/diagramme.jpg?raw=true)

Si le chemin est bon, on continue, sinon on quitte la "branche" actuelle. Si le chemin arrive jusqu'à la dernière carte (la 8ème carte le vecteur va de 0 à 8) et que celle-ci est compatible, on valide la combinaison.

# Code

Le code contient une classe **Carte** et un fichier de fonctions nommé **resolutionCartes** qui contiens les différentes fonctions nécessaires.

## Carte

Carte permet de créer des objets "Cartes" qui ont un ID unique et un vecteur conteant leur symbole.
Ces cartes peuvent être "tournées" afin que l'on puisse essayer toutes les combinaisons possibles.
Le but de cette classe et de pouvoir manipulés les cartes plus facilement et ainsi pouvoir simplifier le reste du projet.

```C++
enum sens {
    HAUT, DROITE, BAS, GAUCHE
};

class Carte {

public:
    Carte(const Piece &piece, const Pieces& pieces);

    void tournerCarte();
    AttachementType getValeurCote(sens cote);

    std::vector<AttachementType>& getSymboles();
    size_t getID() const;

private:
    static size_t next_id;
    size_t id;
    std::vector<AttachementType> symbolesCarte;
    Pieces piecesCompatible;

};

```
## resolutionCartes
Ce fichier comporte différentes fonctions utiles, comme la fonction peiceNecessaire qui va vérifier si les côtes correspondent exemple : FILLE_HAUT et FILLE_BAS
conversionFormatProf va prendre le vecteur de la solution et la transcrire comme voulu par le professeur, c'est-à-dire : "N°" avec N un chiffre entre 1 et 9 codant la pièce à placer et o une lettre entre 'a' et 'd' codant l'orientation.


# Problèmes

Malheureusement, le projet n'a pas pu aboutir, en effet, malgré les innombrables heures passées dessus et toutes les différentes approches tentées en vain, nous n'avons pas pu trouver une solution. La vérification est restée bloquée à la phase de l'ordre des cartes. C'est-à-dire que si les cartes sont déjà dans le bon ordre, mais pas dans la bonne orientation le programme fonctionne. Nous n'arrivons pas à trouver une solution qui va vérifier chaque position possible unique, si cela était trouvé notre programme serait concluant. Mais à cause de ce petit détail, 3/4 des questions de ce projet resteront sans réponse à notre plus grand regret.

PS : En plus de cela, un membre de notre groupe a effectué un formatage automatique sur le fichier pieces.cpp du professeur, il a été donc "modifié" par erreur et vu notre compétence incroyable a utiliser un outil aussi simple et logique que GIT nous n'avons pas pu faire marche arrière. En plus de cela pour notre dernier projet la mise en place du tag "Rendu" ne marchait pas et vu que nous n'avons aucune idée de comment utiliser GIT (sans parler des bouts de codes supprimés lors des merges) il se peut que le tag ne soit pas mis à temps.
