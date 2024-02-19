#ifndef ASD_2021_AVL_IMPL_H
#define ASD_2021_AVL_IMPL_H

#include <utility>
#include <algorithm>
#include <ostream>

template<typename Key>
avlTree<Key>::avlTree() : root(nullptr) {
}

template<typename Key>
avlTree<Key>::~avlTree() {
   avl::eraseSubtree(root);
}

template<typename Key>
void avlTree<Key>::insert(Key const& k) {
    avl::insertInSubtree(root, k);
}

template<typename Key>
avlTree<Key>::avlTree(avlTree const &other) : root(nullptr){
   root = avl::copyFromOtherRoot(other.root);
}

template<typename Key>
avlTree<Key> &avlTree<Key>::operator=(const avlTree<Key> &other){
   if(this == &other || this->root == other.root)
      return *this;

   else {
      avlTree<Key> tmp(other);
      std::swap(root,tmp.root);
      return *this;
   }
}

template<typename Key>
bool avlTree<Key>::contains(Key const& k) const noexcept{
   if (root == nullptr)
      return false;

   else {
      if(root->key == k)
         return true;

      else if(root->key > k)
         return avl::keyIsInSubtree(root->left(), k);

      else
         return avl::keyIsInSubtree(root->right(), k);
   }
}

template<typename Key>
const Key &avlTree<Key>::min() const{
   if(root)
      return avl::min(root);

   else {
      static const Key defaultValue = Key();
      return defaultValue;
   }
}

template<typename Key>
const Key &avlTree<Key>::max() const{
   if(root)
      return avl::max(root);

   else {
      static const Key default_value = Key();
      return default_value;
   }
}

template<typename Key>
void avlTree<Key>::eraseMin() {
   erase(min());
}

template<typename Key>
void avlTree<Key>::eraseMax() {
   erase(max());
}

template<typename Key>
void avlTree<Key>::erase(const Key &k) noexcept {
   avl::erase(root, k);
}

template<typename Key>
std::ostream& avlTree<Key>::showIndented(std::ostream& out) const {
    return avl::showIndented(root, out);
}

template<typename Key>
std::ostream &operator<<(std::ostream & out, avlTree<Key> const & tree) {
    out << tree.root;
    return out;
}

template<typename Key>
std::istream &operator>>(std::istream &in, avlTree<Key> &tree) {
   in >> tree.root;
   return in;
}

template<typename Key>
[[nodiscard]] unsigned char avlTree<Key>::height() const noexcept {
   if(root == nullptr)
      return 0;

   else
      return root->height;
}

#endif //ASD_2021_AVL_IMPL_H
