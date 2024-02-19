#ifndef ArrayDeque_h
#define ArrayDeque_h

#include <cstddef> // std::size_t
#include <ostream> // std::ostream
// Ajoutez si nécessaire d'autres inclusions de librairies
#include <stdexcept> // std::out_of_range

template<class T>
class ArrayDeque {
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using size_type = std::size_t;

    explicit ArrayDeque(size_type _capacite = 0) : debut(0),
                                                   taille(0),
                                                   capacite(_capacite),
                                                   buffer(nullptr) {
        if (capacite)
            buffer = reinterpret_cast<pointer> (
                    ::operator new(capacite * sizeof(value_type)));
    }
    /******************************************************************************************************************/

    // Placez ici les méthodes publiques nécessaires pour passer le codecheck

    /**
     * Constructeur par copie
     * @param autreBuffer
     */
    ArrayDeque<value_type>(ArrayDeque const &autreBuffer) : buffer(nullptr), capacite(autreBuffer.capacite), debut(autreBuffer.debut),
                                                      taille(autreBuffer.taille) {
        if (capacite)
            buffer = reinterpret_cast<pointer> (
                    ::operator new(capacite * sizeof(value_type)));

        for (size_type i = 0; i < taille; ++i) {
            try {
                new(buffer + indicePhysique(i)) value_type{autreBuffer[i]};
            }
            catch (std::exception &e) {
                for (size_type j = 0; j < i; ++j) {
                    buffer[indicePhysique(j)].~value_type();
                }
                ::operator delete(buffer);
                throw e;
            }
        }
    }

    /**
     * Destructeur
     */
    ~ArrayDeque() {
        for (size_type i = 0; i < taille; i++) {
            buffer[indicePhysique(i)].~value_type();
        }
        ::operator delete(buffer);
        buffer = nullptr;
    }



    /**
     * Surchage de l'opérateur = pour la classe ArrayDeque
     * @param autreBuffer
     * @return
     */
    ArrayDeque &operator=(const ArrayDeque &autreBuffer) {
        if (this == &autreBuffer)
            return *this;

        if (capacite < autreBuffer.taille) {
            ArrayDeque<value_type> tmp(autreBuffer);
            this->swap(tmp);
        } else {

           pointer tmp = reinterpret_cast<pointer> (::operator new(capacite * sizeof(value_type)));

            for (size_type i = 0; i < autreBuffer.taille; ++i) {
                try {
                    new(tmp + indicePhysique(i)) value_type{autreBuffer.buffer[autreBuffer.indicePhysique(i)]};
                }

                catch (std::exception &element) {
                    for (size_type j = 0; j < i; ++j) {
                        tmp[indicePhysique(j)].~value_type();
                    }
                    ::operator delete(tmp);
                    throw element;
                }
            }

            for (size_type i = autreBuffer.taille; i < taille; ++i) {
                buffer[indicePhysique(i)].~value_type();
            }

            capacite = autreBuffer.capacite;
            taille = autreBuffer.taille;
        }
        return *this;
    }

    /******************************************************************************************************************/

    /**
     *
     * @return Taille du Buffer
     */
    [[nodiscard]] size_type size() const noexcept { return taille; };

    /******************************************************************************************************************/

    /**
     *
     * @return Capacité du Buffer
     */
    [[nodiscard]] size_type capacity() const { return capacite; };

    /******************************************************************************************************************/

    /**
     * @return Valeur indiquant si le buffer est vide
     */
    [[nodiscard]] bool empty() const { return taille == 0; };

    /******************************************************************************************************************/

    /**
     * @return Référance du 1er élèment du Buffer
     */
    reference front() const {
        if (empty()) {
            throw std::out_of_range("front");
        }
        return this->at(0);
    };

    /******************************************************************************************************************/

    /**
     *
     * @return Référance du dernier élèment du Buffer
     */
    reference back() const {
        if (empty()) {
            throw std::out_of_range("front");
        }
        return this->at(taille - 1);
    };

    /******************************************************************************************************************/

