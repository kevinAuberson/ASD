/*
  -------------------------------------------------------------------------------------------------------------------
  Fichier     : ListeSimple.h
  Nom du labo : Labo 6 - Liste Simple
  Auteur(s)   : Auberson Kevin - Faria Dani - Delay Benoit
  Date        : 14.05.2023
  But         : Implémentation d'une liste simple

  Remarque(s) :

  Compilateur : Mingw-w64 g++ 12.2.0
  -------------------------------------------------------------------------------------------------------------------
*/
#ifndef LISTE_H
#define LISTE_H

#include "LSIterator.h"
#include <utility> // std::swap;

template<typename T>
class ListeSimple {
public:
    using value_type = T;
    using reference = T &;
    using const_reference = T const &;

private:
    struct Maillon {
        value_type valeur;
        Maillon *suivant;
    };

    Maillon avant_premier;

public:
    using iterator = LSIterator<value_type>;
    friend iterator;

    using const_iterator = LSConstIterator<value_type>;
    friend const_iterator;

    const_iterator cbegin() const noexcept { return const_iterator(avant_premier.suivant); }

    iterator begin() noexcept { return iterator(avant_premier.suivant); }

    const_iterator begin() const noexcept { return cbegin(); }

    ListeSimple() : avant_premier{value_type{}, nullptr} {
    }

    // A compléter pour fournir ...
    //

    //-------------------------------------Constructeur, Destructeurs, ...--------------------------------------------//

    /**
     * Constructeur par copie
     * @param other
     */
    ListeSimple(const ListeSimple<value_type> &other) : avant_premier{value_type{}, nullptr} {
        iterator it = before_begin();

        for (const_iterator it2 = other.cbegin(); it2 != other.cend(); ++it2) {
            insert_after(it, *it2);
            ++it;
        }
    }

    /**
     * Destructeur
     */
    ~ListeSimple() {
        while (!empty()) {
            pop_front();
        }
    }

    /**
     * Opérateur d'affectation
     * @param other
     * @return
     */
    ListeSimple<value_type> &operator=(const ListeSimple<value_type> &other) {
        if (&other == this)
            return *this;

        else {
            auto tmp(other);
            swap(tmp);
            return *this;
        }
    }

    //--------------------------------Méthodes de modificatio de la liste---------------------------------------------//

    /**
     * Supprimer le premier maillon
     */
    void pop_front() {
        erase_after(before_begin());
    }

    /**
     * Ajoute la valeur au début de la liste
     * @param element
     */
    void push_front(const_reference element) {
        insert_after(before_begin(), element);
    }

    /**
     * Insére un maillon après l'itérateur it
     * @param it
     * @param element
     */
    void insert_after(iterator it, const_reference element) {
        if (it != end())
            it.m->suivant = new Maillon{element, it.m->suivant};
    }

    /**
     * Supprime le maillon suivant
     * @param it
     */
    void erase_after(iterator it) const {
            auto *tmp = it.m->suivant;
            it.m->suivant = tmp->suivant;

            delete tmp;

    }

    /**
     * Déplace la plage d'éléments [begin, end] vers la nouvelle it après l'élément pointé par it
     * @param it
     * @param begin
     * @param end
     */
    void splice_after(iterator it, iterator begin, iterator end) {
        if (begin == end) return;
        std::swap(end.m->suivant, it.m->suivant);
        std::swap(it.m->suivant, begin.m->suivant);
    }

    /**
     * Echange de maillon
     * @param rhs
     */
    void swap(ListeSimple<value_type> &rhs) noexcept {
        std::swap(avant_premier, rhs.avant_premier);
    }

    /**
     * Echange les valeurs entre le maillon itA et itB
     * @param itA
     * @param itB
     */
    void swap_iterateurs(iterator &itA, iterator &itB) {
        if (itA == itB) {
            return;
        }

        else{
            iterator it1, it2;

            for (it1 = before_begin(); std::next(it1) != itA; ++it1) {}
            for (it2 = before_begin(); std::next(it2) != itB; ++it2) {}

            if (it1 != itB)
                splice_after(it1, it2, itB);

            if (it2 != itA)
                splice_after(it2, it1, itA);
        }
    }

    /**
     * Tri par sélection
     */
    void sort() {
        if (empty()) {
            return;
        }

        else {
            iterator j = before_begin(), iMin, i;
            while (j != end()) {
                iMin = i = j;

                while (++i != end())

                    if (*i < *iMin)
                        iMin = i;

                if (j != iMin) {
                    swap_iterateurs(iMin, j);
                }

                else {
                    j = std::next(iMin);
                }
            }
        }

    }

    //------------------------------------------Méthodes de retour----------------------------------------------------//

    /**
     * Renvoie la valeur du premier maillon de la liste
     * @return
     */
    reference front() {
        return avant_premier.suivant->valeur;
    }

    /**
     * Renvoie la valeur du premier maillon de la liste constant
     * @return
     */
    const_reference front() const {
        return avant_premier.suivant->valeur;
    }

    /**
     * Renvoie l'itérateur de fin de liste constant
     * @return
     */
    const_iterator cend() const noexcept {
        return const_iterator(nullptr);
    }

    /**
     * Renvoie l'itérateur de fin de liste
     * @return
     */
    iterator end() noexcept {
        return iterator(nullptr);
    }

    /**
     * Renvoie l'itérateur de fin de liste
     * @return
     */
    const_iterator end() const noexcept {
        return cend();
    }

    /**
     * Vérifie si la liste est vide
     * @return true si oui, false sinon
     */
    bool empty() {
        return avant_premier.suivant == nullptr;
    }

    /**
     * Renvoie l'avant premier itérateur
     * @return iterator
     */
    iterator before_begin() {
        return iterator(&avant_premier);
    }

    //-------------------------------------------------------------------------------------------------------------//

};

#endif //LISTE_H
