#include "../Gerenciadores/Gerenciador_Grafico.h"
#include "../Ente.h"

#include <iostream>

namespace Gerenciadores
{
    Gerenciador_Grafico* Gerenciador_Grafico::instancia(nullptr);

    Gerenciador_Grafico::Gerenciador_Grafico():
    janela(new sf::RenderWindow(sf::VideoMode(LARGURA_TELA, ALTURA_TELA), "MAGUINHO++")),
    camera(sf::Vector2f(LARGURA_TELA / 2.f, ALTURA_TELA / 2.f), sf::Vector2f(LARGURA_TELA, ALTURA_TELA)) // posição e tamanho
    {
        janela->setFramerateLimit(60);
        janela->setView(camera);
    }
    Gerenciador_Grafico::~Gerenciador_Grafico()
    {
        delete janela;
    }
    void Gerenciador_Grafico::desenharEnte(Ente *pE)
    {
        if (pE)
            janela->draw(*pE->get_corpo());
    }

    void Gerenciador_Grafico::desenhar(sf::Drawable *pD)
    {
        if (pD != nullptr){
            janela->draw(*pD);
        }
    }
    // Propaganda:
    void Gerenciador_Grafico::desenharTextura(sf::Texture* pT)
    {
        if (pT)
        {
            sf::Sprite sprite;
            sprite.setTexture(*pT);
            janela->draw(sprite);
        }
    }
    void Gerenciador_Grafico::carregarTextura(sf::Texture* pT, std::string caminho)
    {
        if (pT)
        {
            if (!pT->loadFromFile(caminho))
                std::cout << "Erro ao carregar textura: " << caminho << std::endl;
        }
    }
    const bool Gerenciador_Grafico::get_JanelaAberta() const
    {
        return janela->isOpen();
    }
    Gerenciador_Grafico *Gerenciador_Grafico::get_instancia()
    {
        if (!instancia)
            instancia = new Gerenciador_Grafico();
        return instancia;
    }
    void Gerenciador_Grafico::mostrar()
    {
        if (get_JanelaAberta())
            janela->display();
    }
    void Gerenciador_Grafico::limpar()
    {
        if (get_JanelaAberta())
            janela->clear(sf::Color(137, 207, 240));
    }
    void Gerenciador_Grafico::fecharJanela()
    {
        if (get_JanelaAberta())
            janela->close();       
    }
    sf::RenderWindow *Gerenciador_Grafico::get_Janela() const
    {
        return janela;
    }
    void Gerenciador_Grafico::resetarCamera()
    {
        camera.setCenter(sf::Vector2f(LARGURA_TELA / 2.f, ALTURA_TELA / 2.f));
        janela->setView(camera);
    }
    void Gerenciador_Grafico::centralizarCamera(sf::Vector2f p)
    {
        camera.setCenter(p);
        janela->setView(camera);        
    }
}

