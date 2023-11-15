#include "../Entidades/Personagens/Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f vel, IDs::IDs id, int vel_max):
        Entidade(pos, id, vel_max),
        pontos_de_vida(50),
        ataque_tempo(0.f),
        dano(0),
        ataque_tempo_max(2.f),
        _movimentacao(nullptr)
        {
        }
        Personagem::~Personagem()
        {
            pontos_de_vida = 0;
        }
    }
}