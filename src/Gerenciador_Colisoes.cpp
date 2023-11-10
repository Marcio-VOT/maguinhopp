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
        while (jgd != nullptr)
        {
            obst = obstaculos->get_primeiro();
            while (obst != nullptr)
            {
                if (colidiu(*jgd, *obst))
                {
                    (*jgd)->colidir();
                    (*obst)->colidir();
                }
                obst++;
            }
            jgd++;
        }
    }
    void Gerenciador_Colisoes::colidiu_janela(){
        Listas::Lista<Entidades::Entidade>::Iterador jgd = jogadores->get_primeiro();
        Entidades::Entidade* jgd1 = (*jgd);
        // sf::Vector2f pos1 = jgd1->getPosicao();
        // while (jgd != nullptr)
        // {
        //     if(difx >= LARGURA_TELA/2){
        //     jgd1->setVelocidade(sf::Vector2f(0, jgd1->getVelocidade().y));
        //     jgd2->setVelocidade(sf::Vector2f(0, jgd2->getVelocidade().y));
        //     if(jgd2->getPosicao().x < jgd1->getPosicao().x - LARGURA_TELA/2){
        //         jgd2->setPosicao(sf::Vector2f(jgd1->getPosicao().x - LARGURA_TELA/2, jgd2->getPosicao().y));
        //         }
        // }else if(difx <= -LARGURA_TELA/2){
        //     jgd1->setVelocidade(sf::Vector2f(0, jgd1->getVelocidade().y));
        //     jgd2->setVelocidade(sf::Vector2f(0, jgd2->getVelocidade().y));
        //     if(jgd2->getPosicao().x > jgd1->getPosicao().x + LARGURA_TELA/2){
        //         jgd2->setPosicao(sf::Vector2f(jgd1->getPosicao().x + LARGURA_TELA/2, jgd2->getPosicao().y));
        //     }
        // }
        // if(dify >= ALTURA_TELA/2){
        //     jgd1->setVelocidade(sf::Vector2f(0, jgd1->getVelocidade().y));
        //     jgd2->setVelocidade(sf::Vector2f(0, jgd2->getVelocidade().y));
        //     if(jgd2->getPosicao().y < jgd1->getPosicao().y - ALTURA_TELA/2){
        //         jgd2->setPosicao(sf::Vector2f(jgd2->getPosicao().x, jgd1->getPosicao().y - ALTURA_TELA/2));
        //     }
        // }else if(dify >= -ALTURA_TELA/2){
        //     jgd1->setVelocidade(sf::Vector2f(0, jgd1->getVelocidade().y));
        //     jgd2->setVelocidade(sf::Vector2f(0, jgd2->getVelocidade().y));
        //     if(jgd2->getPosicao().y > jgd1->getPosicao().y + ALTURA_TELA/2){
        //         jgd2->setPosicao(sf::Vector2f(jgd2->getPosicao().x, jgd1->getPosicao().y + ALTURA_TELA/2));
        //     }
        // }
            
        //    jgd++;
        // }
        
        jgd++;
        Entidades::Entidade* jgd2 = (*jgd);
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
                jgd2->setVelocidade(sf::Vector2f(0, jgd2->getVelocidade().y));
            }

            // jgd1->setPosicao(sf::Vector2f(jgd1->getPosicao().x -1 , jgd1->getPosicao().y));
            // jgd2->setPosicao(sf::Vector2f(jgd1->getPosicao().x - LARGURA_TELA/2, jgd2->getPosicao().y));
        
        //joagdor 2 totalmente a direita da tela
        }else if((difx - 50) <= -LARGURA_TELA/2){
            if(jgd1->getVelocidade().x < 0){
                jgd1->setPosicao(sf::Vector2f(jgd1->getPosicao().x - jgd1->getVelocidade().x, jgd1->getPosicao().y));
                jgd1->setVelocidade(sf::Vector2f(0, jgd1->getVelocidade().y));
            }
            if(jgd2->getVelocidade().x > 0){
                jgd2->setPosicao(sf::Vector2f(jgd2->getPosicao().x - jgd2->getVelocidade().x, jgd2->getPosicao().y));
                jgd2->setVelocidade(sf::Vector2f(0, jgd2->getVelocidade().y));
            }

            // jgd1->setPosicao(sf::Vector2f(jgd1->getPosicao().x +1 , jgd1->getPosicao().y));
            // jgd2->setPosicao(sf::Vector2f(jgd1->getPosicao().x + LARGURA_TELA/2 - 50, jgd2->getPosicao().y));
        }
        // if(dify >= ALTURA_TELA/2){
        //     jgd1->setVelocidade(sf::Vector2f(jgd1->getVelocidade().x, 0));
        //     jgd2->setVelocidade(sf::Vector2f(jgd2->getVelocidade().x, 0));
        //     if(jgd2->getPosicao().y < jgd1->getPosicao().y - ALTURA_TELA/2){
        //         jgd2->setPosicao(sf::Vector2f(jgd2->getPosicao().x, jgd1->getPosicao().y - ALTURA_TELA/2));
        //     }
        // }else if(dify <= -ALTURA_TELA/2){
        //     jgd1->setVelocidade(sf::Vector2f(jgd1->getVelocidade().x, 0));
        //     jgd2->setVelocidade(sf::Vector2f(jgd2->getVelocidade().x, 0));
        //     if(jgd2->getPosicao().y > jgd1->getPosicao().y + ALTURA_TELA/2){
        //         jgd2->setPosicao(sf::Vector2f(jgd2->getPosicao().x, jgd1->getPosicao().y + ALTURA_TELA/2));
        //     }
        // }
        // LARGURA_TELA
        // ALTURA_TELA
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