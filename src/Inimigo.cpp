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
    if(posJogador.x - posInimigo.x > 0.0f)
    {
        body.move(vel.x, 0.0f);
    }
    else
    {
        body.move(-vel.x, 0.0f);
    }

    if(posJogador.y - posInimigo.y > 0.0f)
    {
        body.move(0.0f, vel.y);
    }
    else
    {
        body.move(0.0f, -vel.y);
    }
}

void Inimigo::movimentoAleatorio()
{
    if(moveAleatorio == 0)
    {
        body.move(vel.x, 0.0f);
    }
    else if(moveAleatorio == 1)
    {
        body.move(-vel.x, 0.0f);
    }
    else if(moveAleatorio == 2)
    {
        body.move(0.0f, vel.y);
    }
    else if(moveAleatorio == 3)
    {
        body.move(0.0f, -vel.y);
    }

    float dt = relogio.getElapsedTime().asSeconds();
    if(dt > 1.0f)
    {
        moveAleatorio = rand() % 4;
        relogio.restart();
    }
}

void Inimigo::move()
{
    Vector2f posJogador = jogador->getBody().getPosition();
    Vector2f posInimigo = body.getPosition();

    if(fabs(posJogador.x - posInimigo.x) < RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) < RAIO_PERSEGUIR_Y)
    {
        persegueJogador(posJogador, posInimigo);
    }
    else
    {
        movimentoAleatorio();
    }
}