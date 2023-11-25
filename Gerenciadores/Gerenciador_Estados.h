#pragma once

#include <map>
#include <stdlib.h>

namespace Estados
{
    class Estado;
}
/*
Estados:
0 - Menu Principal
1 - Fase 1
*/

namespace Gerenciadores
{
    class Gerenciador_Estados
    {
    private:
        int estadoAtual;
        int ultimoEstado;
        std::map<int, Estados::Estado*> estados;
        static Gerenciador_Estados* instancia;
        
        Gerenciador_Estados();
    public:
        ~Gerenciador_Estados();
        
        static Gerenciador_Estados* get_instancia();
        void setEstadoAtual (int i) ;
        void atualizaEstadoAtual (){};
        void exibeEstadoAtual (){};
        int getEstadoAtual_id () const { return estadoAtual; }
        void addEstado (Estados::Estado* pEstado);
        int getUltimoEstado_id () const { return ultimoEstado; }
        void executar();
    };
}