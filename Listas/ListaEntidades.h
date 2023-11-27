/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DOS TUTORES  "Os petequeiros Jean e Murilo" - https://github.com/Nixxye -  https://utfpr.curitiba.br/peteco/
    Canal: https://www.youtube.com/@PETECOUTFPR
    CÓDIGO ORIGINAL: https://github.com/Nixxye/peteco-tegprog
*/
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