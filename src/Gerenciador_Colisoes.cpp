#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include <math.h>
#include <iostream>

#define CR 0.2

namespace Gerenciadores
{
    Gerenciador_Colisoes::Gerenciador_Colisoes():
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
        Listas::Lista<Entidades::Entidade>::Iterador obst;
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
        Entidades::Entidade* jgd1 = (*jgd);
        while (jgd != nullptr)
        {
            obst = obstaculos->get_primeiro();
            while (obst != nullptr)
            {
                int col = colidiu(*jgd, *obst);
                if (col)
                {
                    (*jgd)->colidir((*obst));
                    (*obst)->colidir((*jgd));
                }
                obst++;
            }
            jgd++;
            if(jgd != nullptr){
                Entidades::Entidade* jgd2 = (*jgd);
                colidiu_janela(jgd1, jgd2);
            }
        }

        Listas::Lista<Entidades::Entidade>::Iterador inim = inimigos->get_primeiro();
        while (inim != nullptr)
        {
            obst = obstaculos->get_primeiro();
            while (obst != nullptr)
            {
                int col = colidiu(*inim, *obst);
                if (col)
                {
                    (*inim)->colidir((*obst));
                    (*obst)->colidir((*inim));
                }
                obst++;
            }
            inim++;
        }

        inim = inimigos->get_primeiro();
        jgd = jogadores->get_primeiro();
        while (inim != nullptr)
        {
            while (jgd != nullptr)
            {
                if (colidiu(*inim, *jgd))
                {
                    (*inim)->colidir(*jgd);
                    (*jgd)->colidir(*inim);
                }
                jgd++;
            }
            inim++;
        }

    }
    void Gerenciador_Colisoes::colidiu_janela(Entidades::Entidade* jgd1, Entidades::Entidade* jgd2){
        float difx = jgd1->getPosicao().x - jgd2->getPosicao().x;
        float dify = jgd1->getPosicao().y - jgd2->getPosicao().y;
        //joagdor 2 totalmente a esquerda da tela
        if(difx >= LARGURA_TELA/2){
            if(jgd1->getVelocidade().x > 0){
                jgd1->setPosicao(sf::Vector2f(jgd1->getPosicao().x - jgd1->getVelocidade().x, jgd1->getPosicao().y));
                jgd1->setVelocidade(sf::Vector2f(0, jgd1->getVelocidade().y));
            }
            if(jgd2->getVelocidade().x < 0){
                jgd2->setPosicao(sf::Vector2f(jgd2->getPosicao().x - jgd2->getVelocidade().x, jgd2->getPosicao().y));
                jgd2->setVelocidade(sf::Vector2f(-jgd2->getVelocidade().x * CR, jgd2->getVelocidade().y));
            }
        //joagdor 2 totalmente a direita da tela
        }else if((difx - 50) <= -LARGURA_TELA/2){
            if(jgd1->getVelocidade().x < 0){
                jgd1->setPosicao(sf::Vector2f(jgd1->getPosicao().x - jgd1->getVelocidade().x, jgd1->getPosicao().y));
                jgd1->setVelocidade(sf::Vector2f(0, jgd1->getVelocidade().y));
            }
            if(jgd2->getVelocidade().x > 0){
                jgd2->setPosicao(sf::Vector2f(jgd2->getPosicao().x - jgd2->getVelocidade().x, jgd2->getPosicao().y));
                jgd2->setVelocidade(sf::Vector2f(-jgd2->getVelocidade().x * CR, jgd2->getVelocidade().y));
            }
        }
       
    }
    int Gerenciador_Colisoes::colidiu(Entidades::Entidade* e1, Entidades::Entidade* e2)
    {
        sf::Vector2f pos1 = e1->getPosicao(), pos2 = e2->getPosicao(),
        tam1 = e1->getTamanho(), tam2 = e2->getTamanho(),
        d(
            fabs((pos1.x - pos2.x)) - ((tam1.x + tam2.x)/ 2.f),
            fabs((pos1.y - pos2.y)) - ((tam1.y + tam2.y)/ 2.f)
        );

        if (d.x < 0 && d.y < 0)
        {

            if (d.x < d.y)
            {
                if (pos1.y <= pos2.y)
                {
                    e1->setPosicao(sf::Vector2f(e1->getPosicao().x, e2->getPosicao().y - (tam1.y + tam2.y) / 2));
                    e1->setNochao(true);
                    e1->setVelocidade(sf::Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * CR));
                    return 4;
                }
                else
                {
                    e1->setPosicao(sf::Vector2f(e1->getPosicao().x, e2->getPosicao().y + (tam1.y + tam2.y) / 2));  
                    e1->setVelocidade(sf::Vector2f(e1->getVelocidade().x, -e1->getVelocidade().y * CR));
                    return 2;
                }
            }
            else
            {
                if (pos1.x >= pos2.x)
                {
                    e1->setPosicao(sf::Vector2f(e2->getPosicao().x + (tam1.x + tam2.x) / 2, e1->getPosicao().y));
                    e1->setVelocidade(sf::Vector2f(-e1->getVelocidade().x * CR, e1->getVelocidade().y));
                    return 1;

                }
                else
                {
                    e1->setPosicao(sf::Vector2f(e2->getPosicao().x - (tam1.x + tam2.x) / 2, e1->getPosicao().y));
                    e1->setVelocidade(sf::Vector2f(-e1->getVelocidade().x * CR, e1->getVelocidade().y));
                    return 3;
                }
            }
        }

        return 0;
    }

}