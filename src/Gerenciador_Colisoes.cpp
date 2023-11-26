#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include <cmath>
#include <iostream>

#define CR 0.2

namespace Gerenciadores
{

    Gerenciador_Colisoes::Gerenciador_Colisoes() :
        obstaculos(nullptr),
        jogadores(nullptr),
        inimigos(nullptr)
    {

    }

    Gerenciador_Colisoes::~Gerenciador_Colisoes()
    {

    }

    void Gerenciador_Colisoes::colisao_simples()
{
    // Flag para verificar se está na parede (lateral)
    bool esta_na_parede = false;
    Listas::Lista<Entidades::Entidade>::Iterador obst;
    Listas::Lista<Entidades::Entidade>::Iterador inim;
    Listas::Lista<Entidades::Entidade>::Iterador jgd;


    // Iteração sobre inimigos e obstáculos
    for ( inim = inimigos->get_primeiro(); inim != nullptr; ++inim)
    {
        for ( obst = obstaculos->get_primeiro(); obst != nullptr; ++obst)
        {
            TipoColisao col = colidiu(*inim, *obst);

            if (col != Nenhuma)
            {
                // Realiza as ações de colisão
                colidir_entidade_movel_com_entidade_imovel((*inim), (*obst), col);
                (*inim)->colidir((*obst));
                (*obst)->colidir((*inim));

                // Marca se está na parede (lateral)
                if (col == Esquerda || col == Direita)
                    esta_na_parede = true;
            }
        }
    }

    // Iteração sobre inimigos e jogadores
    for ( inim = inimigos->get_primeiro(); inim != nullptr; ++inim)
    {
        for ( jgd = jogadores->get_primeiro(); jgd != nullptr; ++jgd)
        {
            // TipoColisao col = (esta_na_parede) ? colidiu(*jgd, *inim) : colidiu(*inim, *jgd);
            TipoColisao col = colidiu(*inim, *jgd);
            if(col == Esquerda || col == Direita) esta_na_parede = true;

            if (col != Nenhuma)
            {
                colidir_entidade_movel_com_entidade_movel((*inim), (*jgd), col);
                (*inim)->colidir(*jgd, col);
                (*jgd)->colidir(*inim, col);
            }
        }
    }

    // Iteração final sobre jogadores e obstáculos
    for ( jgd = jogadores->get_primeiro(); jgd != nullptr; ++jgd)
    {
        for ( obst = obstaculos->get_primeiro(); obst != nullptr; ++obst)
        {
            TipoColisao col = colidiu(*jgd, *obst);

            if (col != Nenhuma)
            {
                colidir_entidade_movel_com_entidade_imovel((*jgd), (*obst), col);
                (*jgd)->colidir((*obst), col);
                (*obst)->colidir((*jgd), col);
            }
        }
    }

    // Verificação final da colisão com a janela
    Entidades::Entidade* jgd1 = (*jogadores->get_primeiro());
    Listas::Lista<Entidades::Entidade>::Iterador jgd2;
    if (jogadores->get_tamanho() > 1)
    {
         jgd2 = jogadores->get_primeiro();
        ++jgd2; // Avança para o segundo jogador
        colidiu_janela(jgd1, (*jgd2));
    }
}

    void Gerenciador_Colisoes::colidiu_janela(Entidades::Entidade* jgd1, Entidades::Entidade* jgd2)
    {
        float difx = jgd1->getPosicao().x - jgd2->getPosicao().x;
        float dify = jgd1->getPosicao().y - jgd2->getPosicao().y;

        // Jogador 2 totalmente à esquerda da tela
        if (difx >= LARGURA_TELA / 2)
        {
            if (jgd1->getVelocidade().x > 0)
            {
                jgd1->setPosicao(sf::Vector2f(jgd1->getPosicao().x - jgd1->getVelocidade().x, jgd1->getPosicao().y));
                jgd1->setVelocidade(sf::Vector2f(0, jgd1->getVelocidade().y));
            }

            if (jgd2->getVelocidade().x < 0)
            {
                jgd2->setPosicao(sf::Vector2f(jgd2->getPosicao().x - jgd2->getVelocidade().x, jgd2->getPosicao().y));
                jgd2->setVelocidade(sf::Vector2f(-jgd2->getVelocidade().x * CR, jgd2->getVelocidade().y));
            }
        }
        // Jogador 2 totalmente à direita da tela
        else if ((difx - 50) <= -LARGURA_TELA / 2)
        {
            if (jgd1->getVelocidade().x < 0)
            {
                jgd1->setPosicao(sf::Vector2f(jgd1->getPosicao().x - jgd1->getVelocidade().x, jgd1->getPosicao().y));
                jgd1->setVelocidade(sf::Vector2f(0, jgd1->getVelocidade().y));
            }

            if (jgd2->getVelocidade().x > 0)
            {
                jgd2->setPosicao(sf::Vector2f(jgd2->getPosicao().x - jgd2->getVelocidade().x, jgd2->getPosicao().y));
                jgd2->setVelocidade(sf::Vector2f(-jgd2->getVelocidade().x * CR, jgd2->getVelocidade().y));
            }
        }
    }

