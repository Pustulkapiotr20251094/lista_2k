#include <iostream>
#include "lista.h"


int main()
{
	lista lista;

	std::cout << "Projekt - lista_dwukierunkowa"<<'\n';
	std::cout << "\n";
	
	std::cout << "dodawanie leementu na koniec listy \n";
	lista.pushBack(4);
	lista.pushBack(6);
	lista.displayForward();





	std::cout << "\n Dodawnia elementu na pocz¹tek listy  \n";
	lista.pushFront(1);
	lista.pushFront(2);
	lista.pushFront(3);
	lista.displayForward();


	std::cout << "\nRozmiar listy: " << lista.size() << "\n";





	return 0;

}