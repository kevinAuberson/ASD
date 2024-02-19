#ifndef ASD_LABS_2021_AVLNODEIMPLEMENTATION_H
#define ASD_LABS_2021_AVLNODEIMPLEMENTATION_H

#include <algorithm>

#include "avlNode.h"

namespace avl {

    template<typename Key>
    void insertInSubtree(Node<Key> *&r, Key const &k) {
       if (r == nullptr) {
          r = new Node<Key>{k, Node<Key>::NO_CHILD, 1};
       } else if (k == r->key) {
          return;
       } else {
          Side s = k < r->key ? LEFT : RIGHT;
          insertInSubtree(r->children[s], k);
          rebalanceTree(r);
       }
    }

    template<typename Key>
    std::ostream &showIndented(Node<Key> *r,
                                std::ostream &out,
                                std::string before,
                                bool isright) {
       out << before;
       if (not r) {
          out << ".\n";
       } else {
          if (not before.empty()) {
             before[before.size() - 2] = ' ';
             if (isright) {
                before[before.size() - 3] = ' ';
             }
          }
          out << r->key << std::endl;
          if (r->children != Node<Key>::NO_CHILD) {
             for (Side s: {LEFT, RIGHT}) {
                showIndented(r->children[s], out, before + "|_ ", s);
             }
          }
       }
       return out;
    }

    template<typename Key>
    std::ostream &operator<<(std::ostream &out, Node<Key> *const &r) {
       if (r == nullptr)
          return out << ".";

       else
          return out << r->key << "(" << r->left() << "," << r->right() << ")";
    }

    template<typename Key>
    std::istream &operator>>(std::istream &in, Node<Key> *&r) {

       if (!isdigit(in.peek()))
          return in.ignore();

       else {
          Key k;

          in >> k;
          insertInSubtree(r, k);
          in.ignore();

          // Print de la valeur à gauche de la racine
          in >> r->left();
          in.ignore();

          // Print de la valeur à droite de la racine
          in >> r->right();
          in.ignore();

          return in;
       }
    }

    template<typename Key>
    Node<Key> *copyFromOtherRoot(Node<Key> *const &otherRoot) {
       if (otherRoot == nullptr)
          return nullptr;

       else {
          auto tmpNode = new Node<Key>{otherRoot->key, Node<Key>::NO_CHILD, otherRoot->height};
          tmpNode->right() = copyFromOtherRoot(otherRoot->right());
          tmpNode->left() = copyFromOtherRoot(otherRoot->left());
          return tmpNode;
       }
    }

    template<typename Key>
    void eraseSubtree(Node<Key> *&r) {
       if (r == nullptr)
          return;

       else {
          eraseSubtree(r->right());
          eraseSubtree(r->left());
          delete r;
          r = nullptr;
       }
    }

    template<typename Key>
    bool keyIsInSubtree(Node<Key> *r, Key k) {
       if (r == nullptr)
          return false;

       else if (r->key == k)
          return true;

       else {
          bool keyFound = false;

          if (k > r->key && r->children[RIGHT])
             keyFound = keyIsInSubtree(r->children[RIGHT], k);

          else if (r->children[LEFT])
             keyFound = keyIsInSubtree(r->children[LEFT], k);

          return keyFound;

       }
    }

    template<typename Key>
    const Key &max(Node<Key> *const &r) {
       if (r->right() != nullptr)
         return max(r->right());

       else
          return r->key;
    }

    template<typename Key>
    const Key &min(Node<Key> *const &r) {
       if (r->left() != nullptr)
          return min(r->left());

       else
         return r->key;
    }

    template<typename Key>
    Node<Key> *minNode(Node<Key> *&r) {
       if (r->left() != nullptr)
          return minNode(r->left());

       else {
          auto tmpRoot = r;
          r = r->right();
          return tmpRoot;
       }
    }

    template<typename Key>
    void erase(Node<Key> *&r, const Key &k) {
       if (r == nullptr)
          return;

       else if (r->key > k)
          erase(r->left(), k);

       else if (r->key < k)
          erase(r->right(), k);

       else {
          if (r->left() == nullptr)
             r = r->right();

          else if (r->right() == nullptr)
             r = r->left();

          else if (r->children != Node<Key>::NO_CHILD) {
             auto tmpNode = minNode(r->right());
             tmpNode->right() = r->right();
             tmpNode->left() = r->left();
             r = tmpNode;
          }
       }
       rebalanceTree(r);
    }

    template<typename Key>
    unsigned char height(const Node<Key> *const &r) {
       if (r == nullptr)
          return 0;
       else
          return r->height;
    }

    template<typename Key>
    unsigned char newHeight(Node<Key> *const &r) {
       if (!r)
          return 0;

       else {
          r->height = (unsigned char) (std::max(newHeight(r->left()), newHeight(r->right())) + 1);
          return r->height;
       }
    }

    template<typename Key>
    int treeBalance(Node<Key> *&r) {
       if (!r)
          return 0;

       else
          return (height(r->left()) - height(r->right()));
    }

    template<typename Key>
    void rotateRight(Node<Key> *&r) {
       auto tmpNode = r->left();

       r->left() = tmpNode->right();
       tmpNode->right() = r;
       r = tmpNode;
       newHeight(r->right());
       newHeight(r);
    }

    template<typename Key>
    void rotateLeft(Node<Key> *&r) {
       auto tmpNode = r->right();

       r->right() = tmpNode->left();
       tmpNode->left() = r;
       r = tmpNode;
       newHeight(r->left());
       newHeight(r);
    }

    template<typename Key>
    void rebalanceTree(Node<Key> *&r) {
       if (r == nullptr)
          return;
       else {
          int treeBalanceVal = treeBalance(r);

          if (treeBalanceVal < -1) {
             if (treeBalance(r->right()) > 0)
                rotateRight(r->right());
             rotateLeft(r);
          }
          else if (treeBalanceVal > 1) {
             if (treeBalance(r->left()) < 0)
                rotateLeft(r->left());
             rotateRight(r);

          }
          else
             newHeight(r);
       }
    }
}  // namespace avl

#endif  // ASD_LABS_2021_AVLNODEIMPLEMENTATION_H
