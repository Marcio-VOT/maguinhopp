#include "Gerenciadores/GerenciadorGafico.h"
#include "Entidades/Personagem/Jogador.h"


using namespace sf;

class GerenciadorEventos
{
private:
    GerenciadorGrafico* pGrafico;
    Jogador* pJogador;
    //Padrao Singleton
    static GerenciadorEventos* pEventos;
    GerenciadorEventos();
public:
    ~GerenciadorEventos();

    static GerenciadorEventos* getGerenciadorEventos();
    void setJogador(Jogador* pJogador);
    void verificaTeclaPressionada(Keyboard::Key tecla);
    void verificaTeclaSolta(Keyboard::Key tecla);
    void executar();
};

