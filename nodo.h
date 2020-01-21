#include<iostream>
using namespace std;
template<typename T>

class Nodo
{
    protected:
    T dato;
    Nodo<T>* enlace;
    public:
    Nodo(T _dato){
        dato=_dato;
        enlace = 0;
    }
    Nodo(T _dato, Nodo<T>* n){
        dato=_dato;
        enlace=n;
    }

    T datoNodo() const{
        return dato;
    }

    Nodo<T>* enlaceNodo() const{
        return enlace;
    }

    void ponerEnlace(Nodo<T>* sgte){
        enlace=sgte;
    }
};
