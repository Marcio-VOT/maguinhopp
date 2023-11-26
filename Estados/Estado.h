#pragma once

#include "../Gerenciadores/Gerenciador_Estados.h"

namespace Estados
{
    enum estadoID {
        vazio = -1,
        MenuPrincipal = 0,
        Fase1, // 1
        Fase2, // 2
        Jogando, // 3
        Pausa, // 4
        Configuracoes, // 5
        Placar, // 6
        FimDeJogo, // 7
    };
    class Estado
    {

    protected:
        const int id; 
        Gerenciadores::Gerenciador_Estados* pGE;
    public:
        Estado(int i = -1);
        virtual ~Estado();
        int get_id() const;
        virtual void executar () = 0;
        void mudarEstado (int i);
        virtual void resetaEstado() = 0;
        virtual void desenha() = 0;
        virtual void atualiza() {};

    };
}