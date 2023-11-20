#pragma once

#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class Gosma_Verde: public Inimigo
        {
        private:
        public:
            Gosma_Verde(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
            ~Gosma_Verde();
            void executar();
            void mover();
            void salvar(std::ostringstream* entrada);
        };
    }
}