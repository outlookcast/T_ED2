#include <iostream>
#include <list>
#include "No.h"

using namespace std;

No::No()
{
    this->val = -1;
}

No::No(int val)
{
    this->val = val;
}

No::~No() {}

void No::setLista(list<int> lista)
{
    this->lista = lista;
}

void No::setVal(int val)
{
    this->val = val;
}

int No::getVal()
{
    return this->val;
}

list<int> No::getLista()
{
    return this->lista;
}

void No::insereNaLista(int val)
{
    this->lista.push_back(val);
}

void No::imprime()
{
    if(this->lista.size() == 0)
    {
        cout<<"Lista vazia!";
    }
    else
    {
        list<int> lst = this->lista;
        for (list<int>::iterator i = lst.begin(); i != lst.end(); ++i)
            cout << *i <<" ";
    }
}

void No::removeValorDaLista(int val)
{
    this->lista.remove(val);
}
