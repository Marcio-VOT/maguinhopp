#pragma once

#include "./Menu.h"
#include "../Fases/Fase.h"
#include "../../ElementosGraficos/Texto.h"
// #include "../Fases/FasePrimeira.h"
// #include "../Fases/FasePrimeira.h"

namespace Estados {
    namespace Menus {

        class MenuPrincipal : public Menu {
        private:
            Estados::Fases::Fase* plvl;
            ElementosGraficos::Texto titulo;

        public:
            MenuPrincipal(Estados::Fases::Fase* plvl = nullptr);

            ~MenuPrincipal();

            void atualiza() { 
            }

            void desenha();

            void executar();

            void resetaEstado();
        };

    }
}