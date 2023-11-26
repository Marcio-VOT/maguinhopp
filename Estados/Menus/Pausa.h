#pragma once

#include "./Menu.h"
#include "../Fases/Fase.h"
// #include "../Fases/FasePrimeira.h"
// #include "../Fases/FasePrimeira.h"

namespace Estados {
    namespace Menus {

        class Pausa : public Menu {
        private:
            Estados::Fases::Fase* plvl;

        public:
            Pausa(Estados::Fases::Fase* plvl = nullptr);

            ~Pausa();

            void desenha();

            void executar();

            void resetaEstado();

            void AtivaMenuPausa();

            void atualiza() { 
            }
        };

    }
}