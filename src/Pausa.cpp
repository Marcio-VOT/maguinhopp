#include "../Estados/Menus/Pausa.h"

namespace Estados {
    namespace Menus {
        Pausa::Pausa(Estados::Fases::Fase* plvl) :
        Menu(Estados::estadoID::Pausa),
        plvl(plvl) {
            sf::Vector2u telaTam = pGG->get_Janela()->getSize();
            ElementosGraficos::Botao* bt = nullptr;
            bt = new ElementosGraficos::Botao(sf::Vector2f(30, telaTam.y/5 - 65), "CONTINUAR JOGO");
            botoes.push_back(bt);
            bt = new ElementosGraficos::Botao(sf::Vector2f(30, telaTam.y/5), "CONFIGURACOES");
            botoes.push_back(bt);
            bt = new ElementosGraficos::Botao(sf::Vector2f(30, telaTam.y/5 + 65), "SAIR DO JOGO");
            botoes.push_back(bt);
            selecionado = 0;
            botoes[selecionado]->seleciona(true);
        }

        Pausa::~Pausa() { }

        void Pausa::desenha() {
          atualizarCamera();
            for(int i = 0; i < botoes.size(); i++){
                botoes[i]->render();
            }
    
        }

        void Pausa::executar() {
            if (ativo) {
              ativo = false;
              switch (selecionado)
              {
              case 0:
                mudarEstado(1);
                break;
            case 1:
                mudarEstado(1);
                // mudarEstado(Estados::estadoID::Configuracoes);
                break;
            case 2:
                plvl->terminar();
                mudarEstado(0);
                // mudarEstado(Estados::estadoID::MenuPrincipal);
                // plvl->endLevel();
                break;
              default:
                break;
              }
            }
        }

        void Pausa::resetaEstado() {
            for(it = botoes.begin(); it != botoes.end(); it++)
                (*it)->seleciona(false);
            selecionado = 0;
            botoes[selecionado]->seleciona(true);
            ativo = true;
        }

        void Pausa::AtivaMenuPausa() {

            if(pGE->getEstadoAtual_id() == static_cast<int>(Estados::estadoID::Fase1) || pGE->getEstadoAtual_id() == static_cast<int>(Estados::estadoID::Fase2)){
            mudarEstado(Estados::estadoID::Pausa);
            }
        }
    }
}