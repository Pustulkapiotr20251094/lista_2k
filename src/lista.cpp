/**
 * @file Lista.cpp
 * @brief Implementacja metod klasy lista (lista dwukierunkowa).
 *
 * Plik zawiera implementacje wszystkich metod klasy lista, umozliwiajacych
 * dodawanie, usuwanie, wyswietlanie oraz iteracje po elementach listy dwukierunkowej.
 */

#include "lista.h"
#include <stdexcept> 
#include <iostream>

 /**
  * @brief Konstruktor domyslny klasy lista.
  *
  * Inicjalizuje pusta liste z zerowym rozmiarem i pustymi wskaznikami.
  */
lista::lista() : head(nullptr), tail(nullptr), sz(0) {}

/**
 * @brief Destruktor klasy lista.
 *
 * Usuwa wszystkie elementy listy i zwalnia pamiec.  
 */
lista::~lista() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    sz = 0;
}

/**
 * @brief Dodaje element na koniec listy.
 * @param value Wartosc elementu do dodania.
 */
void lista::pushBack(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    sz++;
}

/**
 * @brief Dodaje element na poczatek listy.
 * @param value Wartosc elementu do dodania.
 */
void lista::pushFront(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    sz++;
}

/**
 * @brief Wyswietla zawartosc listy od poczatku do konca.
 */
void lista::displayForward() const {
    Node* current = head;
    std::cout << "Zawartosc listy: ";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

/**
 * @brief Usuwa pierwszy element z listy.
 */
void lista::popFront() {
    if (!head) return; // lista pusta
    Node* temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete temp;
    sz--;
}

/**
 * @brief Usuwa ostatni element z listy.
 */
void lista::popBack() {
    if (!tail) return; // lista pusta
    Node* temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp;
    sz--;
}

/**
 * @brief Usuwa wszystkie elementy listy.
 *
 * Wywoluje metode popFront() az lista stanie sie pusta.
 */
void lista::clear() {
    while (!empty()) {
        popFront();
    }
}

/**
 * @brief Wyswietla zawartosc listy od konca do poczatku.
 */
void lista::displayBackward() const {
    Node* current = tail;
    std::cout << "Zawartosc listy (od konca): ";
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << "\n";
}

/**
 * @brief Dodaje element pod wskazany indeks.
 * @param index Pozycja, na ktorej ma zostac dodany nowy element.
 * @param value Wartosc elementu do dodania.
 * @throw std::out_of_range Jesli indeks jest poza zakresem.
 */
void lista::insertAt(int index, int value) {
    if (index < 0 || index > static_cast<int>(sz)) {
        throw std::out_of_range("Niepoprawny indeks");
    }

    if (index == 0) {
        pushFront(value);
        return;
    }
    else if (index == static_cast<int>(sz)) {
        pushBack(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* current = head;

    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;

    sz++;
}

/**
 * @brief Usuwa element spod wskazanego indeksu.
 * @param index Pozycja elementu do usuniecia.
 * @throw std::out_of_range Jesli indeks jest poza zakresem.
 */
void lista::removeAt(int index) {
    if (index < 0 || index >= static_cast<int>(sz)) {
        throw std::out_of_range("Niepoprawny indeks");
    }

    if (index == 0) {
        popFront();
        return;
    }
    else if (index == static_cast<int>(sz) - 1) {
        popBack();
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;

    sz--;
}



