#pragma once

#include "Elemento.h"
#include "Texto.h"

namespace ElementosGraficos {

  class Botao : public Elemento {
    private:
      Texto* textoInfo;
      // sf::Texture* texuraPadrão;
      // sf::Texture* texuraSelecionado;
    public:
      Botao(sf::Vector2f posicao, std::string info);
      ~Botao();
      void render();
      void seleciona(const bool selecionado);
  };


}