    Gerenciador_Colisoes::TipoColisao Gerenciador_Colisoes::colidiu(Entidades::Entidade* e1, Entidades::Entidade* e2)
    {
        sf::Vector2f pos1 = e1->getPosicao();
        sf::Vector2f pos2 = e2->getPosicao();
        sf::Vector2f tam1 = e1->getTamanho() / 2.f;
        sf::Vector2f tam2 = e2->getTamanho() / 2.f; 

        sf::Vector2f diferenca = pos1 - pos2;
        sf::Vector2f sobreposicao = sf::Vector2f(
            fabs((pos1.x - pos2.x)) - (tam1.x + tam2.x),
            fabs((pos1.y - pos2.y)) - (tam1.y + tam2.y)
        );

        if (sobreposicao.x < 0 && sobreposicao.y < 0)
        {
            TipoColisao tipoColisao = (sobreposicao.x < sobreposicao.y) ?
                ((pos1.y <= pos2.y) ? Baixo : Cima) :
                ((pos1.x >= pos2.x) ? Esquerda : Direita);

            return tipoColisao;
        }

        return Nenhuma;
    }

    void Gerenciador_Colisoes::colidir_entidade_movel_com_entidade_imovel(Entidades::Entidade* entidadeMovel, Entidades::Entidade* entidadeImovel, TipoColisao tipoColisao)
    {
        // Larguras e alturas das entidades
        float larguraMovel = entidadeMovel->getTamanho().x;
        float alturaMovel = entidadeMovel->getTamanho().y;
        float larguraImovel = entidadeImovel->getTamanho().x;
        float alturaImovel = entidadeImovel->getTamanho().y;

        switch (tipoColisao)
        {
        case Baixo:
            entidadeMovel->setPosicao(sf::Vector2f(entidadeMovel->getPosicao().x, entidadeImovel->getPosicao().y - (alturaMovel + alturaImovel)/2.f));
            entidadeMovel->setNoChao(true);
            entidadeMovel->setVelocidade(sf::Vector2f(entidadeMovel->getVelocidade().x, 0));
            break;
        case Cima:
            entidadeMovel->setPosicao(sf::Vector2f(entidadeMovel->getPosicao().x, entidadeImovel->getPosicao().y + (alturaMovel + alturaImovel)/2.f));
            entidadeMovel->setVelocidade(sf::Vector2f(entidadeMovel->getVelocidade().x, -entidadeMovel->getVelocidade().y * CR));
            break;
        case Esquerda:
            entidadeMovel->setPosicao(sf::Vector2f(entidadeImovel->getPosicao().x + (larguraMovel + larguraImovel)/2.f, entidadeMovel->getPosicao().y));
            entidadeMovel->setVelocidade(sf::Vector2f(-entidadeMovel->getVelocidade().x * CR, entidadeMovel->getVelocidade().y));
            break;
        case Direita:
            entidadeMovel->setPosicao(sf::Vector2f(entidadeImovel->getPosicao().x - (larguraMovel + larguraImovel)/2.f, entidadeMovel->getPosicao().y));
            entidadeMovel->setVelocidade(sf::Vector2f(-entidadeMovel->getVelocidade().x * CR, entidadeMovel->getVelocidade().y));
            break;
        }
    }

    void Gerenciador_Colisoes::colidir_entidade_movel_com_entidade_movel(Entidades::Entidade* entidadeMovel1, Entidades::Entidade* entidadeMovel2, TipoColisao tipoColisao)
    {
        // Larguras e alturas das entidades
        float larguraMovel1 = entidadeMovel1->getTamanho().x;
        float alturaMovel1 = entidadeMovel1->getTamanho().y;
        float larguraMovel2 = entidadeMovel2->getTamanho().x;
        float alturaMovel2 = entidadeMovel2->getTamanho().y;
        float diferenca_x = fabs(larguraMovel1 - larguraMovel2);
        float diferenca_y = fabs(alturaMovel1 - alturaMovel2);

        switch (tipoColisao)
        {
        case Baixo:
        break;
        case Cima:
            if(entidadeMovel1->getNoChao()){
                entidadeMovel2->setPosicao(sf::Vector2f(entidadeMovel2->getPosicao().x, entidadeMovel2->getPosicao().y - diferenca_y/2.f));
                entidadeMovel2->setVelocidade(sf::Vector2f(entidadeMovel2->getVelocidade().x, -entidadeMovel2->getVelocidade().y * (CR + 0.3)));
            }else if(entidadeMovel2->getNoChao()){
                entidadeMovel1->setPosicao(sf::Vector2f(entidadeMovel1->getPosicao().x, entidadeMovel1->getPosicao().y - diferenca_y/2.f));
                entidadeMovel1->setVelocidade(sf::Vector2f(entidadeMovel1->getVelocidade().x, -entidadeMovel1->getVelocidade().y * (CR + 0.3)));
            }
        break;
        case Esquerda:
            entidadeMovel1->setPosicao(sf::Vector2f(entidadeMovel1->getPosicao().x + diferenca_x/4.f, entidadeMovel1->getPosicao().y));
            entidadeMovel2->setPosicao(sf::Vector2f(entidadeMovel2->getPosicao().x - diferenca_x/4.f, entidadeMovel2->getPosicao().y));

            entidadeMovel1->setVelocidade(sf::Vector2f(+diferenca_x/8.f, entidadeMovel1->getVelocidade().y));
            entidadeMovel2->setVelocidade(sf::Vector2f(-diferenca_x/8.f, entidadeMovel2->getVelocidade().y));
        break;
        case Direita:
            entidadeMovel1->setPosicao(sf::Vector2f(entidadeMovel1->getPosicao().x - diferenca_x/4.f, entidadeMovel1->getPosicao().y));
            entidadeMovel2->setPosicao(sf::Vector2f(entidadeMovel2->getPosicao().x + diferenca_x/4.f, entidadeMovel2->getPosicao().y));

            entidadeMovel1->setVelocidade(sf::Vector2f(-diferenca_x/8.f, entidadeMovel1->getVelocidade().y));
            entidadeMovel2->setVelocidade(sf::Vector2f(+diferenca_x/8.f, entidadeMovel2->getVelocidade().y));
        break;
        }
    }
}
