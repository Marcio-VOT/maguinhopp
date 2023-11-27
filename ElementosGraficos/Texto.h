/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
*/
#pragma once

#include "../Gerenciadores/Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
#include <string>

#define FONT_PATH "./public/assets/fonts/MainFont.ttf"

namespace ElementosGraficos {

    enum AlinhamentodeTexto {
        esquerda,
        centro,
        direita
    };

    class Texto {
    private:
        std::string info;
        sf::Font* fonte;
        sf::Text texto;

        static Gerenciadores::Gerenciador_Grafico* pGG;

    public:
        Texto(sf::Vector2f position = sf::Vector2f(0, 0), std::string info = "", const char* path = FONT_PATH);

        ~Texto();

        void setTextoInfo(std::string info);

        void getFonte(const char* path);

        void setPosicao(sf::Vector2f position);

        void setCorTexto(const unsigned int R, const unsigned int G, const unsigned int B);

        void setCorTexto(sf::Color C);

        void setTamanhoFonte(const unsigned int size);

        void setAlinhamentodeTexto(AlinhamentodeTexto option);

        sf::Vector2f getSize() const;

        void desenha();

        std::string getInfo() const;

        sf::Vector2f getPosicaon() const;
    };

}