#include "Jogo.h"

Jogo::Jogo() : window(VideoMode(1800, 920), "Jogo"),
               maga(&window)
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
            {

                cout << "Fechando"
                     << "\n"
                     << maga.salvar() << endl;

                window.close();
            }
        }
        maga.move();
        window.clear(Color(173, 216, 230));
        maga.desenhar();
        window.display();
    }
}