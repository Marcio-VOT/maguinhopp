#pragma once

#include "Movimentacao.h"

namespace Entidades {
  namespace Personagens{
    namespace Movimentacoes{
      class Jogador1_movimentacao : public Movimentacao {
        public:
          static Jogador1_movimentacao& getInstance(){
            static Jogador1_movimentacao instance;
            return instance;
          }

          void mover(Entidade* ente = nullptr);
          void aplicaGravidade(Entidade* ente = nullptr);
        private:
          Jogador1_movimentacao() {};
          Jogador1_movimentacao(const Jogador1_movimentacao&);

      };
    }
  }
}