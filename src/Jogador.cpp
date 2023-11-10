#include "Entidades/Personagem/Jogador.h"

Jogador::Jogador(const Vector2f pos, const Vector2f tam):
    Personagem(pos, tam),body(tam), vel(), podeAndar(true)
{
    body.setPosition(pos);
    body.setFillColor(Color::Blue);
    inicializa();
}

Jogador::~Jogador()
{
}

void Jogador::inicializa()
{
    vel = Vector2f(VELOCIDADE_JOGADOR_X, VELOCIDADE_JOGADOR_Y);
}

void Jogador::atualiza()
{
    if(podeAndar)
    {
        atualizarPosicao();
    }
    relogio.restart();
}