#include "Mago.h"

Mago::Mago(RenderWindow *w)
    : Maga(w)
{
}

Mago::~Mago()
{
}

void Mago::move()
{
  // voce according to the keyboard input
  if (Keyboard::isKeyPressed(Keyboard::A))
  {
    body.move(-velocity, 0.f);
  }
  if (Keyboard::isKeyPressed(Keyboard::D))
  {
    body.move(velocity, 0.f);
  }
  if (Keyboard::isKeyPressed(Keyboard::W))
  {
    body.move(0.f, -velocity);
  }
  if (Keyboard::isKeyPressed(Keyboard::S))
  {
    body.move(0.f, velocity);
  }
}
