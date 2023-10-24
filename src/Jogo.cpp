#include "../Jogo.h"

Jogo::Jogo() : window(VideoMode(1800, 920), "Maguinho++"),
               personagens()
{
    Jogador* jogador = new Jogador(Vector2f(100.0f, 200.0f), Vector2f(50.0f, 50.0f));
    Inimigo* inimigo = new Inimigo(Vector2f(100.0f, 100.0f), Vector2f(50.0f, 50.0f), jogador);

    Personagem* p1 = static_cast<Personagem*>(jogador);
    Personagem* p2 = static_cast<Personagem*>(inimigo);

    personagens.push_back(p1);
    personagens.push_back(p2);

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
        for(int i = 0; i < personagens.size(); i++)
        {
            personagens.at(i)->move();
            window.draw(personagens.at(i)->getBody());
        }
        window.display();
    }
    personagens.clear();
}