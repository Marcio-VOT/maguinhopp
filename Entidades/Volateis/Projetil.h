#pragma once

#include "Entidade.h"

namespace Entidades
{
    class Projetil : public Entidade
    {
    private:
    public:
        Projetil();
        ~Projetil();
        void executar();
    };
}