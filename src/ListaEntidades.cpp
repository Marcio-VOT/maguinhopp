#include "../Listas/ListaEntidades.h"   
 #include <iostream>
namespace Listas
{
    ListaEntidades::ListaEntidades():
    LEs()
    {

    }
    ListaEntidades::~ListaEntidades()
    {

    }
    void ListaEntidades::incluir(Entidades::Entidade* pE)
    {
        LEs.incluir(pE);
    }
    const int ListaEntidades::get_tamanho() const
    {
        return LEs.get_tamanho();
    }
    void ListaEntidades::desenhar()
    {
        Lista<Entidades::Entidade>::Iterador aux = LEs.get_primeiro();
        while (aux != nullptr)
        {
            (*aux)->desenhar();
            aux++;
        }
    }
    void ListaEntidades::executar()
    {
        Lista<Entidades::Entidade>::Iterador aux = LEs.get_primeiro();
        while (aux != nullptr)
        {
            (*aux)->executar();
            aux++;
        }        
    }
    void ListaEntidades::remover_neutralizados()
    {
        Lista<Entidades::Entidade>::Iterador aux1 = LEs.get_primeiro(), aux2 = nullptr;
        while (aux1 != nullptr)
        {
            if ((*aux1)->neutralizado())
            {
                aux2 = aux1;
                aux2++;
                LEs.remover(aux1.get_atual());
                aux1 = aux2;
            }else{
            aux1++;
            }
        }
    }
    Lista<Entidades::Entidade>::Iterador ListaEntidades::get_primeiro()
    {
        return LEs.get_primeiro();
    }

}