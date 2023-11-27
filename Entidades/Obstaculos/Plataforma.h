#pragma once 

#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        enum tamanho_plataforma {p = 1, m = 2, g = 3};
        class Plataforma: public Obstaculo
        {
        private:
          tamanho_plataforma tamanho_;
        public:
            Plataforma(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), char tipo = 'p');
            ~Plataforma();
            void executar();
        };
    }
}