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
  // voce according to the keyboard input
  if (Keyboard::isKeyPressed(Keyboard::Left))
  {
    body.move(-velocity, 0.f);
  }
  if (Keyboard::isKeyPressed(Keyboard::Right))
  {
    body.move(velocity, 0.f);
  }
  if (Keyboard::isKeyPressed(Keyboard::Up))
  {
    body.move(0.f, -velocity);
  }
  if (Keyboard::isKeyPressed(Keyboard::Down))
  {
    body.move(0.f, velocity);
  }
}