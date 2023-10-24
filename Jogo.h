#pragma once

#include "../Entidades/Personagem/Jogador.h"
#include "../Entidades/Personagem/Inimigo.h"

using namespace sf;
class Jogo
{
private:
    // Janela do Jogo
    RenderWindow window;
    // figura
    std::vector<Personagem*> personagens;
    
public:
    Jogo();
    ~Jogo();

    void Executar();
};

