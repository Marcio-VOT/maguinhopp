#include "../Entidades/Personagens/Movimentacao/Jogador2_movimentacao.h"
namespace Entidades {
  namespace Personagens{
    namespace Movimentacoes{
      void Jogador2_movimentacao::mover(Entidade *ente)
      {
        aplicaGravidade(ente);    
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
            velocidade.x *= 0.9f;

        if(velocidade.x > max_vel)
            velocidade.x = max_vel;
        else if(velocidade.x < -max_vel)
            velocidade.x = -max_vel;

        ente->setPosicao(ente->getPosicao() + velocidade);
        ente->setVelocidade(velocidade);
        ente->setNoChao(false);
    }

      void Jogador2_movimentacao::aplicaGravidade(Entidade *ente)
      {
          if (!ente->getNoChao())
              ente->setVelocidade(ente->getVelocidade() + sf::Vector2f(0, 0.1));
          else
              ente->setVelocidade(sf::Vector2f(ente->getVelocidade().x, 0.f));
      }
        
    }
  }
}
