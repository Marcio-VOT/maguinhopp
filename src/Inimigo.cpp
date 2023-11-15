#include "../Entidades/Personagens/Inimigo.h"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f vel, IDs::IDs id):
        Personagem(pos, vel, id)
        {
        }
        Inimigo::~Inimigo()
        {
            
        }
        void Inimigo::colidir(Entidade* outro, int side){
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
                p->set_vida(p->get_vida() - dano);
                ataque_tempo = 0.f;
                std::cout << "Inimigo::colidir" << "dano:" << dano << "pVida:" << p->get_vida() << std::endl;
                break;
                case IDs::IDs::vazio:
                /* code */
                break;
            
            default:
                break;
            }
        }
        void Inimigo::salvar(std::ostringstream* entrada)
        {
                Personagem::salvar(entrada);
                (*entrada) << ", \"dano\": " << dano;
        }
    }
}