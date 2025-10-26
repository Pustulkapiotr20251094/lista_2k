#pragma once
#include "lista.h"

/**
 * @file ListaFactory.h
 * @brief Implementacja wzorca projektowego Factory dla klasy lista.
 *
 * Plik zawiera definicje klasy Factory, ktora odpowiada za tworzenie
 * nowych obiektow klasy lista. Pozwala to na oddzielenie logiki tworzenia
 * obiektow od ich uzywania w programie.
 */

 /**
  * @brief Klasa fabryki list.
  *
  * Klasa realizuje wzorzec projektowy "Factory" (Fabryka) i umozliwia
  * tworzenie nowych obiektow klasy lista.
  * Dzieki temu kod tworzacy obiekty jest odseparowany od kodu je wykorzystujacego.
  */
class Factory {
public:
    /**
     * @brief Tworzy nowy obiekt listy dwukierunkowej.
     *
     * Metoda alokuje pamiec dla nowej instancji klasy lista
     * i zwraca wskaznik do niej.
     *
     * @return Wskaznik na nowy obiekt klasy lista.
     */
    static lista* createLista() {
        return new lista();
    }
};
