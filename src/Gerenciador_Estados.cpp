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
    estadoAtual(1),
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
        // estados[estadoAtual]->executar();
    }

    void Gerenciador_Estados::addEstado (Estados::Estado* pEstado)
    {
        if (pEstado == nullptr) {
            exit(1);
        }
        estados[pEstado->get_id()] = pEstado;
    }

    void Gerenciador_Estados::executar()
    {
        estados[estadoAtual]->executar();
    }
}
