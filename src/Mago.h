#pragma once
#include "Maga.h"
#include <SFML/Graphics.hpp>

class Mago : public Maga
{
private:
  /* data */
public:
  Mago(RenderWindow *w);
  ~Mago();
  void move();
};
