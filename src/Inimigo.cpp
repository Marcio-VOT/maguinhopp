#include "../Entidades/Personagens/Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        float Inimigo::ataque_tempo_max = 2.f;

        Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f vel, IDs::IDs id):
        Personagem(pos, vel, id),
        ataque_tempo(0.f),
        dano(0)
        {
        }
        Inimigo::~Inimigo()
        {
            
        }
        void Inimigo::salvar(std::ostringstream* entrada)
        {
                Personagem::salvar(entrada);
                (*entrada) << ", \"dano\": " << dano;
        }

        void Inimigo::colidir(Entidades::Entidade* outro){
            if(outro->get_id() == IDs::IDs::jgd1){
                Entidades::Personagens::Personagem* p = static_cast<Entidades::Personagens::Personagem*>(outro);
                if(ataque_tempo >= ataque_tempo_max){
                    p->set_vida(p->get_vida() - dano);
                    ataque_tempo = 0.f;
                }
            }
        }
    }
}