#include "../Jogo.h"

Jogo::Jogo() : window(VideoMode(1800, 920), "Jogo"),
               shape(Vector2f(60.f, 85.f))
{
    shape.setFillColor(Color::Green);
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
        window.draw(shape);
        window.display();
    }
}