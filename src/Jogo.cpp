#include "../Jogo.h"
#include <iostream>

Jogo::Jogo():
pGrafico(Gerenciadores::Gerenciador_Grafico::get_instancia()),
pEventos(Gerenciadores::Gerenciador_Eventos::get_instancia()),
pEstados(Gerenciadores::Gerenciador_Estados::get_instancia())
{
    Estados::Fases::Fase* fase1 = new Estados::Fases::FasePrimeira();
    Estados::Fases::Fase* fase2 = new Estados::Fases::FasePrimeira(2);
    new Estados::Menus::Pausa(fase1);
    std::cout << "MenuPrincipal criando" << std::endl;
    new Estados::Menus::MenuPrincipal(fase1);
    std::cout << "MenuPrincipal criando" << std::endl;

    executar();
}

Jogo::~Jogo()
{
    delete pGrafico;
    delete pEventos;
    delete pEstados;
}

void Jogo::executar()
{
    while (pGrafico->get_JanelaAberta())
    {
        pGrafico->limpar();
        pEventos->executar();
        pEstados->executar();
        pGrafico->mostrar();
    }
}