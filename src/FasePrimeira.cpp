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
            Listas::Lista<Entidades::Entidade>::Iterador aux = jogadores.get_primeiro();

            if(aux != nullptr)
                std::cout << "Jogador posição 1" << static_cast<int>((*aux)->get_id()) << std::endl;
            std::cout << "aq n deu seg f"<< std::endl;
            aux++;

            if(aux != nullptr){
                std::cout << "aq n deu seg f aux"<< std::endl;
                std::cout << "Jogador posição 2" << static_cast<int>((*aux)->get_id()) << std::endl;
            }

            pGG->centralizarCamera((*(jogadores.get_primeiro()))->getPosicao());
            std::cout << "Jogador posição 1 dps" << static_cast<int>((*aux)->get_id()) << std::endl;
            jogadores.desenhar();
            inimigos.desenhar();
            obstaculos.desenhar();
        }
    }    
}