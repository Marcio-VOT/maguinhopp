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