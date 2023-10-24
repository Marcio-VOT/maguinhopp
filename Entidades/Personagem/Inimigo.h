#include "Personagem.h"
#include "Jogador.h"

#include <time.h>

#include <cmath>

#define VELOCIDADE_INIMIGO_X 0.025f
#define VELOCIDADE_INIMIGO_Y 0.025f

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

using namespace sf;

class Inimigo : public Personagem
{   
    private:
        Jogador* jogador;
        Clock relogio;
        short moveAleatorio;
        void inicializa();
    public:
        Inimigo(const Vector2f pos, const Vector2f tam, Jogador* jogador);
        ~Inimigo();
        void persegueJogador(Vector2f posJogador, Vector2f posInimigo);
        void movimentoAleatorio();
        void move();      
};