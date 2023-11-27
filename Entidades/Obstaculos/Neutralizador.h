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
          bool ativo_;
        public:
            Neutralizador(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), bool ativo = true);
            ~Neutralizador();
            void executar();
            void colidir(Entidade* outro, int side = -1);
        };
    }
}