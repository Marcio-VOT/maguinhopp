#include "../Estados/Menus/MenuPrincipal.h"

namespace Estados {
    namespace Menus {
        
          MenuPrincipal::MenuPrincipal(Estados::Fases::Fase* plvl) :
          Menu(Estados::estadoID::MenuPrincipal),
          plvl(plvl),
          titulo(),
          Jogador1(),
          Jogador2()
          {
            sf::Vector2u telaTam = pGG->get_Janela()->getSize();
            sf::Vector2f botaoTam(300, 50);
            ElementosGraficos::Botao* bt = nullptr;

            bt = new ElementosGraficos::Botao(sf::Vector2f(telaTam.x/2.f - botaoTam.x - 5, telaTam.y/2 - 60), "NOVO JOGO");
            botoes.push_back(bt);
            bt = new ElementosGraficos::Botao(sf::Vector2f(telaTam.x/2.f - botaoTam.x - 5, telaTam.y/2 + 20), "PLACAR");
            botoes.push_back(bt);
            bt = new ElementosGraficos::Botao(sf::Vector2f(telaTam.x/2.f + 5, telaTam.y/2 -60), "CARREGAR JOGO");
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

            Jogador1.setTextoInfo("Jogador1");
            Jogador1.setTamanhoFonte(25);
            Jogador1.setCorTexto(sf::Color::White);
            Jogador1.setAlinhamentodeTexto(ElementosGraficos::AlinhamentodeTexto::esquerda);
            Jogador1.setPosicao(sf::Vector2f(30, telaTam.y - 30));

            Jogador2.setTextoInfo(plvl->getQuantidadeJogadores() == 2 ? "Jogador2" : "J - para entrar");
            Jogador2.setTamanhoFonte(25);
            Jogador2.setCorTexto(plvl->getQuantidadeJogadores() == 2 ? sf::Color::White : sf::Color(211, 211, 211));
            Jogador2.setAlinhamentodeTexto(ElementosGraficos::AlinhamentodeTexto::esquerda);
            Jogador2.setPosicao(sf::Vector2f(telaTam.x - 30 - Jogador2.getSize().x, telaTam.y - 30));
            
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
              Jogador1.desenha();
              Jogador2.desenha();
          }

        void MenuPrincipal::setJogador2() {
            sf::Vector2u telaTam = pGG->get_Janela()->getSize();
            if(plvl->getQuantidadeJogadores() == 2){
                plvl->setQuantidadeJogadores(1);

            }else{
                plvl->setQuantidadeJogadores(2);
            }
            Jogador2.setTextoInfo(plvl->getQuantidadeJogadores() == 2 ? "Jogador2" : "J - para entrar");
            Jogador2.setCorTexto(plvl->getQuantidadeJogadores() == 2 ? sf::Color::White : sf::Color(211, 211, 211));
            Jogador2.setPosicao(sf::Vector2f(telaTam.x - 30 - Jogador2.getSize().x, telaTam.y - 30));
        }

          void MenuPrincipal::executar() {
              if (ativo) {
                  ativo = false;
                  switch (selecionado)
                  {
                  case 0:
                      mudarEstado(3);
                      break;
                  case 1:
                      mudarEstado(1);
                      break;
                  case 2:
                      mudarEstado(1);
                      break;
                  case 3:
                      pGG->get_Janela()->close();
                      break;
                  case -1:
                      ativo = true;
                      selecionado = 0;
                      botoes[selecionado]->seleciona(true);
                      break;
                  default:
                      break;
                  }
                  botoes[selecionado]->seleciona(false);
                  selecionado = 0;
                  botoes[selecionado]->seleciona(true);
              }
          }

          void MenuPrincipal::resetaEstado() {
              ativo = true;
              selecionado = -1;
          }

    }
}