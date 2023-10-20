#pragma once

#define TELA_X 1800.0f
#define TELA_Y 920.0f

#include "Camera.h"

namespace Gerenciador
{

  class GerenciadorGrafico
  {
  private:
    sf::RenderWindow *window;

    // movimentar a camera
    Camera camera;
    sf::Clock relogio;
    static float tempo;

    // a construtora privada faz parte do padrão de projeto singleton
    static GerenciadorGrafico *pGrafico;
    GerenciadorGrafico();

  public:
    ~GerenciadorGrafico();
    static GerenciadorGrafico *getGerenciadorGrafico();
    sf::RenderWindow *getWindow();
    sf::Texture carregarTextura(const char *caminhoTextura);
    sf::Font carregarFonte(const char *caminhoFonte);
    void limpaJanela();
    void resetarRelogio();
    const float getTempo() const;
    void desenhaElemento(sf::RectangleShape corpo);
    void desenhaElemento(sf::Text texto);
    void mostraElementos();
    void fecharJanela();
    const bool verificaJanelaAberta();
    void atualizarCamera(const sf::Vector2f pos);
    void atualizarCamera(const sf::Vector2f pos, sf::Vector2f tam);
    const sf::View getCamera();
    void resetarJanela();
    const sf::Vector2f getTamJanela() const;
    void setLimiteCamera(const sf::IntRect limiteCamera);
    void setLimiteObjeto(const sf::IntRect objeto);
  };

}