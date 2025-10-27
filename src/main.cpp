/**
 * @file main.cpp
 * @brief Program testujacy dzialanie listy dwukierunkowej.
 *
 * Plik zawiera funkcje main(), ktora demonstruje dzialanie wszystkich metod
 * klasy lista. Testuje dodawanie, usuwanie, wyswietlanie oraz iterowanie po liscie.
 */

#include <iostream>
#include "lista.h"
#include "Factory.h"

 /**
  * @brief Funkcja glowna programu testujacego.
  *
  * Funkcja main() prezentuje wszystkie operacje dostepne w klasie lista:
  * dodawanie elementow (na poczatku, koncu i w srodku listy),
  * usuwanie elementow, iteracje w przod i w tyl oraz czyszczenie calej listy.
  *
  * @return Kod zakonczenia programu (0 - sukces).
  */
int main() {
    std::cout << "=== TEST LISTY DWUKIERUNKOWEJ ===\n\n";

    //  Tworzenie listy przez fabryke
    lista* lista = Factory::createLista();

    // --- Dodawanie elementow ---
    std::cout << "Dodawanie elementow na koniec:\n";
    lista->pushBack(10);
    lista->pushBack(20);
    lista->pushBack(30);
    lista->displayForward();

    std::cout << "\nDodawanie elementow na poczatek:\n";
    lista->pushFront(5);
    lista->pushFront(1);
    lista->displayForward();

    std::cout << "\nDodawanie elementu pod indeks 2 (wartosc 15):\n";
    lista->insertAt(2, 15);
    lista->displayForward();

    // --- Wyswietlanie listy ---
    std::cout << "\nWyswietlanie od konca:\n";
    lista->displayBackward();

    // --- Usuwanie elementow ---
    std::cout << "\nUsuwanie pierwszego elementu:\n";
    lista->popFront();
    lista->displayForward();

    std::cout << "\nUsuwanie ostatniego elementu:\n";
    lista->popBack();
    lista->displayForward();

    std::cout << "\nUsuwanie elementu spod indeksu 1:\n";
    lista->removeAt(1);
    lista->displayForward();

    // --- Iterator przod ---
    std::cout << "\nIteracja po liscie (do przodu):\n";
    auto it = lista->getIterator();
    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }
    std::cout << "\n";

    // --- Iterator wstecz ---
    std::cout << "\nIteracja po liscie (od konca):\n";
    auto rit = lista->getReverseIterator();
    while (rit.hasPrev()) {
        std::cout << rit.prev() << " ";
    }
    std::cout << "\n";

    // --- Test rozmiaru i pustej listy ---
    std::cout << "\nAktualny rozmiar listy: " << lista->size() << "\n";
    std::cout << (lista->empty() ? "Lista pusta" : "Lista zawiera elementy") << "\n";

    // --- Czyszczenie ---
    std::cout << "\nCzyszczenie listy...\n";
    lista->clear();
    lista->displayForward();
    std::cout << "Rozmiar po czyszczeniu: " << lista->size() << "\n";
    std::cout << (lista->empty() ? "Lista pusta" : "Lista zawiera elementy") << "\n";

    delete lista; // zwolnienie pamieci z fabryki

    std::cout << "\n=== KONIEC TESTU ===\n";  
    return 0;
}
