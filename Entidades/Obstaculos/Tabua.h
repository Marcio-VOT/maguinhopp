#pragma once 

#include "Obstaculo.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Tabua: public Obstaculo
        {
        private:
          float tempo_sumir;
          static int tempo_sumir_max;
          bool sumindo;
          bool neutralizado_;

        public:
            Tabua(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Tabua();
            void executar();
            void colidir(Entidade* outro, int side = -1);
            bool neutralizado() const { return neutralizado_;};
        };
    }
}