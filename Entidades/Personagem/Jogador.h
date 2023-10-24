#pragma once

#include "Personagem.h"

using namespace sf;

class Jogador : public Personagem
{
private:
    void inicializa();
    
public:
    Jogador(const Vector2f pos, const Vector2f tam);
    Jogador(const RectangleShape body);
    Jogador();
    ~Jogador();

    const RectangleShape getBody();
    void move();
};

