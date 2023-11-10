#include "Entidades/Personagem/Personagem.h"

Personagem::Personagem(const Vector2f pos, const Vector2f tam, const float vel):
    body(RectangleShape(tam)), velFinal(vel, GRAVIDADE), podeAndar(false), paraEsquerda(false), relogio(), dt(0.0f)
{
    body.setPosition(pos);
    body.setFillColor(Color::Green);
}

Personagem::~Personagem()
{
}

const RectangleShape Personagem::getBody()
{
    return body;
}

void Personagem::andar(const bool paraEsquerda)
{
    podeAndar = true;
    this->paraEsquerda = paraEsquerda;
}

void Personagem::parar()
{
    podeAndar = false;
}

void Personagem::atualiza()
{
    atualizarPosicao();
}

void Personagem::atualizarPosicao()
{
    dt = relogio.getElapsedTime().asSeconds();
    float ds = velFinal.x * dt;

    if(paraEsquerda)
    {
        ds *= -1;
    }

    body.move(ds, 0.0f);
    
}
