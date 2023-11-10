#include "Gerenciadores/GerenciadorEventos.h"

GerenciadorEventos* GerenciadorEventos::pEventos = nullptr;

GerenciadorEventos::GerenciadorEventos()
{
    pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
}

GerenciadorEventos::~GerenciadorEventos()
{
    delete pEventos;
}

GerenciadorEventos* GerenciadorEventos::getGerenciadorEventos()
{
    if(pEventos == nullptr)
    {
        pEventos = new GerenciadorEventos();
    }
    return pEventos;
}

void GerenciadorEventos::setJogador(Jogador* pJogador)
{
    this->pJogador = pJogador;
}

void GerenciadorEventos::verificaTeclaPressionada(Keyboard::Key tecla)
{
    if(tecla == Keyboard::Key::A)
    {
        pJogador->andar(true);
    }else if(tecla == Keyboard::Key::D)
    {
        pJogador->andar(false);
    }else if(tecla == Keyboard::Key::Space)
    {
        pGrafico->fechaJanela();
    }
}

void GerenciadorEventos::verificaTeclaSolta(Keyboard::Key tecla)
{
    if(tecla == Keyboard::Key::A || tecla == Keyboard::Key::D)
    {
        pJogador->parar();
    }
}

void GerenciadorEventos::executar()
{
    Event event;
    while(pGrafico->getWindow()->pollEvent(event))
    {
        if(event.type == Event::KeyPressed)
        {
           verificaTeclaPressionada(event.key.code);
        }
        else if(event.type == Event::KeyReleased)
        {
            verificaTeclaSolta(event.key.code);
        }      
        else if(event.type == Event::Closed)
        {
            pGrafico->fechaJanela();
        }
        
    }
}
