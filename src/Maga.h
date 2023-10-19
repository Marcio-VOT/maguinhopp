#pragma
#include "Ente.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
class Maga : public Ente
{
private:
  RectangleShape body;
  Vector2f size;
  Vector2f position;
  float velocity;
  Texture texture;
  RenderWindow *window;

public:
  Maga(RenderWindow *w);
  ~Maga();
  const string salvar();
  void move();
  void desenhar();
};
