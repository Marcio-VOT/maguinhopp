#include "../Entidades/Personagem/Inimigo.h"

Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, Jogador* jogador):
    Personagem(pos, tam), relogio(), jogador(jogador)
{
    body.setFillColor(Color::Red);
    inicializa();
    srand(time(NULL));
    moveAleatorio = rand() % 4;
}

Inimigo::~Inimigo()
{
}

void Inimigo::inicializa()
{
    vel = Vector2f(VELOCIDADE_INIMIGO_X, VELOCIDADE_INIMIGO_Y);
}

void Inimigo::persegueJogador(Vector2f posJogador, Vector2f posInimigo)
{

}

void Inimigo::movimentoAleatorio()
{
 
}
