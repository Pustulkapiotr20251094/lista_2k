#pragma once
#include "lista.h"

/**
 * @brief Klasa fabryki list.
 */
class Factory {
public:
    /**
     * @brief Tworzy nowy obiekt listy dwukierunkowej.
     * @return Wskaünik na nowy obiekt Lista.
     */
    static lista* createLista() {
        return new lista();
    }
};