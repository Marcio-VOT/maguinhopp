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
        void Inimigo::colidir(Entidades::Entidade* outro){
            if(outro == nullptr || ataque_tempo < ataque_tempo_max)
                return;
            
            if(outro->get_id() == IDs::IDs::jgd1 || outro->get_id() == IDs::IDs::jgd2){
                Entidades::Personagens::Personagem* p = dynamic_cast<Entidades::Personagens::Personagem*>(outro);
                p->set_vida(p->get_vida() - dano);
                ataque_tempo = 0.f;
                std::cout << "Inimigo::colidir" << "dano:" << dano << "pVida:" << p->get_vida() << std::endl;
            }
        }
        void Inimigo::salvar(std::ostringstream* entrada)
        {
                Personagem::salvar(entrada);
                (*entrada) << ", \"dano\": " << dano;
        }
    }
}