#include "../Estados/Fases/FasePrimeira.h"
#include <string>

namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira(int id):
        Fase(id)
        {
            if(id == 1)
            criarCenario(ARQUIVO_CENARIO_1);
            else
            criarCenario(ARQUIVO_CENARIO_2);
        }
        FasePrimeira::~FasePrimeira()
        {

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
            if(jogadores.get_tamanho() == 0)
            {
                // pEstados->trocarEstado(new Estados::Fases::FasePrimeira());
            }
            else
            pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
        }

        void FasePrimeira::resetaEstado()
        {
            if(fimDeJogo){
            jogadores.limpar();
            inimigos.limpar();
            obstaculos.limpar();
            criarJogadores();
            criarInimigos();
            criarCenario(ARQUIVO_CENARIO_1);
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