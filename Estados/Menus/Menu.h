#pragma once 

#include "../Estado.h"
#include "../../Ente.h"
#include "../../ElementosGraficos/Botao.h"
#include "../../Controladores/Controlador_Menu.h"
#include "../../Gerenciadores/Gerenciador_Grafico.h"

namespace Estados
{
    namespace Menus
    {
        class Menu: public Estado
        {
        protected:
        std::vector<ElementosGraficos::Botao*> botoes;
        std::vector<ElementosGraficos::Botao*>::iterator it;
        Gerenciadores::Gerenciador_Grafico* pGG;
        int selecionado;
        int min;
        int max;
        Controladores::Controlador_Menu control;
        bool ativo;


        public:
            Menu(int id = -1);
            ~Menu();

            virtual void executar() = 0;
            virtual void baixo();
            virtual void cima();
            void atualizarCamera();
        };
    }
}