#include "../Estados/Fases/FasePrimeira.h"
#include <string>

namespace Estados
{
    namespace Fases
    {
        FasePrimeira::FasePrimeira():
        Fase(1)
        {
            criarCenario(ARQUIVO_CENARIO_1);
        }
        FasePrimeira::~FasePrimeira()
        {

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
            jogadores.desenhar();
            inimigos.desenhar();
            obstaculos.desenhar();
        }
    }    
}