#include "../Ente.h"

Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());


Ente::Ente(sf::Vector2f tam):
id(0),
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