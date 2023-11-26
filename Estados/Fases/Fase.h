#pragma once

#include "../../Entidades/Entidade.h"
#include "../../Entidades/Personagens/Jogador.h"
#include "../../Entidades/Obstaculos/Obst_Facil.h"
#include "../../Entidades/Personagens/Gosma_Verde.h"
#include "../../Entidades/Personagens/Gosma_Nuclear.h"
#include "../../Listas/ListaEntidades.h"
#include "../../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Estado.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include "json.hpp"

namespace Estados
{
    namespace Fases
    {
        class Fase: public Ente, public Estado
        {
        protected:
            Listas::ListaEntidades jogadores;
            Listas::ListaEntidades obstaculos;
            Listas::ListaEntidades inimigos;
            Gerenciadores::Gerenciador_Colisoes gC;
            std::ostringstream buffer;
            bool fimDeJogo;
            int quantidadeJogadores;
            bool primeira;

        public:
            Fase(int i = - 1, int quantidadeJogadores = 1);
            ~Fase();

            virtual void executar() = 0;
            virtual void inicializar() = 0;
            virtual void atualizaId(int id = 1) = 0;
            void gerenciar_colisoes();
            void setPrimeira(bool primeira){
                this->primeira = primeira;
            };
            bool getPrimeira() const{
                return primeira;
            };
            void criarJogadores();
            void criarInimigos();
            void removeNeutralizados();
            void criarCenario(std::string caminho);
            void terminar(){
                fimDeJogo = true;
                jogadores.limpar();
                inimigos.limpar();
                obstaculos.limpar();
            };
            int getQuantidadeJogadores() const{
                return quantidadeJogadores;
            };
            void setQuantidadeJogadores(int quantidadeJogadores){
                this->quantidadeJogadores = quantidadeJogadores;
            };
            void salvar();
            virtual void resetaEstado() = 0;
            virtual void desenha() = 0;
        };
    }    
}