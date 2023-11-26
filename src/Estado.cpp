#include "../Estados/Estado.h"
#include <iostream>

namespace Estados
{
    Estado::Estado(int i):
    pGE(Gerenciadores::Gerenciador_Estados::get_instancia()),
    id(i)
    {
        pGE->addEstado(this);
    }
    Estado::~Estado()
    {
        pGE = nullptr;
    }
    int Estado::get_id() const
    {
        return id;
    }

    void Estado::mudarEstado(int i)
    {
        pGE->setEstadoAtual(i);
        std::cout << "Estado mudado para " << i << std::endl;
    }
}