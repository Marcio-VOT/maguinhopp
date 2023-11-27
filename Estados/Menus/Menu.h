/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DOS TUTORES  "Os petequeiros Jean e Murilo" - https://github.com/Nixxye -  https://utfpr.curitiba.br/peteco/
    Canal: https://www.youtube.com/@PETECOUTFPR
    CÓDIGO ORIGINAL: https://github.com/Nixxye/peteco-tegprog
*/
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
        Controladores::Controlador_Menu control;
        bool ativo;


        public:
            Menu(int id = -1);
            ~Menu();

            virtual void executar() = 0;
            virtual void baixo();
            virtual void cima();
            virtual void setJogador2(){};
            void atualizarCamera();
        };
    }
}