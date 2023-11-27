#include "../Controladores/Observer.h"
#include <iostream>

namespace Controladores {

    Observer::Observer() {
        pGE = Gerenciadores::Entrada::getInstancia();
        pGE->Anexar(this);
    }

    Observer::Observer(Gerenciadores::Entrada* pGE): pGE(pGE) {
        if(pGE != nullptr)
            pGE->Anexar(this);
        else {
            std::cout << "Erro: Gerenciador de Entrada nulo" << std::endl;
            exit(1);
        }

    }

    Observer::~Observer() {
        pGE->Desanexar(this);
    }

} // namespace Controladores