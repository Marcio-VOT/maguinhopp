#include "../Entidades/Personagens/Inimigo.h"
#include <iostream>

namespace Entidades
{
    namespace Personagens
    {
        Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f vel, IDs::IDs id):
        Personagem(pos, vel, id),
        pontos(0)
        {
        }
        Inimigo::~Inimigo()
        {
            
        }
        int Inimigo::getPontos()
        {
            return pontos;
        }

        void Inimigo::setPontos(int pontos)
        {
            this->pontos = pontos;
        }
        
        void Inimigo::salvar(std::ostringstream* entrada)
        {
                Personagem::salvar(entrada);
                (*entrada) << ", \"dano\": " << dano;
        }
    }
}