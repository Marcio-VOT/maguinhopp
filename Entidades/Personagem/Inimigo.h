#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:
  int nivel_maldade;

public:
  Inimigo();
  ~Inimigo();
  virtual void executar();
  virtual void danificar(Jogador *jogador) = 0;
};
