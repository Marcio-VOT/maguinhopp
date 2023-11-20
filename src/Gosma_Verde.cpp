#include "../Entidades/Personagens/Gosma_Verde.h"
#include "../Entidades/Personagens/Movimentacao/Gosma_movimentacao.h"

#define SKIN_BLUE_SLIME "./public/assets/Inimigos/slime-blue.png"
#define ALTURA_SLIME 50.0f
#define LARGURA_SLIME 50.0f
namespace Entidades
{
    namespace Personagens
    {


        Gosma_Verde::Gosma_Verde(sf::Vector2f pos, sf::Vector2f vel):
        Inimigo(pos, vel, IDs::IDs::slime_blue)
        {
            corpo.setSize(sf::Vector2f(LARGURA_SLIME, ALTURA_SLIME));
            corpo.setOrigin(sf::Vector2f((LARGURA_SLIME-TAM)/2, (ALTURA_SLIME-TAM)/2));
            set_and_load_textura(SKIN_BLUE_SLIME);
            set_dano(50);
            setMovimentacao(&Movimentacoes::Gosma_movimentacao::getInstance());
        }
        
        Gosma_Verde::~Gosma_Verde()
        {

        }
        void Gosma_Verde::executar()
        {
            mover();
            if(ataque_tempo < ataque_tempo_max)
                ataque_tempo += 0.03;
            
        }

        void Gosma_Verde::mover()
        {
            _movimentacao->mover(this);
        }

        void Gosma_Verde::salvar(std::ostringstream* entrada)
        {
            Inimigo::salvar(entrada);
            // (*entrada) << " \"m\" :" << m << std::endl;
        }
    }
}