

#include <iostream>
#include "lista.h"


int main()

{
   

    lista lista;
    lista.pushBack(10);
    lista.pushBack(20);
    lista.pushBack(30);
    lista.pushFront(5);
    lista.pushFront(1);
    lista.displayForward();

    std::cout << "\nWyswietlanie od konca:\n";
    lista.displayBackward();

    std::cout << "\nUsuwanie pierwszego i ostatniego elementu...\n";
    lista.popFront();
    lista.popBack();
    lista.displayForward();

    std::cout << "\nCzyszczenie listy...\n";
    lista.clear();
    lista.displayForward();
    std::cout << "Rozmiar po czyszczeniu: " << lista.size() << "\n";

    std::cout << (lista.empty() ? "Lista pusta\n" : "Lista niepusta\n");



	return 0;

}