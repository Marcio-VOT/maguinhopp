#include "../Entidades/Entidade.h"

#include <iostream>

namespace Entidades
{
    Entidade::Entidade(sf::Vector2f pos, IDs::IDs id):
    Ente(sf::Vector2f(TAM, TAM), id),
    posicao(pos),
    nochao(false),
    velocidade(sf::Vector2f(0.f, 0.f))
    {
        corpo.setPosition(posicao);
    }
    Entidade::~Entidade()
    {
        
    }
    void Entidade::colidir(Entidade* outro)
    {
    }
    void Entidade::setPosicao(sf::Vector2f p)
    {
        corpo.setPosition(p);
    }
    void Entidade::setVelocidade(sf::Vector2f v)
    {
        velocidade = v;
    }
}