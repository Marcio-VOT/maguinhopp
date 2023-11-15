#pragma once

#include "Movimentacao.h"

namespace Entidades {
  namespace Personagens{
    namespace Movimentacoes{
      class Jogador2_movimentacao : public Movimentacao {
        public:
          static Jogador2_movimentacao& getInstance(){
            static Jogador2_movimentacao instance;
            return instance;
          }

          void mover(Entidade* ente = nullptr);
          void aplicaGravidade(Entidade* ente = nullptr);
          
          private:
            Jogador2_movimentacao() {};
            Jogador2_movimentacao(const Jogador2_movimentacao&);
      };
    }
  }
}