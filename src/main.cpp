#include <iostream>
#include "lista.h"
#include "Factory.h"

int main() {
    std::cout << "=== TEST LISTY DWUKIERUNKOWEJ ===\n\n";

    // 🏭 Tworzenie listy przez fabrykę
    lista* lista = Factory::createLista();

    // --- Dodawanie elementów ---
    std::cout << "Dodawanie elementów na koniec:\n";
    lista->pushBack(10);
    lista->pushBack(20);
    lista->pushBack(30);
    lista->displayForward();

    std::cout << "\nDodawanie elementów na początek:\n";
    lista->pushFront(5);
    lista->pushFront(1);
    lista->displayForward();

    std::cout << "\nDodawanie elementu pod indeks 2 (wartość 15):\n";
    lista->insertAt(2, 15);
    lista->displayForward();

    // --- Wyświetlanie listy ---
    std::cout << "\nWyświetlanie od końca:\n";
    lista->displayBackward();

    // --- Usuwanie elementów ---
    std::cout << "\nUsuwanie pierwszego elementu:\n";
    lista->popFront();
    lista->displayForward();

    std::cout << "\nUsuwanie ostatniego elementu:\n";
    lista->popBack();
    lista->displayForward();

    std::cout << "\nUsuwanie elementu spod indeksu 1:\n";
    lista->removeAt(1);
    lista->displayForward();

    // --- Iterator przód ---
    std::cout << "\nIteracja po liście (do przodu):\n";
    auto it = lista->getIterator();
    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }
    std::cout << "\n";

    // --- Iterator wstecz ---
    std::cout << "\nIteracja po liście (od końca):\n";
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

    delete lista; // zwolnienie pamięci z fabryki

    std::cout << "\n=== KONIEC TESTU ===\n";
    return 0;
}
