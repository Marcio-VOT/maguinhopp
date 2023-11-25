#pragma once

#include "Observer.h"
#include <string.h>

namespace Controladores {

    class Controlador_Entrada_Texto: public Observer {
    private:
    std::string texto;

    public:
        Controlador_Entrada_Texto();
        ~Controlador_Entrada_Texto();
        void notifica(sf::String key);
        std::string getTexto() const;
        void resetTexto();
    };

}