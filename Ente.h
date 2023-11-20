#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciadores/Gerenciador_Grafico.h"
#include <sstream>
#include "IDs.h"

class Ente
{
protected:
  IDs::IDs id;
  static int total;
  int numeroTotal;
  static Gerenciadores::Gerenciador_Grafico* pGG;
  sf::RectangleShape corpo;
  sf::Texture textura;
  sf::Texture invTextura;

public:
  Ente(sf::Vector2f tam = sf::Vector2f(60.f, 85.f), IDs::IDs id = IDs::IDs::vazio);
  ~Ente();
  virtual void executar() = 0;
  void desenhar();
  IDs::IDs get_id() const { return id; };
  void set_id(IDs::IDs id) { this->id = id; };
  const sf::RectangleShape* get_corpo() const;
  const sf::Texture* get_textura() const;
  const void set_textura();
  const void set_inv_textura();
  const void load_textura(const std::string& caminho );
  const void load_inv_textura(const std::string& caminho );
  const void set_and_load_textura(const std::string& caminho, const std::string& invCaminho = "");
  virtual void salvar(std::ostringstream* entrada) {
    (*entrada) << "{ \"id\":" << std::to_string(static_cast<int>(id));
  }
  virtual bool neutralizado() const { return false; };
  const bool operator==(const Ente* ente) const { return this->numeroTotal == ente->numeroTotal; };
};
