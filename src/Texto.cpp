#include "../ElementosGraficos/Texto.h"

namespace ElementosGraficos{
  Gerenciadores::Gerenciador_Grafico* Texto::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());
  
  Texto::Texto(sf::Vector2f position, std::string info, const char* path): fonte(nullptr){
    this->info = info;
    getFonte(path);
    texto.setFont((*fonte));
    texto.setString(info);
    texto.setPosition(position);
    texto.setCharacterSize(20);
    texto.setFillColor(sf::Color::White);
  }

  Texto::~Texto(){
    if(fonte != nullptr)
      delete fonte;
  }

  void Texto::setTextoInfo(std::string info){
    this->info = info;
    texto.setString(info);
  }

  void Texto::setPosicao(sf::Vector2f position){
    texto.setPosition(position);
  }

  void Texto::getFonte(const char* path){
    fonte = pGG->getFonte(path);
  }

  void Texto::setCorTexto(const unsigned int R, const unsigned int G, const unsigned int B){
    texto.setFillColor(sf::Color(R, G, B));
  }
  void Texto::setCorTexto(sf::Color C){
    texto.setFillColor(C);
  }

  void Texto::setTamanhoFonte(const unsigned int size){
    texto.setCharacterSize(size);
  }

  void Texto::setAlinhamentodeTexto(AlinhamentodeTexto option){
    switch (option) {
      case esquerda:
        texto.setOrigin(0, 0);
        break;
      case centro:
        texto.setOrigin(texto.getLocalBounds().width / 2, 0);
        break;
      case direita:
        texto.setOrigin(texto.getLocalBounds().width, 0);
        break;
    }
  }

  sf::Vector2f Texto::getSize() const{
    return sf::Vector2f(texto.getLocalBounds().width, texto.getLocalBounds().height);
  }

  void Texto::desenha(){
    pGG->desenhar(&texto);
  }

  std::string Texto::getInfo() const{
    return info;
  }

  sf::Vector2f Texto::getPosicaon() const{
    return texto.getPosition();
  }

}