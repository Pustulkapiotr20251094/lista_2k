
#include <iostream>
#include "lista.h"
#include "Factory.h"

int main() {
    // 🔹 Test podstawowych metod
    lista lista;
    lista.pushBack(10);
    lista.pushBack(20);
    lista.pushBack(30);

    std::cout << "Zawartość listy: ";
    lista.displayForward();

    // 🔹 Test działania iteratora
    std::cout << "\nIteracja po liście:\n";
    auto it = lista.getIterator();
    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }
    std::cout << "\n";

    return 0;
}
