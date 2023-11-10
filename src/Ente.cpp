#include "../Ente.h"
#include <iostream>

Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());


Ente::Ente(sf::Vector2f tam, IDs::IDs id):
id(id),
corpo(tam)
{
}

Ente::~Ente()
{

}

void Ente::desenhar()
{
  pGG->desenharEnte(this);
}

const sf::RectangleShape* Ente::get_corpo() const
{
  return &corpo;
}

const sf::Texture* Ente::get_textura() const
{
  return &textura;
}

const void Ente::set_textura()
{
  corpo.setTexture(&this->textura, true);
}

const void Ente::load_textura(const std::string& caminho)
{
  pGG->carregarTextura(&textura, caminho);
}

const void Ente::set_and_load_textura(const std::string& caminho)
{
  load_textura(caminho);
  set_textura();
}