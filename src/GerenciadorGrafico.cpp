#include "Gerenciadores/GerenciadorGafico.h"

GerenciadorGrafico* pGrafico = nullptr;

GerenciadorGrafico::GerenciadorGrafico(): 
    window(new RenderWindow(VideoMode(1800.0f, 920.0f), "Maguinho++"))
{
    if(window == nullptr){
        std::cout << "Erro ao criar janela" << std::endl;
        exit(1);
    }
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    if(window)
    {
        delete window;
        window = nullptr;
    }
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
    if(pGrafico == nullptr)
    {
        return new GerenciadorGrafico();
    }
    return pGrafico;
}

RenderWindow* GerenciadorGrafico::getWindow()
{
    return window;
}

void GerenciadorGrafico::limpaJanela()
{
    window->clear();
}

void GerenciadorGrafico::desenhaElemento(RectangleShape body)
{
    window->draw(body);
}

void GerenciadorGrafico::mostraElemento()
{
    window->display();
}

void GerenciadorGrafico::fechaJanela()
{
    window->close();
}

const bool GerenciadorGrafico::verificaJanelaAberta()
{
    return window->isOpen();
}