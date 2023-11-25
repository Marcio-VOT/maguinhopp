#pragma once 

#include "../Estado.h"
#include "../../Ente.h"

namespace ElementosGraficos{
    class Botao;
}

namespace Controladores {
    class Controlador_Menu;
}

namespace Estados
{
    namespace Menus
    {
        class Menu: public Ente, public Estado
        {
        protected:
        std::vector<ElementosGraficos::Botao*> botoes;
        std::vector<ElementosGraficos::Botao*>::iterator it;
        int selecionado;
        int min;
        int max;
        Controladores::Controlador_Menu control;
        bool ativo;


        public:
            Menu();
            ~Menu();

            virtual void executar() = 0;
            virtual void baixo();
            virtual void cima();
            void atualizarCamera();
        };
    }
}