#include "../Entidades/Obstaculos/Neutralizador.h"
namespace Entidades
{
    namespace Obstaculos
    {
        Neutralizador::Neutralizador(sf::Vector2f pos, bool ativo): Obstaculo(pos), ativo_(ativo)
        {
          corpo.setFillColor(sf::Color::Red);
          if(!ativo_){
            sf::Vector2f tam = corpo.getSize();
            corpo.setSize(sf::Vector2f(tam.x, 2));
            corpo.setOrigin((corpo.getSize().x - tam.x)/2 , (corpo.getSize().y - tam.y)/2);
            corpo.setPosition(sf::Vector2f(corpo.getPosition().x, corpo.getPosition().y + tam.y/2));
          }
            
        }

        Neutralizador::~Neutralizador()
        {
            
        }

        void Neutralizador::executar()
        {
            
        }

        void Neutralizador::colidir(Entidade* outro, int side)
        {
          if(outro == nullptr)
            return;

            Entidades::Personagens::Personagem* aux;
            try
            {
              aux = dynamic_cast<Entidades::Personagens::Personagem*>(outro);
              if(ativo_)
                aux->set_vida(0);
              else 
                aux->setPosicao(sf::Vector2f(aux->getPosicao().x, aux->getPosicao().y - 300));
              
            }
            catch(const std::exception& e)
            {
              return;
            }
        }
    }
}