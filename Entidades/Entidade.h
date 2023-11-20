#pragma once

#include "../Ente.h"

// Largura e Altura padrão para as entidades
#define TAM 50.f

namespace Entidades
{
    class Entidade: public Ente
    {
    protected:
        sf::Vector2f velocidade;
        sf::Vector2f posicao;
        const int max_vel;
        bool nochao;

    public:
        Entidade(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), IDs::IDs id  = IDs::IDs::vazio, int max_vel = 5);
        ~Entidade();
        virtual void executar()=0;
        virtual void colidir(Entidade* outro, int side = -1);
        const sf::Vector2f getPosicao() const { return corpo.getPosition(); }
        const sf::Vector2f getTamanho() const { return corpo.getSize(); }
        void setPosicao(sf::Vector2f p);
        const sf::Vector2f getVelocidade () const { return velocidade; }
        const bool getNoChao() const { return nochao; }
        void setNoChao(bool n) { nochao = n; }
        const int getMaxVelocidade() const { return max_vel; }
        void setVelocidade(sf::Vector2f v);
        virtual void aplicaGravidade()
        {
            this->setVelocidade(this->getVelocidade() + sf::Vector2f(0, 0.1));
        };
        virtual void salvar(std::ostringstream* entrada)
        {
            Ente::salvar(entrada);
            (*entrada) << ", \"posicao\": [" << corpo.getPosition().x<<","<<corpo.getPosition().y<<"], \"velocidade\": ["<<velocidade.x<<","<<velocidade.y<<"]";
        }
    };
}