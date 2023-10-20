#include "Mago.h"

Mago::Mago(RenderWindow *w, IDs::IDs ids)
    : Maga(w, ids)
{
  if (!texture.loadFromFile("Jogadores/mago.png"))
  {
    std::cout << "Error" << std::endl;
  }

  body.setTexture(&texture);
}

Mago::~Mago()
{
}

void Mago::move()
{
  // Get the position of the body
  Vector2f position = body.getPosition();

  // Get the size of the window
  Vector2u windowSize = window->getSize();

  bool isTouchingLeft = false;
  bool isTouchingRight = false;
  bool isTouchingTop = false;
  bool isTouchingBottom = false;

  // Check if the body is outside the left boundary
  if (position.x < 0)
  {
    body.setPosition(0, position.y);
    isTouchingLeft = true;
  }
  else
  {
    isTouchingLeft = false;
  }

  // Check if the body is outside the right boundary
  if (position.x + body.getSize().x > windowSize.x)
  {
    body.setPosition(windowSize.x - body.getSize().x, position.y);
    isTouchingRight = true;
  }
  else
  {
    isTouchingRight = false;
  }

  // Check if the body is outside the top boundary
  if (position.y < 0)
  {
    body.setPosition(position.x, 0);
    isTouchingTop = true;
  }
  else
  {
    isTouchingTop = false;
  }

  // Check if the body is outside the bottom boundary
  if (position.y + body.getSize().y > windowSize.y)
  {
    body.setPosition(position.x, windowSize.y - body.getSize().y);
    isTouchingBottom = true;
  }
  else
  {
    isTouchingBottom = false;
  }

  if (Keyboard::isKeyPressed(Keyboard::A))
  {
    if (!isTouchingLeft)
    {
      body.move(-1, 0);
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::D))
  {
    if (!isTouchingRight)
    {
      body.move(1, 0);
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::W))
  {
    if (!isTouchingTop)
    {
      body.move(0, -1);
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::S))
  {
    if (!isTouchingBottom)
    {
      body.move(0, 1);
    }
  }
}
