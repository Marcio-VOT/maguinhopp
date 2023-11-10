#include "../Estados/Fases/Fase.h"

#include <fstream>
#include <string>
#include <iostream>

#define ARQUIVO_JOGADOR "./save/jogador.json"
#define ARQUIVO_INIMIGO "./save/inimigo.json"

namespace Estados
{
    namespace Fases
    {
        Fase::Fase(int i):
        jogadores(),
        obstaculos(),
        inimigos(),
        Estado(i)
        {
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);
            criarJogadores();
        }
        Fase::~Fase()
        {
            salvar();
        }

        void Fase::gerenciar_colisoes()
        {
            gC.colisao_simples();
        }
        void Fase::criarJogadores()
        {
            std::ifstream arquivo(ARQUIVO_JOGADOR);
            if (!arquivo)
            {
                jogadores.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Jogador2()));
                jogadores.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Jogador()));
                return;
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            for (auto it = json.begin(); it != json.end(); ++it)
            {
                switch (static_cast<IDs::IDs>((*it)["id"]))
                {
                case IDs::IDs::jgd1:
                    jogadores.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Jogador(
                    sf::Vector2f(
                        (float) ((*it)["posicao"][0]), 
                        (float) ((*it)["posicao"][1])
                                ),
                    sf::Vector2f(
                        (float) ((*it)["velocidade"][0]),
                        (float) ((*it)["velocidade"][1])
                                )
                    )));
                    break;
                case IDs::IDs::jgd2:
                    jogadores.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Jogador2(
                    sf::Vector2f(
                        (float) ((*it)["posicao"][0]), 
                        (float) ((*it)["posicao"][1])
                                ),
                    sf::Vector2f(
                        (float) ((*it)["velocidade"][0]),
                        (float) ((*it)["velocidade"][1])
                                )
                    )));
                    break;
                default:
                    break;
                }
                
            }
        }
        void Fase::criarInimMedios()
        {

        }
        void Fase::criarCenario(std::string caminho)
        {
            std::ifstream arquivo(caminho);
            if (!arquivo)
            {
                std::cout<<"Não foi possível acessar o arquivo de cenário."<<std::endl;
                exit(1);
            }
            std::string linha;
            
            Entidades::Entidade* aux = nullptr;

            int j = 0;
            for (int i = 0; std::getline(arquivo, linha); i++)
            {
                j = 0;
                for (char tipo : linha)
                {
                    switch (tipo)
                    {
                        // Plataforma:
                    case '0':
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Obst_Facil(sf::Vector2f(j * TAM, i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                    break;
                    
                    default:
                        break;
                    }
                    j++;
                }
            }
            arquivo.close();
        }
        void Fase::salvar(){
            // Salvando Jogadores:
            std::ofstream arquivo(ARQUIVO_JOGADOR);  
            if (!arquivo)
            {
                std::cout << "Problema em salvar o arquivo" << std::endl;
                exit(1);  
            }

            Listas::Lista<Entidades::Entidade>::Iterador j = jogadores.get_primeiro();
            buffer.str("");
            buffer << "[";
            if (j != nullptr)
            {
                Entidades::Entidade* aux = (*j);
                j++;
                if(j != nullptr){
                    (*j)->salvar(&buffer);
                    buffer << ",";
                }
                aux->salvar(&buffer);
            }
            // while (j != nullptr)
            // {
            //     buffer << ",";
            //     (*j)->salvar(&buffer);
            //     j++;
            // }
            buffer << "]";

            arquivo << buffer.str();

            arquivo.close();
            // // Salvando inimigos: 

            // std::ofstream arquivo_inimigo(ARQUIVO_INIMIGO);  
            // if (!arquivo_inimigo)
            // {
            //     std::cout << "Problema em salvar o arquivo" << std::endl;
            //     exit(1);
            // }

            // Listas::Lista<Entidades::Entidade>::Iterador i = inimigos.get_primeiro();
            // buffer.str("");
            // buffer << "[";
            // if (i != nullptr)
            // {
            //     (*i)->salvar(&buffer);
            //     i++;
            // }
            // while (i != nullptr)
            // {
            //     buffer << ",";
            //     (*i)->salvar(&buffer);
            //     i++;
            // }
            // buffer << "]";

        }
    }
}