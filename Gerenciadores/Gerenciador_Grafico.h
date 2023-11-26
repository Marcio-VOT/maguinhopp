#pragma once

#include <SFML/Graphics.hpp>

class Ente;

//Dimensões da janela
#define LARGURA_TELA 800.0
//Dimensões da janela
#define ALTURA_TELA 600.0


namespace Gerenciadores
{
    // Infraestrutura - SFML
    class Gerenciador_Grafico
    {
    private:
        sf::RenderWindow* janela;
        sf::View camera;
        Gerenciador_Grafico();
        static Gerenciador_Grafico* instancia;
    public:
        ~Gerenciador_Grafico();

        void desenharEnte(Ente* pE);
        void desenhar(sf::Drawable* pD);
        // create a getFonte method to get the font from a path and return it
        sf::Font* getFonte(const std::string& path) {
        sf::Font* fonte = new sf::Font();
        if (!fonte->loadFromFile(path)) {
            delete fonte;
            throw std::runtime_error("Não foi possível carregar a fonte: " + path);
        }
        return fonte;
        }   
        
        void desenharTextura(sf::Texture* pT);
        const bool get_JanelaAberta() const;
        static Gerenciador_Grafico* get_instancia();
        void mostrar();
        void limpar();
        void fecharJanela();
        void resetarCamera();
        void centralizarCamera(sf::Vector2f p);
        void carregarTextura(sf::Texture* pT, std::string caminho);
        sf::RenderWindow* get_Janela() const;
    };
}