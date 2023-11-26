#include "../Entidades/Personagens/Jogador.h"


#define SKIN_JOGADOR1 "./public/assets/Jogadores/Jogador1.png"
#define SKIN_JOGADOR2 "./public/assets/Jogadores/Jogador2.png"
#define SKIN_JOGADOR1_inv "./public/assets/Jogadores/Jogador1_inv.png"
#define SKIN_JOGADOR2_inv "./public/assets/Jogadores/Jogador2_inv.png"
#define ALTURA_JOGADOR 85.0f
#define LARGURA_JOGADOR 60.0f
#include <iostream>




namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f vel):
        Personagem(pos, vel, IDs::IDs::jgd1),
        pontos(0)
        {
          corpo.setSize(sf::Vector2f(LARGURA_JOGADOR, ALTURA_JOGADOR));
          corpo.setOrigin(sf::Vector2f((LARGURA_JOGADOR-TAM)/2, (ALTURA_JOGADOR-TAM)/2));
          updatePlayerId(IDs::IDs::jgd1);
        }
        Jogador::~Jogador()
        {
        }
        void Jogador::executar()
        {
            mover();
            if(ataque_tempo < ataque_tempo_max)
                ataque_tempo += 0.03;
        }
        void Jogador::updatePlayerId(IDs::IDs id){
                this->id = id;
                switch (id)
                {
                case IDs::IDs::jgd1:
                    this->setMovimentacao(&Entidades::Personagens::Movimentacoes::Jogador1_movimentacao::getInstance());
                    set_and_load_textura(SKIN_JOGADOR1, SKIN_JOGADOR1_inv);
                break;

                case IDs::IDs::jgd2:
                    this->setMovimentacao(&Entidades::Personagens::Movimentacoes::Jogador2_movimentacao::getInstance());
                    set_and_load_textura(SKIN_JOGADOR2, SKIN_JOGADOR2_inv);
                break;
                default:
                    std::cout << "Erro ao atualizar id do jogador" << std::endl;
                    exit(1);
                    break;
                }
            }
        void Jogador::mover()
        {
            _movimentacao->mover(this);
        }

        void Jogador::salvar(std::ostringstream* entrada)
        {
            Personagem::salvar(entrada);
            (*entrada) << ", \"pontos\": " << pontos << " }" << std::endl;
        }
        void Jogador::colidir(Entidade* outro, int side)
        {
            Personagem* p = nullptr;
            switch (outro->get_id())
            {
            case IDs::IDs::slime_blue:
            case IDs::IDs::pumpkin:
            if(side == 4 || side == 2){
            p = dynamic_cast<Personagem*>(outro);
            if(ataque_tempo >= ataque_tempo_max){
                // std::cout << "ataque do player para com inimigo" << posicao.x << posicao.y << p->getPosicao().x << p->getPosicao().y <<  std::endl;
                p->set_vida(0);
                ataque_tempo = 0;
            }
            }
            break;
            
            default:
                break;
            }
        
        }
    }
}