#include "Jogo.h"
#include <iostream>
#include <fstream>
#include <string>

Jogo::Jogo() : window(VideoMode(1800, 920), "Jogo"),
               maga(&window, IDs::IDs::jogador1), mago(&window, IDs::IDs::jogador2)

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
                // save the maga.salvar inside a file
                ofstream myfile;
                myfile.open("save.txt");
                if (myfile.is_open())
                {
                    cout << "File ofstream is open" << endl;
                    myfile << maga.salvar() << endl;
                    myfile << mago.salvar() << endl;
                    myfile.close();
                }
                else
                {
                    cout << "Unable to open file";
                }

                window.close();
            }
        }
        mago.move();
        maga.move();
        window.clear(Color(173, 216, 230));
        maga.desenhar();
        mago.desenhar();
        window.display();
    }
}