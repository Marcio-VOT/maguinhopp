#pragma once

#include "Gerenciadores/Gerenciador_Entrada.h"

namespace Controladores {

    class Observer {
    private:
        Gerenciadores::Entrada* pGE;

    public:
        Observer();
        virtual ~Observer();
    
        virtual void notifica(std::string key) = 0;
        
    };

}