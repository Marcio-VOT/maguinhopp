#include "../Entidades/Personagens/Gosma_Nuclear.h"
#include "../Entidades/Personagens/Movimentacao/Gosma_movimentacao.h"

#define SKIN_RED_SLIME "./public/assets/Inimigos/slime-red.png"
#define ALTURA_SLIME 50.0f
#define LARGURA_SLIME 50.0f
namespace Entidades
{
    namespace Personagens
    {

        int Gosma_Nuclear::temperatura_fusao = 30;
        Gosma_Nuclear::Gosma_Nuclear(sf::Vector2f pos, sf::Vector2f vel):
        Inimigo(pos, vel, IDs::IDs::slime_red),
        temperatura_nucleo(0.f)
        {
            corpo.setSize(sf::Vector2f(LARGURA_SLIME, ALTURA_SLIME));
            corpo.setOrigin(sf::Vector2f((LARGURA_SLIME-TAM)/2, (ALTURA_SLIME-TAM)/2));
            set_and_load_textura(SKIN_RED_SLIME);
            set_dano(3);
            setPontos(15);
            setMovimentacao(&Movimentacoes::Gosma_movimentacao::getInstance());
        }
        
        Gosma_Nuclear::~Gosma_Nuclear()
        {

        }

        void Gosma_Nuclear::executar()
        {
            mover();
            if(ataque_tempo < ataque_tempo_max){
                ataque_tempo += 0.03;
            }

            if(temperatura_nucleo < temperatura_fusao){
                temperatura_nucleo += 0.001;
            }
        }

        int Gosma_Nuclear::get_dano() const{
          if( temperatura_nucleo >= temperatura_fusao){
            return dano + 8;
          }else
            return dano;
        }


        void Gosma_Nuclear::colidir(Entidade* outro, int side){
            if(outro == nullptr || ataque_tempo < ataque_tempo_max)
                return;
            
            Personagem* p = nullptr;
            
            switch (outro->get_id())
            {
            case IDs::IDs::jgd1:
            case IDs::IDs::jgd2:
                p = dynamic_cast<Entidades::Personagens::Personagem*>(outro);
                if(p == nullptr)
                    return;
                p->setDanoRecebido(get_dano());
                ataque_tempo = 0.f;
                break;            
            default:
                break;
            }
        }

        void Gosma_Nuclear::mover()
        {
            _movimentacao->mover(this);
        }

        void Gosma_Nuclear::salvar(std::ostringstream* entrada)
        {
            Inimigo::salvar(entrada);
        }
    }
}