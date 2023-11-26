#include "../Estados/Menus/MenuPrincipal.h"

namespace Estados {
    namespace Menus {
        
          MenuPrincipal::MenuPrincipal(Estados::Fases::Fase* plvl) :
          Menu(Estados::estadoID::MenuPrincipal),
          plvl(plvl),
          titulo()
          {
            sf::Vector2u telaTam = pGG->get_Janela()->getSize();
            sf::Vector2f botaoTam(300, 50);
            ElementosGraficos::Botao* bt = nullptr;

            bt = new ElementosGraficos::Botao(sf::Vector2f(telaTam.x/2.f - botaoTam.x - 5, telaTam.y/2 - 60), "NOVO JOGO");
            botoes.push_back(bt);
            bt = new ElementosGraficos::Botao(sf::Vector2f(telaTam.x/2.f - botaoTam.x - 5, telaTam.y/2 + 20), "PLACAR");
            botoes.push_back(bt);
            bt = new ElementosGraficos::Botao(sf::Vector2f(telaTam.x/2.f + 5, telaTam.y/2 -60), "CONFIGURACÕES");
            botoes.push_back(bt);
            bt = new ElementosGraficos::Botao(sf::Vector2f(telaTam.x/2.f + 5, telaTam.y/2 + 20), "SAIR DO JOGO");
            botoes.push_back(bt);

            selecionado = 0;
            botoes[selecionado]->seleciona(true);

            titulo.setTextoInfo("MAGUINHO++");
            titulo.setTamanhoFonte(80);
            titulo.setCorTexto(sf::Color(77.6, 68.2, 44.3));
            titulo.setAlinhamentodeTexto(ElementosGraficos::AlinhamentodeTexto::centro);

            titulo.setPosicao(sf::Vector2f(telaTam.x/2.f, telaTam.y/2 - 200));

            std::cout << "MenuPrincipal criado" << std::endl;
            ativo = true;
          }
  
          MenuPrincipal::~MenuPrincipal() {
          }
  
          void MenuPrincipal::desenha() {
              atualizarCamera();
              for(int i = 0; i < botoes.size(); i++){
                botoes[i]->render();
              }
              titulo.desenha();
          }

          void MenuPrincipal::executar() {
              if (ativo) {
                  ativo = false;
                  switch (selecionado)
                  {
                  case 0:
                      mudarEstado(1);
                      break;
                  case 1:
                      mudarEstado(1);
                      break;
                  case 2:
                      mudarEstado(1);
                      break;
                  case 3:
                      mudarEstado(1);
                      break;
                  default:
                      break;
                  }
              }
          }

          void MenuPrincipal::resetaEstado() {
              ativo = true;
              selecionado = 0;
              botoes[selecionado]->seleciona(true);
          }

    }
}