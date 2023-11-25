#pragma once

#include "../Gerenciadores/Gerenciador_Estados.h"

namespace Estados
{
    class Estado
    {
    enum estadoID {
        vazio = -1,
        MenuPrincipal = 0,
        Fase1,
        Fase2,
        Jogando,
        Pausa,
        Configuracoes,
        Placar,
        FimDeJogo,
    };

    protected:
        const int id; 
        static Gerenciadores::Gerenciador_Estados* pGE;
    public:
        Estado(int i = -1);
        virtual ~Estado();
        int get_id() const;
        virtual void executar () = 0;
        void mudarEstado (int i);
    };
}