#include "../ElementosGraficos/Botao.h"
#include <iostream>

namespace ElementosGraficos {

  Botao::Botao(sf::Vector2f posicao, std::string info):
  Elemento() 
  {
    body = sf::RectangleShape(sf::Vector2f(250, 50));
    body.setPosition(posicao);
    body.setFillColor(sf::Color::White);
    body.setOutlineColor(sf::Color::Black);
    body.setOutlineThickness(2);

    textoInfo = new Texto(posicao, info);
    textoInfo->setCorTexto(sf::Color::Black);
  }

  Botao::~Botao() {
  }

  void Botao::render() {
    Elemento::render();
    textoInfo->desenha();
  }

  void Botao::seleciona(const bool selecionado) {
    if (selecionado) {
      body.setFillColor(sf::Color::Black);
      textoInfo->setCorTexto(sf::Color::White);
    } else {
      body.setFillColor(sf::Color::White);
      textoInfo->setCorTexto(sf::Color::Black);
    }
  }

}