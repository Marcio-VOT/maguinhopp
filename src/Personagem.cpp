#include "Entidades/Personagem/Personagem.h"

Personagem::Personagem(const Vector2f pos, const Vector2f tam):
    body(RectangleShape(tam))
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

void Personagem::move()
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

