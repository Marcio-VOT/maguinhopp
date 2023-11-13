#pragma once

#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo_Facil: public Inimigo
        {
        private:
        public:
            Inimigo_Facil(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
            ~Inimigo_Facil();
            void executar();
            void mover();
            void salvar(std::ostringstream* entrada);
        };
    }
}