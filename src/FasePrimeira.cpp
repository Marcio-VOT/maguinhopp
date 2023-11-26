#include "../Estados/Fases/FasePrimeira.h"
#include <string>

namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira(int id, int quantidadeJogadores):
        Fase(id, quantidadeJogadores)
        {
            if(id == 1)
            caminho = ARQUIVO_CENARIO_1;
            else
            caminho = ARQUIVO_CENARIO_2;
        }
        FasePrimeira::~FasePrimeira()
        {

        }

        void FasePrimeira::inicializar()
        {
            criarCenario(caminho);
        }

        void FasePrimeira::atualizaId(int id)
        {
            if(id == 1)
            caminho = ARQUIVO_CENARIO_1;
            else
            caminho = ARQUIVO_CENARIO_2;
        }

        void FasePrimeira::atualiza()
        {
            executar();
        }

        void FasePrimeira::executar()
        {
            jogadores.executar();
            inimigos.executar();
            gerenciar_colisoes();
            removeNeutralizados();

            if(inimigos.get_tamanho() < 1 && primeira)
            {
                terminar();
                atualizaId(Estado::get_id() -1);
                setPrimeira(false);
                mudarEstado(1);
                return;
            }else if(inimigos.get_tamanho() < 1 && !primeira)
            {
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