#pragma once

#include "../Gerenciadores/Gerenciador_Grafico.h"
#include "../Gerenciadores/Gerenciador_Entrada.h"
#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
    class Gerenciador_Eventos
    {
    private:
        Gerenciador_Grafico *pGrafico;
        Entrada *pGE;
        static Gerenciador_Eventos* instancia;
        Gerenciador_Eventos();
        sf::Event evento;
    public:
        ~Gerenciador_Eventos();
        void executar();     
        static Gerenciador_Eventos* get_instancia();
    };
}
