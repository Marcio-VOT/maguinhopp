#include "../Entidades/Obstaculos/Tabua.h"

namespace Entidades
{
    namespace Obstaculos
    {

        int Tabua::tempo_sumir_max = 1.f;
        Tabua::Tabua(sf::Vector2f pos):
        Obstaculo(pos, false),
        sumindo(false),
        neutralizado_(false)
        {
          corpo.setFillColor(sf::Color(165, 42, 42, 255));
          corpo.setOutlineThickness(1.f);
          corpo.setOutlineColor(sf::Color::Black);
          corpo.setSize(sf::Vector2f(corpo.getSize().x, corpo.getSize().y +2));
          set_id(IDs::IDs::tabua);
        }
        Tabua::~Tabua()
        {

        }
        void Tabua::executar()
        {
            if(sumindo)
            {
                tempo_sumir += 0.1f;
                if(tempo_sumir >= tempo_sumir_max)
                {
                  neutralizado_ = true;
                }
            }
        }

        void Tabua::colidir(Entidade* outro, int side)
        {
            if(outro->get_id() == IDs::IDs::jgd1 || outro->get_id() == IDs::IDs::jgd2 ){
              sumindo = true;
            }
        }
    }
}