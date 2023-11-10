#pragma once

#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Jogador2: public Personagem
        {
        private:
            int pontos;
        public:
            Jogador2(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f vel = sf::Vector2f(0, 0));
            ~Jogador2();
            void executar();
            void mover();
            void salvar(std::ostringstream* entrada);
        };
    }
}