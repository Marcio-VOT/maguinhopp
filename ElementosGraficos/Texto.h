#pragma once

#include "../Gerenciadores/Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
#include <string>

#define FONT_PATH "./assets/Fonts/MainFont.ttf"

namespace ElementosGraficos {

    enum AlinhamentodeTexto {
        esquerda,
        centro,
        direita
    };

    class Texto {
    private:
        std::string info;

        sf::Text texto;

        static Gerenciadores::Gerenciador_Grafico* pGG;

    public:
        Texto(sf::Vector2f position = sf::Vector2f(0, 0), std::string info = "", const char* path = FONT_PATH);

        ~Texto();

        void setTextoInfo(std::string info);

        void setPosition(sf::Vector2f position);

        void setTextoColor(const unsigned int R, const unsigned int G, const unsigned int B);

        void setFontSize(const unsigned int size);

        void setAlinhamentodeTexto(AlinhamentodeTexto option);

        sf::Vector2f getSize() const;

        void render();

        std::string getInfo() const;

        sf::Vector2f getPosition() const;
    };

}