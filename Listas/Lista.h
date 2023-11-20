#pragma once
#include <iostream>

namespace Listas
{
    template <class TL>
    class Lista
    {
    private:
        template <class TE>
        class Elemento
        {
        private:
            TE* pinfo;
            Elemento<TE>* pProx;
            Elemento<TE>* pAnt;

        public:
            Elemento() : pinfo(nullptr), pProx(nullptr), pAnt(nullptr) {}
            ~Elemento() {
                delete pinfo;
            }

            TE* get_pinfo() const { return pinfo; }
            Elemento<TE>* get_pProx() const { return pProx; }
            Elemento<TE>* get_pAnt() const { return pAnt; }

            void set_pinfo(TE* pi) { pinfo = pi; }
            void set_pProx(Elemento<TE>* pP) { pProx = pP; }
            void set_pAnt(Elemento<TE>* pA) { pAnt = pA; }
        };

    private:
        Elemento<TL>* pPrimeiro;
        int tamanho;

    public:
        Lista() : pPrimeiro(nullptr), tamanho(0) {}

        ~Lista() {
            limpar();
        }

        void limpar() {
            while (pPrimeiro) {
                Elemento<TL>* aux = pPrimeiro;
                pPrimeiro = pPrimeiro->get_pProx();
                delete aux;
            }
            tamanho = 0;
        }

        bool vazia() const {
            return tamanho == 0;
        }

        void remover(const Elemento<TL>* elem) {
            if (elem == nullptr || pPrimeiro == nullptr)
                return;

            Elemento<TL>* anterior = elem->get_pAnt();
            Elemento<TL>* proximo = elem->get_pProx();

            if (anterior != nullptr)
                anterior->set_pProx(proximo);
            else
                pPrimeiro = proximo;

            if (proximo != nullptr)
                proximo->set_pAnt(anterior);

            delete elem;

            tamanho--;
        }

        const int get_tamanho() const {
            return tamanho;
        }

        void incluir(TL* elem) {
            if (!elem)
                return;

            Elemento<TL>* novoElemento = new Elemento<TL>();
            novoElemento->set_pinfo(elem);

            if (pPrimeiro != nullptr) {
                pPrimeiro->set_pAnt(novoElemento);
            }

            novoElemento->set_pProx(pPrimeiro);
            pPrimeiro = novoElemento;
            tamanho++;
        }

        class Iterador
        {
        private:
            Elemento<TL>* atual;
            Lista<TL>* lista;

        public:
            Iterador(Elemento<TL>* a = nullptr, Lista<TL>* l = nullptr) : atual(a), lista(l) {}

            ~Iterador() {}

            Iterador& operator++() {
                if (atual != nullptr) {
                    atual = atual->get_pProx();

                    if (atual == nullptr) {
                        lista = nullptr;
                    }
                }
                return *this;
            }

            Iterador operator++(int) {
                Iterador temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const Elemento<TL>* outro) const {
                return atual == outro;
            }

            bool operator!=(const Elemento<TL>* outro) const {
                return !(atual == outro);
            }

            void operator=(const Elemento<TL>* outro) {
                atual = outro;
            }

            TL* operator*() {
                return (atual != nullptr && atual->get_pinfo() != nullptr) ? atual->get_pinfo() : nullptr;
            }

            const Elemento<TL>* get_atual() const {
                return atual;
            }
        };

        Iterador get_primeiro() {
            return Iterador(pPrimeiro, this);
        }

        void setPrimeiro(Elemento<TL>* primeiro) {
            pPrimeiro = primeiro;
        }

        void decrementarTamanho() {
            tamanho--;
        }

        TL* operator[](int index) {
            Elemento<TL>* current = pPrimeiro;
            for (int i = 0; i < index && current; ++i) {
                current = current->get_pProx();
            }
            if (current) {
                return current->get_pinfo();
            } else {
                // Pode ser apropriado lançar uma exceção ou retornar um valor padrão.
                return nullptr;
            }
        }

        void inserirNaPosicao(int posicao, TL* elem) {
            if (!elem || posicao < 0 || posicao > tamanho) {
                return;
            }

            Elemento<TL>* novoElemento = new Elemento<TL>();
            novoElemento->set_pinfo(elem);

            if (posicao == 0) {
                if (pPrimeiro != nullptr) {
                    pPrimeiro->set_pAnt(novoElemento);
                }
                novoElemento->set_pProx(pPrimeiro);
                pPrimeiro = novoElemento;
            } else {
                Elemento<TL>* current = pPrimeiro;
                for (int i = 0; i < posicao - 1; ++i) {
                    current = current->get_pProx();
                }

                novoElemento->set_pProx(current->get_pProx());
                novoElemento->set_pAnt(current);
                if (current->get_pProx() != nullptr) {
                    current->get_pProx()->set_pAnt(novoElemento);
                }
                current->set_pProx(novoElemento);
            }

            tamanho++;
        }
    };
}
