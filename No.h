#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include <list>

using namespace std;

class No
{
private:
    int val;
    list<int> lista;

public:
    No(); /// Construtor padrão
    No(int val); /// Construtor inicializando val
    ~No();
    int getVal(); /// Retorna val
    list<int> getLista(); /// Retorna a lista
    void setVal(int val); /// Muda o valor de val
    void setLista(list<int> lista); /// Muda a lista
    void insereNaLista(int val); /// Insere a lista
    void imprime(); /// Imprime a lista de valores
    void removeValorDaLista(int val); /// Remove um item da lista
};

#endif // NO_H_INCLUDED
