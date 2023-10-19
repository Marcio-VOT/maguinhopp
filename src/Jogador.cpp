#include "../../Jogador.h"

Jogador::Jogador(const Vector2f pos, const Vector2f tam)
{
    body.setPosition(pos);
    body.setFillColor(Color::Green);
    inicializa();
}

Jogador::Jogador(const RectangleShape body): 
    body(body)
{
    inicializa();
}
Jogador::Jogador():
    body()
{
    inicializa();
}

void Jogador::inicializa()
{
    vel = Vector2f(0.1f, 0.1f);
}

Jogador::~Jogador()
{
}   

const RectangleShape Jogador::getBody()
{
    return body;
}

void Jogador::move()
{
    if(Keyboard::isKeyPressed(Keyboard::Key::A))
    {
        body.move(-vel.x, 0.f);
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::D))
    {
        body.move(vel.x, 0.f);
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::W))
    {
        body.move(0.f, -vel.y);
    }

    if (Keyboard::isKeyPressed(Keyboard::Key::S))
    {
        body.move(0.f, vel.y);
    }
     
}