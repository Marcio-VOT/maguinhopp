#include "../Entidades/Personagens/Inimigo.h"

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
    }
}