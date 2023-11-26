#pragma once

#include "./Menu.h"
#include "../Fases/Fase.h"
#include "../../Jogo.h"

namespace Estados {
    namespace Menus {

        class Pausa : public Menu {
        private:
            Estados::Fases::Fase* plvl;

        public:
            Pausa(Estados::Fases::Fase* plvl = nullptr);

            ~Pausa();

            void atualiza() { 
            }

            void desenha();

            void resetaEstado();

            void executar();

            void AtivaMenuPausa();
        };

    }
}