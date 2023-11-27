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
        Fase::Fase(int i, int quantidadeJogadores):
        jogadores(),
        obstaculos(),
        inimigos(),
        Estado(i),
        fimDeJogo(true),
        quantidadeJogadores(quantidadeJogadores),
        pontosFase(0)
        {
            gC.set_inimigos(&inimigos);
            gC.set_jogadores(&jogadores);
            gC.set_obstaculos(&obstaculos);
        }
        Fase::~Fase()
        {
            salvar();
        }

        void Fase::removeNeutralizados()
        {
            jogadores.remover_neutralizados();
            inimigos.remover_neutralizados();
            obstaculos.remover_neutralizados();
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
                std::cout << "Arquivo não existe - players" << std::endl;
                return;
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);
            Entidades::Personagens::Jogador* jogador1 = nullptr;
            Entidades::Personagens::Jogador* jogador2 = nullptr;
            for (auto it = json.begin(); it != json.end(); ++it)
            {
                switch (static_cast<IDs::IDs>((*it)["id"]))
                {
                case IDs::IDs::jgd1:
                    jogador1 = new Entidades::Personagens::Jogador(
                    sf::Vector2f(
                        (float) ((*it)["posicao"][0]), 
                        (float) ((*it)["posicao"][1])
                                ),
                    sf::Vector2f(
                        (float) ((*it)["velocidade"][0]),
                        (float) ((*it)["velocidade"][1])
                                )
                    );
                    jogador1->updatePlayerId(IDs::IDs::jgd1);
                    jogadores.incluir(static_cast<Entidades::Entidade*>(jogador1));
                    break;
                case IDs::IDs::jgd2:
                    jogador2 = new Entidades::Personagens::Jogador(
                    sf::Vector2f(
                        (float) ((*it)["posicao"][0]), 
                        (float) ((*it)["posicao"][1])
                                ),
                    sf::Vector2f(
                        (float) ((*it)["velocidade"][0]),
                        (float) ((*it)["velocidade"][1])
                                )
                    );
                    jogador2->updatePlayerId(IDs::IDs::jgd2);
                    jogadores.incluir(static_cast<Entidades::Entidade*>(jogador2));
                    break;
                default:
                    break;
                }
                
            }
        }
        void Fase::criarInimigos()
        {
            std::ifstream arquivo(ARQUIVO_INIMIGO);
            if (!arquivo)
            {
                std::cout << "Arquivo não existe - inimigos" << std::endl;   
                return;
            }

            nlohmann::json json = nlohmann::json::parse(arquivo);

            for (auto it = json.begin(); it != json.end(); ++it)
            {
                inimigos.incluir(static_cast<Entidades::Entidade*>(new Entidades::Personagens::Gosma_Verde(
                    sf::Vector2f(
                        (float) ((*it)["posicao"][0]), 
                        (float) ((*it)["posicao"][1])
                                ),
                    sf::Vector2f(
                        (float) ((*it)["velocidade"][0]),
                        (float) ((*it)["velocidade"][1])
                                )
                    )));
            }
            arquivo.close();
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

            bool inicializado = jogadores.get_tamanho() > 0 || inimigos.get_tamanho() > 0;

            int j = 0;
            int t = 0, n = 0, p = 0, r = 0, g = 0;
            for (int i = 0; std::getline(arquivo, linha); i++)
            {
                j = 0;
                for (char tipo : linha)
                {
                
                char tipoPlat;
                int randNum = rand() % 3; // Gera um número aleatório entre 0 e 2

                switch(randNum) {
                    case 0:
                        tipoPlat = 'p';
                        break;
                    case 1:
                        tipoPlat = 'm';
                        break;
                    case 2:
                        tipoPlat = 'g';
                        break;
                }

                    switch (tipo)
                    {
                    case '0':    
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Obst_Facil(sf::Vector2f(j * TAM + (TAM), i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                    break;
                    case 't':    
                        if(t < 3 || rand() % 2 == 0){
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Tabua(sf::Vector2f(j * TAM + (TAM), i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                        t++;
                        }else{
                            aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Obst_Facil(sf::Vector2f(j * TAM + (TAM), i * TAM)));
                            if (aux)
                                obstaculos.incluir(aux);
                        }
                    break;
                    case '-':    
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Neutralizador(sf::Vector2f(j * TAM + (TAM), i * TAM)));
                        if (aux)
                            obstaculos.incluir(aux);
                    break;
                    case '+':    
                        if(n < 3 || rand() % 2 == 0){
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Neutralizador(sf::Vector2f(j * TAM + (TAM), i * TAM), false));
                        if (aux)
                            obstaculos.incluir(aux);
                        n++;
                        }
                    break;
                    case 'p':
                        if(p < 3 || rand() % 2 == 0){
                        aux = static_cast<Entidades::Entidade*> (new Entidades::Obstaculos::Plataforma(sf::Vector2f(j * TAM + (TAM), i * TAM), tipoPlat));
                        if (aux)
                            obstaculos.incluir(aux);
                        p++;
                        }
                    break;
                    case '1':
                        if(!inicializado){
                        Entidades::Personagens::Jogador* jgd = new Entidades::Personagens::Jogador(sf::Vector2f(j * TAM , i * TAM), sf::Vector2f(0,0));
                        aux = static_cast<Entidades::Entidade*>(jgd);
                        if (aux){
                            jgd->updatePlayerId(IDs::IDs::jgd1);
                            jogadores.incluir(aux);
                        };
                        }
                    break;
                    case '2':
                    if(!inicializado && quantidadeJogadores == 2){
                        Entidades::Personagens::Jogador* jgd = new Entidades::Personagens::Jogador(sf::Vector2f(j * TAM , i * TAM), sf::Vector2f(0,0));
                        aux = static_cast<Entidades::Entidade*>(jgd);
                        if (aux){
                            jgd->updatePlayerId(IDs::IDs::jgd2);
                            jogadores.incluir(aux);
                        };
                    }
                    break;
                    case 'r':
                        if(!inicializado){
                            if(r < 3 || rand() % 2 == 0){
                                aux = static_cast<Entidades::Entidade*>(new Entidades::Personagens::Gosma_Nuclear(sf::Vector2f(j * TAM, i * TAM), sf::Vector2f(0,0)));
                                if (aux)
                                    inimigos.incluir(aux);
                                r++;
                            }
                        }
                    break;
                    case 'g':
                        if(!inicializado){
                            if(g < 3 || rand() % 2 == 0){
                                aux = static_cast<Entidades::Entidade*>(new Entidades::Personagens::Gosma_Verde(sf::Vector2f(j * TAM, i * TAM), sf::Vector2f(0,0)));
                                if (aux)
                                    inimigos.incluir(aux);
                                g++;
                            }
                        }
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