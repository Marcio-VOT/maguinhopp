/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
*/
#pragma once

#include "../Gerenciadores/Gerenciador_Grafico.h"

#include <SFML/Graphics.hpp>

namespace ElementosGraficos {

    class Elemento {
    protected:
        sf::RectangleShape body;
        Gerenciadores::Gerenciador_Grafico* pGG;

    public:
        Elemento();

        virtual ~Elemento();

        virtual void render();
    };

}