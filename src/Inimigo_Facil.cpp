#include "../Entidades/Personagens/Inimigo_Facil.h"

#define SKIN_BLUE_SLIME "./public/assets/Inimigos/slime-blue.png"
#define ALTURA_SLIME 50.0f
#define LARGURA_SLIME 50.0f
namespace Entidades
{
    namespace Personagens
    {


        Inimigo_Facil::Inimigo_Facil(sf::Vector2f pos, sf::Vector2f vel):
        Inimigo(pos, vel, IDs::IDs::slime)
        {
            corpo.setSize(sf::Vector2f(LARGURA_SLIME, ALTURA_SLIME));
            corpo.setOrigin(sf::Vector2f((LARGURA_SLIME-TAM)/2, (ALTURA_SLIME-TAM)/2));
            set_and_load_textura(SKIN_BLUE_SLIME);
        }
        
        Inimigo_Facil::~Inimigo_Facil()
        {

        }
        void Inimigo_Facil::executar()
        {
            mover();
        }

        void Inimigo_Facil::mover()
        {
            velocidade += sf::Vector2f(rand() % 10 - 5,(float) (nochao ? - (rand() % 5) : 0));
            if (!nochao)
                velocidade += sf::Vector2f(0, 0.1);
            else
                velocidade = sf::Vector2f(velocidade.x, 0.f);
            
            corpo.setPosition(corpo.getPosition() + velocidade);
            nochao = false;
        }

        void Inimigo_Facil::salvar(std::ostringstream* entrada)
        {
            Inimigo::salvar(entrada);
            // (*entrada) << " \"m\" :" << m << std::endl;
        }
    }
}