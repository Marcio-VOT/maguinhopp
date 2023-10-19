#include "../Jogo.h"

Jogo::Jogo() : window(VideoMode(1800, 920), "Jogo"),
               jogador()
{
    Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        

        window.clear();
        jogador.move();
        window.draw(jogador.getBody());
        window.display();
    }
}