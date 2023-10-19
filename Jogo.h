#pragma once
#include "Jogador.h"

using namespace sf;
class Jogo
{
private:
    // Janela do Jogo
    RenderWindow window;
    // figura
    RectangleShape jogador;
    
public:
    Jogo();
    ~Jogo();

    void Executar();
};

