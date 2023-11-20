#pragma once

#include "Movimentacao.h"
#include <random>


namespace Entidades {
  namespace Personagens{
    namespace Movimentacoes{
      class Gosma_movimentacao : public Movimentacao {
        public:
          static Gosma_movimentacao& getInstance(){
            static Gosma_movimentacao instance;
            return instance;
          }

          void mover(Entidade* ente = nullptr){
            ente->aplicaGravidade();
            sf::Vector2f velocidade = ente->getVelocidade();
            int max_vel = ente->getMaxVelocidade();

            // Gerar um número aleatório entre -1 e 1
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(-1, 1);

            // Adicionar o número aleatório à velocidade x
            velocidade += sf::Vector2f(dis(gen), 0);

            // Limitar a velocidade x à velocidade máxima
            if(velocidade.x > max_vel)
                velocidade.x = max_vel;
            else if(velocidade.x < -max_vel)
                velocidade.x = -max_vel;

            ente->setPosicao(ente->getPosicao() + velocidade);
            ente->setVelocidade(velocidade);
            ente->setNoChao(false);
          };
          
          private:
            Gosma_movimentacao() {};
            Gosma_movimentacao(const Gosma_movimentacao&);
      };
    }
  }
}