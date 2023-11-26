#pragma once

#include "Lista.h"
#include "../Entidades/Entidade.h"

namespace Listas
{   
    // Coleção
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade> LEs;
    public:
        ListaEntidades();
        ~ListaEntidades();
        void incluir(Entidades::Entidade* pE);
        const int get_tamanho() const;
        void desenhar();
        void executar();
        void remover_neutralizados();
        void limpar();
        Lista<Entidades::Entidade>::Iterador get_primeiro();
    };
}