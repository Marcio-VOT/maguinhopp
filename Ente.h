#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/Gerenciador_Grafico.h"
#include <sstream>
#include "IDs.h"

class Ente
{
protected:
  IDs::IDs id;
  static Gerenciadores::Gerenciador_Grafico* pGG;
  sf::RectangleShape corpo;
  sf::Texture textura;

public:
  Ente(sf::Vector2f tam = sf::Vector2f(60.f, 85.f), IDs::IDs id = IDs::IDs::vazio);
  ~Ente();
  virtual void executar() = 0;
  void desenhar();
  IDs::IDs get_id() const { return id; };
  const sf::RectangleShape* get_corpo() const;
  const sf::Texture* get_textura() const;
  const void set_textura();
  const void load_textura(const std::string& caminho);
  const void set_and_load_textura(const std::string& caminho);
  virtual void salvar(std::ostringstream* entrada) {
    (*entrada) << "{ \"id\":" << std::to_string(static_cast<int>(id));
  }

};
