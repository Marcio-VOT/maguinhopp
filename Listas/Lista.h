#pragma once

namespace Listas
{
    template<class TL>
    class Lista
    {
    private:
        // Classe aninhada privada
        template <class TE>
        class Elemento
        {
        private:
            TE* pinfo;
            Elemento<TE>* pProx;
            Elemento<TE>* pAnt; 

        public:
            Elemento():
            pinfo(nullptr),
            pProx(nullptr),
            pAnt(nullptr)
            {

            }
            ~Elemento()
            {
                if (pinfo)
                    delete pinfo;
                pProx = nullptr;
                pAnt = nullptr; 
            }
            TE* get_pinfo() const { return pinfo; }
            Elemento<TE>* get_pProx() { return pProx; }
            Elemento<TE>* get_pAnt() { return pAnt; } 

            void set_pinfo(TE* pi) { if (pi) { pinfo = pi; } }
            void set_pProx(Elemento<TE>* pP) { if (pP) { pProx = pP; } } 
            void set_pAnt(Elemento<TE>* pA) { if (pA) { pAnt = pA; } } 
        };
        private:
            Elemento<TL>* pPrimeiro;
            int tamanho;
        public:
            Lista():
            pPrimeiro(nullptr),
            tamanho(0)
            {

            }
            ~Lista()
            {
                limpar();
            }
            void limpar()
            {
                Elemento<TL>* aux = nullptr;
                while(pPrimeiro)
                {
                    aux = pPrimeiro;
                    pPrimeiro = pPrimeiro->get_pProx();
                    if (aux)
                        delete aux;
                }
                tamanho = 0;
                pPrimeiro = nullptr;
            }
            void remover(const Elemento<TL>* elem)
            {
                if (!elem || !pPrimeiro)
                    return;

                Elemento<TL>* atual = pPrimeiro;
                Elemento<TL>* anterior = nullptr;

                while (atual != nullptr && !(atual->get_pinfo() == elem->get_pinfo())) {
                    anterior = atual;
                    atual = atual->get_pProx();
                }

                if (atual == nullptr) {
                    // Elemento não encontrado
                    return;
                }

                if (anterior == nullptr) {
                    // Remover o primeiro elemento
                    pPrimeiro = atual->get_pProx();
                    if (pPrimeiro) {
                        pPrimeiro->set_pAnt(nullptr);
                    }
                } else {
                    // Remover um elemento que não é o primeiro
                    anterior->set_pProx(atual->get_pProx());
                    if (atual->get_pProx()) {
                        atual->get_pProx()->set_pAnt(anterior);
                    }
                }

                delete atual;
                tamanho--;
                return;
            }
            const int get_tamanho() const
            {
                return tamanho;
            }
            void incluir(TL* elem)
            {
                if (!elem)
                    return;
                Elemento<TL>* aux = new Elemento<TL>();
                if (aux)
                {
                    aux->set_pinfo(elem);
                    if (pPrimeiro != nullptr) {
                        pPrimeiro->set_pAnt(aux);
                    }
                    aux->set_pProx(pPrimeiro);
                    pPrimeiro = aux;
                    tamanho++;
                }
            }
            // Classe aninhada pública:
            class Iterador
            {
            private:
                Elemento<TL>* atual;
            public:
                Iterador(Elemento<TL>* a = nullptr):
                atual(a)
                {

                }
                ~Iterador()
                {
                    atual = nullptr;
                }
                Iterador& operator++()
                {
                    atual = atual->get_pProx();
                    return *this;
                }
                Iterador& operator++(int)
                {
                    atual = atual->get_pProx();
                    return *this;
                }
                bool operator==(const Elemento<TL>* outro) const
                {
                    return atual == outro;
                }
                Iterador& operator--()
                {
                    if (atual != nullptr) {
                        atual = atual->get_pAnt();
                    }
                    return *this;
                }
                Iterador& operator--(int)
                {
                    if (atual != nullptr) {
                        atual = atual->get_pAnt();
                    }
                    return *this;
                }
                bool operator!=(const Elemento<TL>* outro) const
                {
                    return !(atual == outro);
                }
                void operator=(const Elemento<TL>* outro)
                {
                    atual = outro;
                }
                TL* operator*()
                {
                    return atual->get_pinfo();
                }
                const Elemento<TL>* get_atual() const
                {
                    return atual;
                }
            };
            Iterador get_primeiro()
            {
                return Iterador(pPrimeiro);
            }
    };
}