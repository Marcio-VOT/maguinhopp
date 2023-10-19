#pragma once
#include "IDs.h"
#include <SFML/Graphics.hpp>

class Ente
{
protected:
  IDs::IDs id;
  const std::string salvarEnte();

public:
  Ente(const IDs::IDs ID);
  ~Ente();
  const IDs::IDs getID() const;
  virtual void desenhar() = 0;
};
