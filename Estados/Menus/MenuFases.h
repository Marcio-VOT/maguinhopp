#pragma once

#include "./Menu.h"
#include "../Fases/Fase.h"
// #include "../Fases/FasePrimeira.h"
// #include "../Fases/FasePrimeira.h"

namespace Estados {
    namespace Menus {

        class MenuFases : public Menu {
        private:
            Estados::Fases::Fase* plvl;

        public:
            MenuFases(Estados::Fases::Fase* plvl = nullptr);

            ~MenuFases();

            void atualiza() { 
            }

            void desenha();

            void executar();

            void resetaEstado();
        };

    }
}