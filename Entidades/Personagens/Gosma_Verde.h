#pragma once

#include "Inimigo.h"

namespace Entidades
{
    namespace Personagens
    {
        class Gosma_Verde: public Inimigo
        {
        private:
            float nivel_de_gosma;
            static int nivel_de_gosma_max;
        public:
            Gosma_Verde(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f));
            ~Gosma_Verde();
            float get_nivel_de_gosma();
            void set_nivel_de_gosma(float nivel_de_gosma);
            void executar();
            void mover();
            int get_dano() const;
            void salvar(std::ostringstream* entrada);
            void colidir(Entidade* outro, int side = -1);
        };
    }
}