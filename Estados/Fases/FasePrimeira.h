#pragma once

#include "Fase.h"

#define ARQUIVO_CENARIO_1 "Design/Fase1/Cenario/cenario1.txt"
#define ARQUIVO_CENARIO_2 "Design/Fase1/Cenario/cenario1.txt"

namespace Estados
{
    namespace Fases
    {
        // Fase 1
        class FasePrimeira: public Fase
        {
        private:
        public:
            FasePrimeira(int id = 1);
            ~FasePrimeira();

            void executar();
            void resetaEstado();
            void desenha();
            void atualiza();
        };
    }    
}