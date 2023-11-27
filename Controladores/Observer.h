/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DOS TUTORES  "Os petequeiros Jean e Murilo" - https://github.com/Nixxye -  https://utfpr.curitiba.br/peteco/
    Canal: https://www.youtube.com/@PETECOUTFPR
    CÓDIGO ORIGINAL: https://github.com/Nixxye/peteco-tegprog
*/
#pragma once

#include "../Gerenciadores/Gerenciador_Entrada.h"
#include <iostream>

namespace Controladores {

    class Observer {
    private:
        Gerenciadores::Entrada* pGE;
    public:
        Observer();
        Observer(Gerenciadores::Entrada* pGE);
        virtual ~Observer();
        virtual void notifica(sf::String key) = 0;
    };

}