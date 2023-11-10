#include "../Entidades/Personagens/Jogador.h"

#define SKIN_JOGADOR "./public/assets/Jogadores/Jogador1.png"
#define ALTURA_JOGADOR 85.0f
#define LARGURA_JOGADOR 60.0f
#include <iostream>



namespace Entidades
{
    namespace Personagens
    {
        Jogador::Jogador(sf::Vector2f pos, sf::Vector2f vel):
        Personagem(pos, vel, IDs::IDs::jgd1),
        pontos(0)
        {
          corpo.setSize(sf::Vector2f(LARGURA_JOGADOR, ALTURA_JOGADOR));
          corpo.setOrigin(sf::Vector2f((LARGURA_JOGADOR-TAM)/2, (ALTURA_JOGADOR-TAM)/2));
          set_and_load_textura(SKIN_JOGADOR);
        }
        Jogador::~Jogador()
        {

        }
        void Jogador::executar()
        {
            mover();
        }
        void Jogador::mover()
        {
            //flag para definir se o personagem se moveu
            bool f = false;
            sf::Vector2f velocidade_inicial = velocidade;

            if (!nochao)
                velocidade += sf::Vector2f(0, 0.1);
            else
                velocidade = sf::Vector2f(velocidade.x, 0.f);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                velocidade += sf::Vector2f(0.1, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                velocidade += sf::Vector2f(-0.1, 0);  
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && nochao)
                velocidade += sf::Vector2f(0, -5.f); 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                velocidade += sf::Vector2f(0, 0.1);
                
            if(velocidade.x == velocidade_inicial.x)
                velocidade.x *= 0.9f;

            if(velocidade.x > max_vel)
                velocidade.x = max_vel;
            else if(velocidade.x < -max_vel)
                velocidade.x = -max_vel;
            
            corpo.setPosition(corpo.getPosition() + velocidade);
            nochao = false;
        }

        void Jogador::salvar(std::ostringstream* entrada)
        {
            Personagem::salvar(entrada);
            (*entrada) << ", \"pontos\": " << pontos << " }" << std::endl;
        }
    }
}