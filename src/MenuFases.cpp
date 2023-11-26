#include "../Estados/Menus/MenuFases.h"

namespace Estados {
    namespace Menus {
        
          MenuFases::MenuFases(Estados::Fases::Fase* plvl) :
          Menu(Estados::estadoID::MenuFases),
          plvl(plvl)
          {
            sf::Vector2u telaTam = pGG->get_Janela()->getSize();
            sf::Vector2f botaoTam(300, 50);
            ElementosGraficos::Botao* bt = nullptr;

            bt = new ElementosGraficos::Botao(sf::Vector2f(telaTam.x/2.f - botaoTam.x - 5, telaTam.y/2 - 60), "FASE 1");
            botoes.push_back(bt);
            bt = new ElementosGraficos::Botao(sf::Vector2f(telaTam.x/2.f - botaoTam.x - 5, telaTam.y/2 + 20), "FASE 2");
            botoes.push_back(bt);

            selecionado = 0;
            botoes[selecionado]->seleciona(true);
            std::cout << "MenuFases criado" << std::endl;
          }
  
          MenuFases::~MenuFases() {
          }
  
          void MenuFases::desenha() {
              atualizarCamera();
              for(int i = 0; i < botoes.size(); i++){
                botoes[i]->render();
              }
          }

          void MenuFases::executar() {
              if (ativo) {
                  ativo = false;
                  switch (selecionado)
                  {
                  case 0:
                      plvl->atualizaId(1);
                      plvl->inicializar();
                      plvl->setPrimeira(true);
                      mudarEstado(1);     
                      break;
                  case 1:
                      plvl->atualizaId(2);
                      plvl->inicializar();
                      plvl->setPrimeira(true);
                      mudarEstado(1);
                      break;
                  case -1:
                      ativo = true;
                      selecionado = 0;
                      botoes[selecionado]->seleciona(true);
                      break;
                  default:
                      break;
                  }
              }
          }

          void MenuFases::resetaEstado() {
              ativo = true;
              botoes[selecionado]->seleciona(false);
              selecionado = -1;
          }

    }
}