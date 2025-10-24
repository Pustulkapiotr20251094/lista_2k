#pragma once
#include <cstddef>
#include <iostream>

/**
 * @brief Pojedynczy w�ze� listy dwukierunkowej.
 */
struct Node {
    int data;       ///< Warto�� przechowywana w w�le
    Node* prev;     ///< Wska�nik do poprzedniego elementu
    Node* next;     ///< Wska�nik do nast�pnego elementu

    /**
     * @brief Konstruktor inicjalizuj�cy nowy w�ze�.
     * @param value Warto�� przechowywana w w�le.
     */
    explicit Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

/**
 * @brief Klasa reprezentuj�ca list� dwukierunkow�.
 */
class lista {
private:
    Node* head;  ///< Pocz�tek listy
    Node* tail;  ///< Koniec listy
    std::size_t sz; ///< Liczba element�w listy

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
    void removeAt(int index);             // usu� element spod wskazanego indeksu

    /**
     * @brief Sprawdza, czy lista jest pusta.
     * @return true je�li lista jest pusta.
     */
    bool empty() const { return sz == 0; }

    /**
     * @brief Zwraca liczb� element�w listy.
     */
    std::size_t size() const { return sz; }

    /**
     * @brief Klasa wewn�trzna s�u��ca do iterowania po li�cie.
     *
     * Pozwala na przechodzenie po elementach listy bez bezpo�redniego dost�pu do wska�nik�w.
     */
    class Iterator {
    private:
        Node* current; ///< Bie��cy element listy
    public:
        /**
         * @brief Konstruktor iteratora.
         * @param start Wska�nik do pierwszego elementu listy.
         */
        Iterator(Node* start) : current(start) {}

        /**
         * @brief Sprawdza, czy istnieje kolejny element listy.
         */
        bool hasNext() const { return current != nullptr; }

        /**
         * @brief Zwraca warto�� bie��cego elementu i przechodzi do nast�pnego.
         * @return Warto�� elementu.
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
     * @brief Zwraca iterator ustawiony na pocz�tek listy.
     */
    Iterator getIterator() const { return Iterator(head); }
};
