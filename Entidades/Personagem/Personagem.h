#pragma once 

#include <SFML/Graphics.hpp>   
#include <iostream>

#define GRAVIDADE 10.0f

using namespace sf;

class Personagem
{
    protected:
        RectangleShape body;
        Vector2f velFinal;
        bool podeAndar;
        bool paraEsquerda;
        Clock relogio;
        float dt;
        
    public:
        Personagem(const Vector2f pos, const Vector2f tam, const float vel);
        ~Personagem();

        const RectangleShape getBody();
        void andar(const bool paraEsquerda);
        void parar();
        virtual void atualiza() = 0;

        void atualizarPosicao();

};