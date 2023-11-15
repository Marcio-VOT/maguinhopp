#pragma once

#include "../../Entidade.h"
namespace Entidades {
  namespace Personagens{
    namespace Movimentacoes{  
      class Movimentacao {
        public:
          virtual void aplicaGravidade(Entidade* ente = nullptr) = 0;
          virtual void mover(Entidade* ente = nullptr) = 0;
      };
    }
  }
}