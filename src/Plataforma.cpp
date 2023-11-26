#include "../Entidades/Obstaculos/Plataforma.h"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(sf::Vector2f pos, char tipo):
        Obstaculo(pos, false),
        tamanho_(tamanho_plataforma::p)
        {
          corpo.setFillColor(sf::Color(165, 42, 42, 255));
          corpo.setOutlineThickness(1.f);
          corpo.setOutlineColor(sf::Color::Black);
          set_id(IDs::IDs::plataforma);

          sf::Vector2f tam = corpo.getSize();
          switch (tipo)
          {
          case 'p':
            corpo.setSize(sf::Vector2f(150.f, corpo.getSize().y));
            tamanho_ = tamanho_plataforma::p;
            break;

          case 'm':
            corpo.setSize(sf::Vector2f(200.f, corpo.getSize().y));
            tamanho_ = tamanho_plataforma::m;
            break;

          case 'g':
            corpo.setSize(sf::Vector2f(300.f, corpo.getSize().y));
            tamanho_ = tamanho_plataforma::g;
            break;
          default:
            break;
          }
          corpo.getOrigin();
          corpo.setOrigin((corpo.getSize().x - tam.x)/2 , 0);
        }
        Plataforma::~Plataforma()
        {

        }
        void Plataforma::executar()
        {
        }
    }
}