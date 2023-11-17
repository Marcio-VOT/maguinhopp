#pragma once

#include "Gerenciadores/Gerenciador_Entrada.h"

namespace Controladores {

    class Observer {
    private:
        Gerenciadores::Entrada* pGE;

    public:
        Observer();
        virtual ~Observer();
    
        virtual void notificaPressionado(std::string key) = 0;
        virtual void notificaSolto(std::string key) = 0;
    };

}