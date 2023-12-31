/*
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DO TUTOR Matheus Burda - https://github.com/MatheusBurda
    CÓDIGO ORIGINAL: https://github.com/MatheusBurda/Desert
    CÓDIGO FORTEMENTE INSPIRADO NO CÓDIGO DOS TUTORES  "Os petequeiros Jean e Murilo" - https://github.com/Nixxye -  https://utfpr.curitiba.br/peteco/
    Canal: https://www.youtube.com/@PETECOUTFPR
    CÓDIGO ORIGINAL: https://github.com/Nixxye/peteco-tegprog
*/
#pragma once

#include <SFML/Graphics.hpp>

#include "Gerenciadores/Gerenciador_Colisoes.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Gerenciadores/Gerenciador_Estados.h"
#include "Gerenciadores/Gerenciador_Eventos.h"
#include "Estados/Fases/FasePrimeira.h"
#include "Estados/Fases/Fase.h"
#include "Estados/Menus/Pausa.h"
#include "Estados/Menus/MenuPrincipal.h"
#include "Estados/Menus/MenuFases.h"

class Jogo
{
private:
    Gerenciadores::Gerenciador_Grafico* pGrafico;
    Gerenciadores::Gerenciador_Eventos* pEventos;
    Gerenciadores::Gerenciador_Estados* pEstados;
public:
    Jogo();
    ~Jogo();
    void executar();
};