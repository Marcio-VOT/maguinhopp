#pragma once

#include "Movimentacao.h"

namespace Entidades {
  namespace Personagens{
    namespace Movimentacoes{
      class Slime_movimentacao : public Movimentacao {
        public:
          static Slime_movimentacao& getInstance(){
            static Slime_movimentacao instance;
            return instance;
          }

          void mover(Entidade* ente = nullptr);
          void aplicaGravidade(Entidade* ente = nullptr);
          
          private:
            Slime_movimentacao() {};
            Slime_movimentacao(const Slime_movimentacao&);
      };
    }
  }
}