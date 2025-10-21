#include <iostream>
#include "lista.h"
int main()
{
	std::cout << "Projekt - lista_dwukierunkowa"<<'\n';
	std::cout << "\n";
	std::cout << "test - tworzenie obiektu \n";
	lista l;
	std::cout << "rozmiar poczatkowy : " << l.size() << "\n";
	std::cout << (l.empy() ? "lista jest pusta " : "coœ tam jest ");




	return 0;

}