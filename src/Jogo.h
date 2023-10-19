#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Maga.h"
#include "Mago.h"

using namespace sf;
class Jogo
{
private:
    // Janela do Jogo
    RenderWindow window;
    // maga
    Maga maga;
    // mago
    Mago mago;

public:
    Jogo();
    ~Jogo();
    void Executar();
};
