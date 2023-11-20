#pragma once

#include "../Listas/ListaEntidades.h"
#include "../Listas/Lista.h"
#include "../Entidades/Entidade.h"

namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        enum TipoColisao {
        Nenhuma = 0,
        Esquerda = 1,
        Cima = 2,
        Direita = 3,
        Baixo = 4
        };

    private:
        Listas::ListaEntidades *obstaculos;
        Listas::ListaEntidades *jogadores;
        Listas::ListaEntidades *inimigos;

    public:
        Gerenciador_Colisoes();
        ~Gerenciador_Colisoes();

        void set_obstaculos(Listas::ListaEntidades *o) { if (o) { obstaculos = o; }}
        void set_jogadores(Listas::ListaEntidades *j) { if (j) { jogadores = j; }}
        void set_inimigos(Listas::ListaEntidades *i) { if (i) { inimigos = i; }}
        void colidiu_janela(Entidades::Entidade* jgd1, Entidades::Entidade* jgd2);
        void colisao_simples();
        void colidir_entidade_movel_com_entidade_imovel(Entidades::Entidade* entidadeMovel, Entidades::Entidade* entidadeImovel, TipoColisao tipoColisao);
        void colidir_entidade_movel_com_entidade_movel(Entidades::Entidade* entidadeMovel1, Entidades::Entidade* entidadeMovel2, TipoColisao tipoColisao);
        TipoColisao colidiu(Entidades::Entidade* e1, Entidades::Entidade* e2);

    };
}