    /**
     * Méthode permetant de changer la capacite du Buffer
     * @param nouvelleCapacite Nouvelle capacité a attribuer au Buffer
     */
    void changerCapaciteBuffer(size_t nouvelleCapacite) {
        pointer tmpBuffer = reinterpret_cast<pointer>(::operator new(nouvelleCapacite * sizeof(value_type)));

        // Crée un nouveau Buffer avec la bonne taille et la bonne capacité
        for (size_type i = 0; i < taille; ++i) {
            try {
                new(tmpBuffer + i) value_type{buffer[indicePhysique(i)]};
            }
            catch (std::exception &element) {
                for (size_type j = 0; j < i; ++j) {
                    tmpBuffer[indicePhysique(j)].~value_type();
                }
                ::operator delete(tmpBuffer);
                throw element;
            }
        }

        // Détruit toutes les valeurs de l'ancien Buffer
        for (size_type i = 0; i < taille; ++i) {
            buffer[indicePhysique(i)].~value_type();
        }

        ::operator delete(buffer);
        buffer = tmpBuffer;
        capacite = nouvelleCapacite;
        debut = 0;
    }

    /******************************************************************************************************************/

    /**
     * Ajoute un élément à la fin du buffer
     * @param element
     */
    void push_back(const value_type &element) {

        if (taille >= capacite)
            changerCapaciteBuffer((taille > 0) ? (taille * 2) : 1);

        new(buffer + indicePhysique(taille)) value_type{element};
        ++taille;


    }

    /******************************************************************************************************************/

    /**
     * Ajoute un élément au début du buffer
     * @param element
     */
    void push_front(const value_type &element) {
        if (taille >= capacite)
            changerCapaciteBuffer((taille > 0) ? (taille * 2) : 1);

        try {
            debut = (debut ? debut : capacite) - 1;
            new(buffer + indicePhysique(0)) value_type{element};
        }

        catch (std::exception &element) {
            debut = (debut == capacite - 1) ? 0 : debut + 1;
            throw element;
        }

        ++taille;
    }

    /******************************************************************************************************************/

    /**
     * Réduit la capacité à la taille du buffer
     */
    void shrink_to_fit() {
        if (capacite == taille) {
            return;
        }

        else {
            changerCapaciteBuffer(taille);
        }

    }

    /******************************************************************************************************************/

    /**
     * Echange des propriétés entre 2 objets
     * @param autre
     */
    void swap(ArrayDeque<value_type> &autre) noexcept {
        if (&autre != this) {
            std::swap(buffer, autre.buffer);
            std::swap(capacite, autre.capacite);
            std::swap(debut, autre.debut);
            std::swap(taille, autre.taille);
        }
    }

    /******************************************************************************************************************/

    /**
     * Supprime l'élément du début
     */
    void pop_front() {
        if (empty())
            throw std::out_of_range("pop front");

        --taille;
        buffer[debut].~value_type();
        debut = (debut + 1) % capacite;


    }

    /******************************************************************************************************************/

    /**
     * Supprime l'élément de fin
     */
    void pop_back() {
        if (empty()) {
            throw std::out_of_range("pop back");
        }

        buffer[(debut + --taille) % capacite].~value_type();

    }

    /******************************************************************************************************************/

    /**
     * Opérateur pour atteindre un index i du buffer
     * @param i
     * @return élément à l'index i
     */
    reference operator[](size_type i) const {
        if (i >= taille) {
            throw std::out_of_range("operator[]");
        }

        return this->at(i);

    }

    /******************************************************************************************************************/

private:
    pointer buffer;
    size_type capacite;
    size_type debut;
    size_type taille;

    // Placez ici les méthodes privées qui permettent de rendre votre code plus clair

    /******************************************************************************************************************/

    /**
     * Conversion de l'adresse logique en physique
     * @param indiceLogique Position logique du Buffer
     * @return  la position physique du Buffer
     */
    [[nodiscard]] size_type indicePhysique(size_type indiceLogique) const {
        return (debut + indiceLogique + capacite) % capacite;
    }

    /******************************************************************************************************************/

    /**
     *
     * @param position
     * @return une référence sur la valeur à la position
     */
    reference at(size_type position) const {
        if (position >= taille)
            throw std::out_of_range("at");

        return buffer[indicePhysique(position)];
    }

    /******************************************************************************************************************/

};

template<typename T>
inline
std::ostream &operator<<(std::ostream &s,
                         const ArrayDeque<T> &v) {
    s << "(" << v.size() << "/" << v.capacity() << ") : ";
    if (not v.empty())
        s << v.front() << " -> " << v.back() << " : ";
    s << "[";
    for (int i = 0; i < v.size(); ++i) {
        s << v[i];
        if (i != v.size() - 1)
            s << ", ";
    }
    s << "]";
    return s;
}


#endif /* ArrayDeque_h */
