#pragma once
#include <cstddef>
#include <iostream>

/**
 * @file Lista.h
 * @brief Definicje klasy lista i struktury Node dla listy dwukierunkowej.
 *
 * Plik zawiera deklaracje struktur i klas uzywanych do implementacji
 * listy dwukierunkowej wraz z iteratorami pozwalajacymi na przechodzenie
 * po elementach w obu kierunkach.
 */

 /**
  * @brief Pojedynczy wezel listy dwukierunkowej.
  *
  * Struktura przechowuje wartosc oraz wskazniki do poprzedniego   
  * i nastepnego wezla w liscie.
  */
struct Node {
    int data;       ///< Wartosc przechowywana w wezle
    Node* prev;     ///< Wskaznik do poprzedniego elementu
    Node* next;     ///< Wskaznik do nastepnego elementu

    /**
     * @brief Konstruktor inicjalizujacy nowy wezel.
     * @param value Wartosc przechowywana w wezle.
     */
    explicit Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

/**
 * @brief Klasa reprezentujaca liste dwukierunkowa.
 *
 * Klasa lista umozliwia dodawanie, usuwanie i przegladanie elementow,
 * a takze oferuje iteratory do poruszania sie po elementach listy.
 */
class lista {
private:
    Node* head;   ///< Wskaznik do pierwszego elementu listy
    Node* tail;   ///< Wskaznik do ostatniego elementu listy
    std::size_t sz; ///< Liczba elementow w liscie

public:
    /**
     * @brief Konstruktor domyslny klasy lista.
     *
     * Inicjalizuje pusta liste bez elementow.
     */
    lista();

    /**
     * @brief Destruktor klasy lista.
     *
     * Zwalnia pamiec zajmowana przez elementy listy.
     */
    ~lista();

    /**
     * @brief Dodaje element na koniec listy.
     * @param value Wartosc elementu do dodania.
     */
    void pushBack(int value);

    /**
     * @brief Dodaje element na poczatek listy.
     * @param value Wartosc elementu do dodania.
     */
    void pushFront(int value);

    /**
     * @brief Usuwa pierwszy element z listy.
     */
    void popFront();

    /**
     * @brief Usuwa ostatni element z listy.
     */
    void popBack();

    /**
     * @brief Usuwa wszystkie elementy z listy.
     */
    void clear();

    /**
     * @brief Wyswietla zawartosc listy od poczatku do konca.
     */
    void displayForward() const;

    /**
     * @brief Wyswietla zawartosc listy od konca do poczatku.
     */
    void displayBackward() const;

    /**
     * @brief Dodaje element pod wskazany indeks.
     * @param index Pozycja, na ktorej ma zostac dodany element.
     * @param value Wartosc elementu do dodania.
     */
    void insertAt(int index, int value);

    /**
     * @brief Usuwa element spod wskazanego indeksu.
     * @param index Pozycja elementu do usuniecia.
     */
    void removeAt(int index);

    /**
     * @brief Sprawdza, czy lista jest pusta.
     * @return true jesli lista nie zawiera elementow.
     */
    bool empty() const { return sz == 0; }

    /**
     * @brief Zwraca liczbe elementow w liscie.
     * @return Liczba elementow.
     */
    std::size_t size() const { return sz; }

    /**
     * @brief Klasa wewnetrzna sluzaca do iterowania po liscie do przodu.
     *
     * Pozwala na przechodzenie po elementach listy bez bezposredniego dostepu do wskaznikow.
     */
    class Iterator {
    private:
        Node* current; ///< Wskaznik do biezacego elementu
    public:
        /**
         * @brief Konstruktor iteratora.
         * @param start Wskaznik do pierwszego elementu listy.
         */
        explicit Iterator(Node* start) : current(start) {}

        /**
         * @brief Sprawdza, czy istnieje kolejny element listy.
         * @return true jesli istnieje nastepny element.
         */
        bool hasNext() const { return current != nullptr; }

        /**
         * @brief Zwraca wartosc biezacego elementu i przechodzi do nastepnego.
         * @return Wartosc aktualnego elementu.
         */
        int next() {
            int value = current->data;
            current = current->next;
            return value;
        }

        /**
         * @brief Sprawdza, czy istnieje poprzedni element listy.
         * @return true jesli istnieje poprzedni element.
         */
        bool hasPrevious() const { return current != nullptr; }

        /**
         * @brief Zwraca wartosc biezacego elementu i przechodzi do poprzedniego.
         * @return Wartosc aktualnego elementu.
         */
        int previous() {
            int value = current->data;
            current = current->prev;
            return value;
        }
    };

    /**
     * @brief Klasa wewnetrzna sluzaca do iterowania po liscie od konca.
     */
    class ReverseIterator {
    private:
        Node* current; ///< Wskaznik do biezacego elementu
    public:
        /**
         * @brief Konstruktor iteratora wstecznego.
         * @param start Wskaznik do ostatniego elementu listy.
         */
        explicit ReverseIterator(Node* start) : current(start) {}

        /**
         * @brief Sprawdza, czy istnieje poprzedni element.
         * @return true jesli istnieje element przed biezacym.
         */
        bool hasPrev() const { return current != nullptr; }

        /**
         * @brief Zwraca wartosc biezacego elementu i przechodzi do poprzedniego.
         * @return Wartosc aktualnego elementu.
         */
        int prev() {
            int v = current->data;
            current = current->prev;
            return v;
        }
    };

    /**
     * @brief Zwraca iterator ustawiony na poczatek listy.
     * @return Iterator klasy Iterator.
     */
    Iterator getIterator() const { return Iterator(head); }

    /**
     * @brief Zwraca iterator wsteczny ustawiony na koniec listy.
     * @return Obiekt klasy ReverseIterator.
     */
    ReverseIterator getReverseIterator() const { return ReverseIterator(tail); }
};
