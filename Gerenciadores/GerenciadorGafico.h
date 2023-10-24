#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class GerenciadorGrafico
{
private:
    RenderWindow window;
    //Padrao Singleton
    static GerenciadorGrafico* pGrafico;
    GerenciadorGrafico();
public:
    ~GerenciadorGrafico();

    static GerenciadorGrafico* getGerenciadorGrafico();

    static GerenciadorGrafico* getGerenciadorGrafico();
    RenderWindow* getWindow();
    void limpaJanela();
    void desenhaElemento(const RectangleShape body);  
    void mostraElemento();
    void fechaJanela();
    const bool verificaJanelaAberta();

};