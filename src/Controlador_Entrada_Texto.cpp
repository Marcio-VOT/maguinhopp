#include "../Controladores/Controlador_Entrada_Texto.h"

namespace Controladores {
  Controlador_Entrada_Texto::Controlador_Entrada_Texto(): Observer() {
  }

  Controlador_Entrada_Texto::~Controlador_Entrada_Texto() {
  }

  void Controlador_Entrada_Texto::notifica(sf::String key) {
    if (key == "Enter" || 
        key == "Right" || 
        key == "Left" || 
        key == "Up" || 
        key == "Down" || 
        key == "Escape" || 
        key == "Control" || 
        key == "Shift" || 
        key == "RControl" || 
        key == "RShift" || 
        key == "Tab"||
        key == "Unknown"){
        return;
        }

    if (key == "BackSpace") {
        if (texto.size() > 0)
            texto.pop_back();
    }
    else if (key == "Space") 
      texto += " ";
    else
      texto += key;
  }

  std::string Controlador_Entrada_Texto::getTexto() const {
    return texto;
  }

  void Controlador_Entrada_Texto::resetTexto() {
    texto = "";
  }

}