#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/Gerenciador_Grafico.h"

class Ente
{
protected:
  int id;
  static Gerenciadores::Gerenciador_Grafico* pGG;
  sf::RectangleShape corpo;
  sf::Texture textura;

public:
  Ente(sf::Vector2f tam = sf::Vector2f(60.f, 85.f));
  ~Ente();
  virtual void executar() = 0;
  void desenhar();
  const sf::RectangleShape* get_corpo() const;
  const sf::Texture* get_textura() const;
  const void set_textura();
  const void load_textura(const std::string& caminho);
  const void set_and_load_textura(const std::string& caminho);

};