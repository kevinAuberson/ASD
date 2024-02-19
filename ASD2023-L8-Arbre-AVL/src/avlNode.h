#ifndef ASD_LABS_2021_AVLNODE_H
#define ASD_LABS_2021_AVLNODE_H

namespace avl {

    enum Side {
        LEFT = 0, RIGHT = 1
    };

    template<typename Key>
    struct Node {
        Key const key;
        std::array<Node*, 2> children;
        unsigned char height;

        inline Node*& left() noexcept { return children[LEFT]; }
        inline Node* const& left() const noexcept { return children[LEFT]; }
        inline Node*& right() noexcept { return children[RIGHT]; }
        inline Node* const& right() const noexcept { return children[RIGHT]; }

        static constexpr std::array<Node*, 2> NO_CHILD{nullptr, nullptr};
    };

    template<typename Key>
    void insertInSubtree(Node<Key>*& r, Key const& k);

    template<typename Key>
    std::ostream&  showIndented(Node<Key> *r,
                       std::ostream &out = std::cout,
                       std::string before = "",
                       bool isright = false);

    /**
     * Efface les sous arbres à partir de une racine ou noeud ?
     * @tparam Key
     * @param r Racine ou noeud de départ
     */
    template<typename Key>
    void eraseSubtree(Node<Key>*& r);


    /**
     * Copie les valeurs d'une Racine/Noeud et les renvoie
     * @tparam Key
     * @param otherRoot Autre Racine/Noeud qui recois la copie
     */
    template<typename Key>
    Node<Key>* copyFromOtherRoot(Node<Key>* const& otherRoot);


    /**
     * Indique si une valeur est présente dans/sous un Noeud/Racine
     * @tparam Key
     * @param r Noeud/Racine à parcourir
     * @param k Clé à chercher
     * @return
     */
    template<typename Key>
    bool keyIsInSubtree(Node<Key>* r, Key k);

    /**
     * Retourne la valeur la plus petite valeur contenue dans/sous le Noeud/Racine
     * @tparam Key
     * @param r Noeud/Racine à parcourir
     * @return valeur la plus petite
     */
    template<typename Key>
    const Key& min(Node<Key>* const &r);

    /**
     * Retourne la valeur la plus grande valeur contenue dans/sous le Noeud/Racine
     * @tparam Key
     * @param r Noeud/Racine à parcourir
     * @return  valeur la plus grande
     */
    template<typename Key>
    const Key& max(Node<Key>* const &r);

    /**
     * Retourne le Noeud avec la valeur la plus petite contenue dans/sous le Noeud/Racine
     * @tparam Key
     * @param r Noeud/Racine à parcourir
     * @return Noeud valeur la plus grande
     */
    template<typename Key>
    Node<Key>* minNode(Node<Key>*& r);

    /**
     * Réequilibre un arbre avec le principe vu en cours
     * @tparam Key
     * @param r Noeud/Racine à réequilibrer
     */
    template<typename Key>
    void rebalanceTree(Node<Key>*& r);

    /**
     * Retourne l'équilibre du Noeud/Racine
     * @tparam Key
     * @param r Noeud/Racine à analyser
     * @return Equilibre de r
     */
    template<typename Key>
    int treeBalance(Node<Key>*& r);

    /**
     * Effecture une rotation droite sur le noeud/racine
     * @tparam Key
     * @param r Noeud/Racine a tourner
     */
    template<typename Key>
    void rotateRight(Node<Key>*& r);

    /**
    * Effecture une rotation gauche sur le noeud/racine
    * @tparam Key
    * @param r Noeud/Racine a tourner
    */
    template<typename Key>
    void rotateLeft(Node<Key>*& r);

    /**
     * Trouve la hauteur à partir du noeud/racine
     * @tparam Key
     * @param r
     * @return Noeud/Racine a analyser
     */
    template<typename Key>
    unsigned char height(const Node<Key>* const& r);

    /**
     * Retourne la nouvelle taille du noeud/raceine
     * @tparam Key
     * @param r Noeud/Racine a analyser
     * @return Taille la plus grande du Noeud/Racine
     */
    template<typename Key>
    unsigned char newHeight(const Node<Key>* const& r);

    template<typename Key>
    void erase(Node<Key>*& r, const Key& k);

    template<typename Key>
    std::ostream& operator<<(std::ostream& out, Node<Key>* const& r);

    template<typename Key>
    std::istream& operator>>(std::istream& in, Node<Key>*& r);


}

#include "avlNodeImplementation.h"

#endif //ASD_LABS_2021_AVLNODE_H
