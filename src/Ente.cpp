#include "../Ente.h"
#include <iostream>

Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::get_instancia());


Ente::Ente(sf::Vector2f tam, IDs::IDs id):
id(id),
corpo(tam)
{
}

Ente::~Ente()
{

}

void Ente::desenhar()
{
  pGG->desenharEnte(this);
}

const sf::RectangleShape* Ente::get_corpo() const
{
  return &corpo;
}

const sf::Texture* Ente::get_textura() const
{
  return &textura;
}

const void Ente::set_textura()
{
  if(&textura == nullptr){
    std::cout << "Erro ao setar textura, textura não foi encontrada" << std::endl;
    exit(1);
  }
  else
    corpo.setTexture(&textura, true);
}
const void Ente::set_inv_textura()
{
  if(&invTextura == nullptr){
    std::cout << "Erro ao setar textura, textura não foi encontrada" << std::endl;
    exit(1);
  }
  else
    corpo.setTexture(&invTextura, true);
}


const void Ente::load_textura(const std::string& caminho)
{
  pGG->carregarTextura(&textura, caminho);
  // sf::Image img = textura.copyToImage();
  // img.flipHorizontally();
  // std::string key = std::to_string(static_cast<int>(id));
  // img.saveToFile("public/assets/Jogadores/" + key + "_inv.png");
}
const void Ente::load_inv_textura(const std::string& caminho)
{
  pGG->carregarTextura(&invTextura, caminho);
}

const void Ente::set_and_load_textura(const std::string& caminho, const std::string& invCaminho)
{
  if(caminho == ""){
    std::cout << "Erro ao setar textura" << std::endl;
    exit(1);
  }else
    load_textura(caminho);

  if(invCaminho != ""){
    std::cout << "Carregando textura invertida" << invCaminho << std::endl;
    load_inv_textura(invCaminho );
  }
  else
    load_inv_textura(caminho);
  
  set_textura();
}