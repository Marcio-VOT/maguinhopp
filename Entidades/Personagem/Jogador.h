#pragma once

#include "Personagem.h"

#include <time.h>

#include <cmath>

#define VELOCIDADE_JOGADOR_X 0.025f
#define VELOCIDADE_JOGADOR_Y 0.025f

using namespace sf;

class Jogador : public Personagem
{
private:
    RectangleShape body;
    Vector2f vel;
    void inicializa();
public:
    Jogador(const Vector2f pos, const Vector2f tam);
    ~Jogador();
    
    void atualiza();
};

