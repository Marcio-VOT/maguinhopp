#include "../Entidades/Personagens/Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        int Personagem::max_vel = 5;
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f vel, IDs::IDs id):
        Entidade(pos, id),
        pontos_de_vida(50)
        {

        }
        Personagem::~Personagem()
        {
            pontos_de_vida = 0;
        }
    }
}