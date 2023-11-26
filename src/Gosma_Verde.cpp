#include "../Entidades/Personagens/Gosma_Verde.h"
#include "../Entidades/Personagens/Movimentacao/Gosma_movimentacao.h"

#define SKIN_GREEN_SLIME "./public/assets/Inimigos/slime-green.png"
#define ALTURA_SLIME 50.0f
#define LARGURA_SLIME 50.0f
namespace Entidades
{
    namespace Personagens
    {

        int Gosma_Verde::nivel_de_gosma_max = 3;
        Gosma_Verde::Gosma_Verde(sf::Vector2f pos, sf::Vector2f vel):
        Inimigo(pos, vel, IDs::IDs::slime_green),
        nivel_de_gosma(0.f)
        {
            corpo.setSize(sf::Vector2f(LARGURA_SLIME, ALTURA_SLIME));
            corpo.setOrigin(sf::Vector2f((LARGURA_SLIME-TAM)/2, (ALTURA_SLIME-TAM)/2));
            set_and_load_textura(SKIN_GREEN_SLIME);
            set_dano(3);
            setPontos(10);
            setMovimentacao(&Movimentacoes::Gosma_movimentacao::getInstance());
        }
        
        Gosma_Verde::~Gosma_Verde()
        {

        }

        void Gosma_Verde::executar()
        {
            mover();
            if(ataque_tempo < ataque_tempo_max){
                nivel_de_gosma = 0.f;
                ataque_tempo += 0.03;
            }
            else if(nivel_de_gosma < nivel_de_gosma_max)
                nivel_de_gosma += 0.001;

            
        }

        int Gosma_Verde::get_dano() const{
            return dano + nivel_de_gosma;
        }

        float Gosma_Verde::get_nivel_de_gosma()
        {
            return nivel_de_gosma;
        }

        void Gosma_Verde::set_nivel_de_gosma(float nivel_de_gosma)
        {
            this->nivel_de_gosma = nivel_de_gosma;
        }

        void Gosma_Verde::colidir(Entidade* outro, int side){
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
                // std::cout << "Inimigo::colidir" << "dano:" << get_dano() << "pVida:" << p->get_vida() << std::endl;
                ataque_tempo = 0.f;
                nivel_de_gosma = 0.f;
                break;
                case IDs::IDs::vazio:
                /* code */
                break;
            
            default:
                break;
            }
        }

        void Gosma_Verde::mover()
        {
            _movimentacao->mover(this);
        }

        void Gosma_Verde::salvar(std::ostringstream* entrada)
        {
            Inimigo::salvar(entrada);
        }
    }
}