#include "../Entidades/Personagens/Inimigo_Facil.h"

namespace Entidades
{
    namespace Personagens
    {

        Inimigo_Facil::Inimigo_Facil(sf::Vector2f pos, sf::Vector2f vel):
        Inimigo(pos, vel, IDs::IDs::slime),
        m(5)
        {
        }
        Inimigo_Facil::~Inimigo_Facil()
        {

        }
        void Inimigo_Facil::executar()
        {
            corpo.setPosition(corpo.getPosition() + velocidade);
        }
        void Inimigo_Facil::mover()
        {
            velocidade += sf::Vector2f(rand() % 10 - 5,(float) (nochao ? - (rand() % 5) : 0));
            if (!nochao)
                velocidade += sf::Vector2f(0, 0.1);  
            else
                velocidade = sf::Vector2f(velocidade.x, 0.f);
            nochao = false;
        }
        void Inimigo_Facil::salvar(std::ostringstream* entrada)
        {
            Inimigo::salvar(entrada);
            (*entrada) << " \"m\" :" << m << std::endl;
        }
    }
}