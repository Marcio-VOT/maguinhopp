#include "../Estados/Fases/FasePrimeira.h"
#include <string>

namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira(int id, int quantidadeJogadores):
        Fase(id, quantidadeJogadores),
        caminho(ARQUIVO_CENARIO_1),
        idMapa(id)
        {
            if(id == 1){
                caminho = ARQUIVO_CENARIO_1;
                idMapa = 1;
            }
            else{
                caminho = ARQUIVO_CENARIO_2;
                idMapa = 2;
            }
        }
        FasePrimeira::~FasePrimeira()
        {

        }

        void FasePrimeira::inicializar()
        {
            criarCenario(caminho);
        }

        void FasePrimeira::atualizaMapaId(int id)
        {
            if(id == 1){
                caminho = ARQUIVO_CENARIO_1;
                idMapa = 1;

            }
            else{
                caminho = ARQUIVO_CENARIO_2;
                idMapa = 2;
            }
        }

        void FasePrimeira::atualiza()
        {
            executar();
        }

        void FasePrimeira::executar()
        {
            jogadores.executar();
            inimigos.executar();
            obstaculos.executar();
            gerenciar_colisoes();
            removeNeutralizados();

            if(inimigos.get_tamanho() < 1 && primeira && jogadores.get_tamanho() > 0)
            {
                terminar();

                if(idMapa == 1)
                atualizaMapaId(2);
                else
                atualizaMapaId();

                setPrimeira(false);
                mudarEstado(1);
                return;
            }else if(inimigos.get_tamanho() < 1 && !primeira  && jogadores.get_tamanho() > 0)
            {
                //iterator para o jogador
                Listas::Lista<Entidades::Entidade>::Iterador it = jogadores.get_primeiro();
                Entidades::Personagens::Jogador* jogador1 = dynamic_cast<Entidades::Personagens::Jogador*>(*it);
                pontosFase += jogador1->getPontos();
                if(jogadores.get_tamanho() > 1){
                it++;
                Entidades::Personagens::Jogador* jogador2 = dynamic_cast<Entidades::Personagens::Jogador*>(*it);
                pontosFase += jogador2->getPontos();
                }

                terminar();
                mudarEstado(0);
                return;
            }
            
            if(jogadores.get_tamanho() == 0)
            {
                terminar();
                mudarEstado(0);
            }
            else
            pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
        }

        void FasePrimeira::resetaEstado()
        {
            if(fimDeJogo){
            inicializar();
            fimDeJogo = false;
            }
            pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
        }

        void FasePrimeira::desenha()
        {
            jogadores.desenhar();
            inimigos.desenhar();
            obstaculos.desenhar();
        }
    }    
}