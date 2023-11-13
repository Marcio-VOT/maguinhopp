#pragma once

#include "../Entidade.h"

namespace Entidades
{
    namespace Personagens
    {
        class Personagem: public Entidade
        {
        protected:
            static int max_vel;
            int pontos_de_vida;
        public:
            Personagem(sf::Vector2f pos, sf::Vector2f vel, IDs::IDs ID);
            ~Personagem();
            virtual void executar() = 0;
            int get_vida() { return pontos_de_vida; }
            void set_vida(int p) { pontos_de_vida = p; }
            void setDanoRecebido(int dano) { pontos_de_vida -= dano; }
            virtual void salvar(std::ostringstream* entrada){
                Entidade::salvar(entrada);
                (*entrada) << ", \"pontos_de_vida\": " << pontos_de_vida;
            };
        };
    }
    
}