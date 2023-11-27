/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DOS TUTORES  "Os petequeiros Jean e Murilo" - https://github.com/Nixxye -  https://utfpr.curitiba.br/peteco/
    Canal: https://www.youtube.com/@PETECOUTFPR
    CÓDIGO ORIGINAL: https://github.com/Nixxye/peteco-tegprog
*/
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
        float delay;
    public:
        ~Gerenciador_Eventos();
        void executar();     
        static Gerenciador_Eventos* get_instancia();
    };
}
