#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Maga.h"

using namespace sf;
class Jogo
{
private:
    // Janela do Jogo
    RenderWindow window;
    // maga
    Maga maga;

public:
    Jogo();
    ~Jogo();
    void Executar();
};
