#include "../Estados/Menus/Menu.h"

namespace Estados
{
    namespace Menus
    {

      Menu::Menu(int id):
      Estado(id),
      pGG(Gerenciadores::Gerenciador_Grafico::get_instancia()),
      selecionado(0),
      control(this),
      ativo(false)
      {
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
        if(selecionado < 0){
          selecionado = 0;
        }
        if ( ativo ) {
            botoes[selecionado]->seleciona(false);
            selecionado++;
            selecionado = selecionado % botoes.size();
            botoes[selecionado]->seleciona(true);
        }
      }

      void Menu::cima()
      {
        if(selecionado < 0){
          selecionado = 0;
        }
        if (ativo ) {
            botoes[selecionado]->seleciona(false);
              selecionado--;
            if(selecionado < 0)
              selecionado = botoes.size()-1;
            
            selecionado = selecionado % botoes.size();
            botoes[selecionado]->seleciona(true);
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
