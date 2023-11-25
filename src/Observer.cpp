#include "../Controladores/Observer.h"
#include <iostream>

namespace Controladores {

    Observer::Observer() {
        pGE = Gerenciadores::Entrada::getInstancia();
        pGE->Anexar(this);
    }

    Observer::~Observer() {
        pGE->Desanexar(this);
    }

} // namespace Controladores