#include "Maga.h"

Maga::Maga(RenderWindow *w)
    : Ente(IDs::IDs::jogador1),
      size(50.f, 80.f),
      position(1.f, 10.f),
      velocity(1.000),
      window(w)
{
  body.setSize(size);
  body.setPosition(position);
  if (!texture.loadFromFile("Jogadores/Jogador1.png"))
  {
    std::cout << "Error" << std::endl;
  }

  body.setTexture(&texture);
}

Maga::~Maga()
{
}

void Maga::desenhar()
{
  window->draw(body);
}

const string Maga::salvar()
{
  string linha = Ente::salvarEnte();
  linha += to_string(size.x) + ' ' + to_string(size.y) + ' ' + to_string(body.getPosition().x) + ' ' + to_string(body.getPosition().y) + ' ' + to_string(velocity);
  return linha;
}

void Maga::move()
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

  if (Keyboard::isKeyPressed(Keyboard::Left))
  {
    if (!isTouchingLeft)
    {
      body.move(-1, 0);
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::Right))
  {
    if (!isTouchingRight)
    {
      body.move(1, 0);
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::Up))
  {
    if (!isTouchingTop)
    {
      body.move(0, -1);
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::Down))
  {
    if (!isTouchingBottom)
    {
      body.move(0, 1);
    }
  }
}