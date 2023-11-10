#include "Jogo.h"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico()),
               personagens()
{
    if(pGrafico == nullptr)
    {
        std::cout << "Erro ao criar janela" << std::endl;
        exit(1);
    }


    Jogador* jogador = new Jogador(Vector2f(100.0f, 200.0f), Vector2f(50.0f, 50.0f));
    Inimigo* inimigo1 = new Inimigo(Vector2f(100.0f, 100.0f), Vector2f(50.0f, 50.0f), jogador);
    Inimigo* inimigo2 = new Inimigo(Vector2f(200.0f, 200.0f), Vector2f(50.0f, 50.0f), jogador);

    Personagem* p1 = static_cast<Personagem*>(jogador);
    Personagem* p2 = static_cast<Personagem*>(inimigo1);
    Personagem* p3 = static_cast<Personagem*>(inimigo2);

    personagens.push_back(p1);
    personagens.push_back(p2);
    personagens.push_back(p3);

    Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    pEvento->executar();
    while (pGrafico->verificaJanelaAberta())
    {
        
        pGrafico->limpaJanela();
        for(int i = 0; i < personagens.size(); i++)
        {
            personagens.at(i)->atualiza();
            pGrafico->desenhaElemento(personagens.at(i)->getBody());
        }
        pGrafico->mostraElemento();
    }
    personagens.clear();
}