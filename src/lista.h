#pragma once
#include <cstddef>
#include <iostream>

/**
 * @brief Pojedynczy wêze³ listy dwukierunkowej.
 */
struct Node {
    int data;       ///< Wartoœæ przechowywana w wêŸle
    Node* prev;     ///< WskaŸnik do poprzedniego elementu
    Node* next;     ///< WskaŸnik do nastêpnego elementu

    /**
     * @brief Konstruktor inicjalizuj¹cy nowy wêze³.
     * @param value Wartoœæ przechowywana w wêŸle.
     */
    explicit Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

/**
 * @brief Klasa reprezentuj¹ca listê dwukierunkow¹.
 */
class lista {
private:
    Node* head;  ///< Pocz¹tek listy
    Node* tail;  ///< Koniec listy
    std::size_t sz; ///< Liczba elementów listy

public:
    lista();
    ~lista();

    void pushBack(int value);
    void pushFront(int value);
    void popFront();
    void popBack();
    void clear();
    void displayForward() const;
    void displayBackward() const;
    void insertAt(int index, int value);  // dodaj element pod wskazany indeks
    void removeAt(int index);             // usuñ element spod wskazanego indeksu

    /**
     * @brief Sprawdza, czy lista jest pusta.
     * @return true jeœli lista jest pusta.
     */
    bool empty() const { return sz == 0; }

    /**
     * @brief Zwraca liczbê elementów listy.
     */
    std::size_t size() const { return sz; }

    /**
     * @brief Klasa wewnêtrzna s³u¿¹ca do iterowania po liœcie.
     *
     * Pozwala na przechodzenie po elementach listy bez bezpoœredniego dostêpu do wskaŸników.
     */
    class Iterator {
    private:
        Node* current; ///< Bie¿¹cy element listy
    public:
        /**
         * @brief Konstruktor iteratora.
         * @param start WskaŸnik do pierwszego elementu listy.
         */
        Iterator(Node* start) : current(start) {}

        /**
         * @brief Sprawdza, czy istnieje kolejny element listy.
         */
        bool hasNext() const { return current != nullptr; }

        /**
         * @brief Zwraca wartoœæ bie¿¹cego elementu i przechodzi do nastêpnego.
         * @return Wartoœæ elementu.
         */
        int next() {
            int value = current->data;
            current = current->next;
            return value;
        }

        bool hasPrevious() const { return current != nullptr; }

        int previous() {
            int value = current->data;
            current = current->prev;
            return value;
        }




    };

    /**
     * @brief Zwraca iterator ustawiony na pocz¹tek listy.
     */
    Iterator getIterator() const { return Iterator(head); }
};
