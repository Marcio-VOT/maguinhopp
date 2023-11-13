#pragma once

#include "Personagem.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo: public Personagem
        {
        protected:
            float ataque_tempo;
            static float ataque_tempo_max;
            int dano;
            
        public:
            Inimigo(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f vel = sf::Vector2f(0.f, 0.f), IDs::IDs id = IDs::IDs::vazio);
            ~Inimigo();
            virtual void mover() = 0;
            virtual void executar() = 0;
            virtual void salvar(std::ostringstream* entrada);
            const void set_dano(int d) { dano = d; }
            const int get_dano() const { return dano; }
            virtual void colidir(Entidades::Entidade* outro);
        };
    }
}