#pragma once 

#include <SFML/Graphics.hpp>   
#include <iostream>

using namespace sf;

class Personagem
{
    protected:
        RectangleShape body;
        Vector2f vel;
        
    public:
        Personagem(const Vector2f pos, const Vector2f tam);
        Personagem(const RectangleShape body);
        Personagem();
        ~Personagem();

        const RectangleShape getBody();
        virtual void move() = 0;

};