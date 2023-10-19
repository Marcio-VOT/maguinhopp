#pragma once
#include "../Entidades/Personagem/Jogador.h"

using namespace sf;
class Jogo
{
private:
    // Janela do Jogo
    RenderWindow window;
    // figura
    Jogador jogador;
    
public:
    Jogo();
    ~Jogo();

    void Executar();
};

