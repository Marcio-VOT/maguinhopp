#pragma once

#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGafico.h"
#include "Entidades/Personagem/Jogador.h"
#include "Entidades/Personagem/Inimigo.h"


using namespace sf;
class Jogo
{
private:
    // Janela do Jogo
    GerenciadorGrafico* pGrafico;
    GerenciadorEventos* pEvento;
    // figura
    std::vector<Personagem*> personagens;
    
public:
    Jogo();
    ~Jogo();
    void Executar();
    void instanciaPersonagem();
};

