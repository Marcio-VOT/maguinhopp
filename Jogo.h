#pragma once

#include "Gerenciadores/GerenciadorGafico.h"
#include "Entidades/Personagem/Jogador.h"
#include "Entidades/Personagem/Inimigo.h"


using namespace sf;
class Jogo
{
private:
    // Janela do Jogo
    GerenciadorGrafico* pGrafico;
    // figura
    std::vector<Personagem*> personagens;
    
public:
    Jogo();
    ~Jogo();
    void Executar();
};

