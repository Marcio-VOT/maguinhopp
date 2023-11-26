#include "../Estados/Menus/Menu.h"

namespace Estados
{
    namespace Menus
    {
      Menu::Menu()
      {
        selecionado = 0;
        min = 0;
        max = 0;
        ativo = false;
      }

      Menu::~Menu(){
        ElementosGraficos::Botao* bt = NULL;
        while (botoes.size() != 0) {
            bt = botoes.back();
            delete (bt);
            botoes.pop_back();
        }
        botoes.clear();
      }

      void Menu::baixo()
      {
        if (ativo) {
            // botoes[selecionado]->seleciona(false);
            selecionado++;
            if (selecionado > max)
                selecionado = min;
            // botoes[selecionado]->seleciona(true);
        }
      }

      void Menu::cima()
      {
        if (ativo) {
            // botoes[selecionado]->seleciona(false);
            selecionado--;
            if (selecionado < min)
                selecionado = max;
            // botoes[selecionado]->seleciona(true);
        }
      }

      void Menu::atualizarCamera()
      {
        sf::Window* janela = pGG->get_Janela();
        if(pGG->get_JanelaAberta() && janela){
        pGG->centralizarCamera(sf::Vector2f(janela->getSize().x/2, janela->getSize().y/2));
        }
      };
      
    }

}
