#pragma once

#include "../Gerenciadores/Gerenciador_Grafico.h"

#include <SFML/Graphics.hpp>

namespace ElementosGraficos {

    class Elemento {
    protected:
        sf::RectangleShape body;
        static Gerenciadores::Gerenciador_Grafico* pGG;

    public:
        Elemento();

        virtual ~Elemento();

        virtual void render();
    };

}