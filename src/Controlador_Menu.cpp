#include "../Controladores/Controlador_Menu.h"
#include "../Estados/Menus/Menu.h"
#include "../Estados/Menus/Pausa.h"



namespace Controladores{
    
    Controlador_Menu::Controlador_Menu(Estados::Menus::Menu* pM): Observer() {
        pMenu = pM;
    }

    Controlador_Menu::~Controlador_Menu() {
      pMenu = nullptr;
    }

    void Controlador_Menu::notifica(sf::String key) {
      if (pMenu == NULL) {
            std::cout << "ERROR pointer to Menu NULL on MenuControl::notify()." << std::endl;
            exit(1);
        }

        if (key == "Down")
            pMenu->baixo();
        if (key == "Up")
            pMenu->cima();
        if (key == "Enter")
            pMenu->executar();
        if (key == "Escape"){
            if (dynamic_cast<Estados::Menus::Pausa*>(pMenu) != nullptr)
                dynamic_cast<Estados::Menus::Pausa*>(pMenu)->AtivaMenuPausa();
        }
    }

    void Controlador_Menu::setMenu(Estados::Menus::Menu* pM) {
        pMenu = pM;
    }
}