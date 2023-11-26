#pragma once

#include "Fase.h"

#define ARQUIVO_CENARIO_1 "Design/Fase1/Cenario/cenario1.txt"
#define ARQUIVO_CENARIO_2 "Design/Fase1/Cenario/cenario2.txt"

namespace Estados
{
    namespace Fases
    {
        // Fase 1
        class FasePrimeira: public Fase
        {
        private:
            std::string caminho;
        public:
            FasePrimeira(int id = 1, int quantidadeJogadores = 1);
            ~FasePrimeira();

            void executar();
            void resetaEstado();
            void desenha();
            void atualiza();
            void inicializar();
            void atualizaId(int id = 1);
        };
    }    
}