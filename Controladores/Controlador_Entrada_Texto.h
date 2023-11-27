/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DOS TUTORES  "Os petequeiros Jean e Murilo" - https://github.com/Nixxye -  https://utfpr.curitiba.br/peteco/
    Canal: https://www.youtube.com/@PETECOUTFPR
    CÓDIGO ORIGINAL: https://github.com/Nixxye/peteco-tegprog
*/
#pragma once

#include "Observer.h"
#include <string.h>

namespace Controladores {

    class Controlador_Entrada_Texto: public Observer {
    private:
    std::string texto;

    public:
        Controlador_Entrada_Texto();
        ~Controlador_Entrada_Texto();
        void notifica(sf::String key);
        std::string getTexto() const;
        void resetTexto();
    };

}