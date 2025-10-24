
#include <iostream>
#include "lista.h"
#include "Factory.h"

int main() {
    std::cout << "\nTest insertAt i removeAt:\n";

    lista lista;
    lista.pushBack(10);
    lista.pushBack(20);
    lista.pushBack(30);
    lista.displayForward();

    std::cout << "Dodaję 15 pod indeks 1...\n";
    lista.insertAt(1, 15);
    lista.displayForward();

    std::cout << "Usuwam element pod indeksem 2...\n";
    lista.removeAt(2);
    lista.displayForward();

    return 0;
}
