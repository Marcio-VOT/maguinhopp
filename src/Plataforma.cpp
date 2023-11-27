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
          set_id(IDs::IDs::plataforma);

          corpo.setPosition(sf::Vector2f(corpo.getPosition().x, corpo.getPosition().y + corpo.getSize().y/4));
          sf::Vector2f tam = corpo.getSize();
          switch (tipo)
          {
          case 'p':
            corpo.setSize(sf::Vector2f(200.f, 20));
            tamanho_ = tamanho_plataforma::p;
            break;

          case 'm':
            corpo.setSize(sf::Vector2f(300.f, 20));
            tamanho_ = tamanho_plataforma::m;
            break;

          case 'g':
            corpo.setSize(sf::Vector2f(350.f, 20));
            tamanho_ = tamanho_plataforma::g;
            break;
          default:
            break;
          }
          corpo.getOrigin();
          corpo.setOrigin((corpo.getSize().x - tam.x)/2 , (corpo.getSize().y - tam.y)/2);
        }
        Plataforma::~Plataforma()
        {

        }
        void Plataforma::executar()
        {
        }
    }
}