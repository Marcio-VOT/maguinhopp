#pragma once

#include "../Entidade.h"
#include "Movimentacao/Movimentacao.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem: public Entidade
        {
        protected:
            int pontos_de_vida;
            float ataque_tempo;
            const float ataque_tempo_max;
            int dano;
            Movimentacoes::Movimentacao* _movimentacao;
        public:
            Personagem(sf::Vector2f pos, sf::Vector2f vel, IDs::IDs ID, int vel_max = 5);
            ~Personagem();
            virtual void executar() = 0;
            void setMovimentacao(Movimentacoes::Movimentacao* movimentacao){
                _movimentacao = movimentacao;
            };
            int get_vida() { return pontos_de_vida; }
            void set_vida(int p) { pontos_de_vida = p; }
            void setDanoRecebido(int dano) { pontos_de_vida -= dano; }
            const void set_dano(int d) { dano = d; }
            virtual int get_dano() const { return dano; }
            virtual void salvar(std::ostringstream* entrada){
                Entidade::salvar(entrada);
                (*entrada) << ", \"pontos_de_vida\": " << pontos_de_vida;
            }
            bool neutralizado() const { return pontos_de_vida <= 0; };
        };
    }
    
}