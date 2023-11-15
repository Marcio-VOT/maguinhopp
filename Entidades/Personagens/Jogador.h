#pragma once

#include "Personagem.h"
#include "Movimentacao/Movimentacao.h"
#include "./Movimentacao/Jogador1_movimentacao.h"
#include "./Movimentacao/Jogador2_movimentacao.h"


namespace Entidades
{
    namespace Personagens
    {
        class Jogador: public Personagem
        {
        private:
            int pontos;
            
        public:
            Jogador(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f vel = sf::Vector2f(0, 0));
            ~Jogador();
            void updatePlayerId(IDs::IDs id);
            void executar();
            void mover();
            void salvar(std::ostringstream* entrada);
        };
    }
}