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