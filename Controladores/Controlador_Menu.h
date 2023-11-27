/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DOS TUTORES  "Os petequeiros Jean e Murilo" - https://github.com/Nixxye -  https://utfpr.curitiba.br/peteco/
    Canal: https://www.youtube.com/@PETECOUTFPR
    CÓDIGO ORIGINAL: https://github.com/Nixxye/peteco-tegprog
*/
#pragma once

#include "Observer.h"
#include "../Gerenciadores/Gerenciador_Entrada.h"

namespace Estados {
    namespace Menus {
        class Menu;
    }
}

namespace Controladores {

    class Controlador_Menu : public Observer {
    private:
    Estados::Menus::Menu* pMenu;

    public:
        Controlador_Menu(Estados::Menus::Menu* pM = nullptr);
        ~Controlador_Menu();
        void notifica(sf::String key);
        void setMenu(Estados::Menus::Menu* pM);
    };

}