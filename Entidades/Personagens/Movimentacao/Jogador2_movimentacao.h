#pragma once

#include "Movimentacao.h"
#include <iostream>
#include <cmath>

namespace Entidades {
  namespace Personagens{
    namespace Movimentacoes{
      class Jogador2_movimentacao : public Movimentacao {
        public:
          static Jogador2_movimentacao& getInstance(){
            static Jogador2_movimentacao instance;
            return instance;
          }

          void mover(Entidade* ente = nullptr)
          {
            ente->aplicaGravidade();
            sf::Vector2f velocidade_inicial = ente->getVelocidade();
            sf::Vector2f velocidade = velocidade_inicial;
            bool nochao = ente->getNoChao();
            int max_vel = ente->getMaxVelocidade();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            velocidade += sf::Vector2f(0.1, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                velocidade += sf::Vector2f(-0.1, 0);  
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && nochao)
                velocidade += sf::Vector2f(0, -5.f); 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                velocidade += sf::Vector2f(0, 0.1);
                
            if(velocidade.x != velocidade_inicial.x){
                if(velocidade.x > 0)
                    ente->set_textura();
                else if(velocidade.x < 0)
                    ente->set_inv_textura();
            }
            
            if(velocidade.x == velocidade_inicial.x)
                velocidade.x = std::round(velocidade.x * 0.9f * 1000) / 1000;

            if(velocidade.x > max_vel)
                velocidade.x = max_vel;
            else if(velocidade.x < -max_vel)
                velocidade.x = -max_vel;


            ente->setPosicao(ente->getPosicao() + velocidade);
            ente->setVelocidade(velocidade);
            ente->setNoChao(false);
          };
          
          private:
            Jogador2_movimentacao() {};
            Jogador2_movimentacao(const Jogador2_movimentacao&);
      };
    }
  }
}