#include "../Gerenciadores/Gerenciador_Estados.h"
#include "../Estados/Estado.h"

namespace Gerenciadores
{
    Gerenciador_Estados* Gerenciador_Estados::instancia = nullptr;

    Gerenciador_Estados* Gerenciador_Estados::get_instancia()
    {
        if (!instancia)
            instancia = new Gerenciador_Estados;
        
        return instancia;
    }

    Gerenciador_Estados::Gerenciador_Estados():
    estadoAtual(0),
    ultimoEstado(0)
    {
    }

    Gerenciador_Estados::~Gerenciador_Estados()
    {
        for (int i = 0; i < estados.size(); i++)
            delete estados[i];  
    }

    void Gerenciador_Estados::setEstadoAtual(int i)
    {
        ultimoEstado = estadoAtual;
        estadoAtual = i;
        estados[estadoAtual]->resetaEstado();
    }

    void Gerenciador_Estados::addEstado (Estados::Estado* pEstado)
    {
        if (pEstado == nullptr) {
            exit(1);
        }
        estados[pEstado->get_id()] = pEstado;
    }

    void Gerenciador_Estados::executaEstadoAtual()
    {
        estados[estadoAtual]->atualiza();
    }

    void Gerenciador_Estados::exibeEstadoAtual()
    {
        estados[estadoAtual]->desenha();
    }

    void Gerenciador_Estados::executar()
    {
        executaEstadoAtual();
        exibeEstadoAtual();
    }
}
