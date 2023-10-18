#include "Ente.h"

class Fase : public Ente
{
private:
public:
  Fase();
  ~Fase();
  virtual void executar() = 0;
  void gerenciar_colisoes();
  void criar_inimigos();
  void criar_obstaculos();
};
