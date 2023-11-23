#pragma once 

#include "Obstaculo.h"
#include "../Personagens/Personagem.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Neutralizador: public Obstaculo
        {
        private:

        public:
            Neutralizador(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Neutralizador();
            void executar();
            void colidir(Entidade* outro, int side = -1){
              if(outro != nullptr){
                try
                {
                  dynamic_cast<Entidades::Personagens::Personagem*>(outro)->set_vida(0);
                }
                catch(const std::exception& e)
                {
                }
                
              }
            };
        };
    }
}