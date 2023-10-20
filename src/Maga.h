#pragma once
#include "Ente.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
class Maga : public Ente
{
protected:
  RectangleShape body;
  Vector2f size;
  Vector2f position;
  float velocity;
  Texture texture;
  RenderWindow *window;

public:
  Maga(RenderWindow *w, IDs::IDs ids);
  ~Maga();
  const string salvar();
  virtual void move();
  void desenhar();
};
