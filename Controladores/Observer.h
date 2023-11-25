#pragma once

#include "../Gerenciadores/Gerenciador_Entrada.h"
#include <iostream>

namespace Controladores {

    class Observer {
    private:
        Gerenciadores::Entrada* pGE;
    public:
        Observer();
        virtual ~Observer();
        virtual void notifica(sf::String key) = 0;
    };

}