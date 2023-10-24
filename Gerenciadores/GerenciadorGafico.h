#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class GerenciadorGrafico
{
private:
    RenderWindow* window;
    //Padrao Singleton
    static GerenciadorGrafico* pGrafico;
    GerenciadorGrafico();
public:
    ~GerenciadorGrafico();

    static GerenciadorGrafico* getGerenciadorGrafico();

    RenderWindow* getWindow();
    void limpaJanela();
    void desenhaElemento(RectangleShape body);  
    void mostraElemento();
    void fechaJanela();
    const bool verificaJanelaAberta();

};