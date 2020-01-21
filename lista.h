#include<iostream>
#include"nodo.h"
using namespace std;

template<typename T>

class Lista{
    protected:
    Nodo<T>* primero;
    public:
    Lista(){
        primero=NULL;
    }

    void crearLista();
    void insertarCabezaLista(T entrada);
    void visualizar();
    Nodo<T>* buscarLista(T);
    Nodo<T>* buscarPosicion(int);
    void eliminar(T entrada);
};

template<typename T>
void Lista<T>::crearLista(){
    int x;
    primero = 0;
    cout<<"Termina con -1"<<endl;
    do{
        cin>>x;
        if(x!=-1){
            primero=new Nodo<T>(x,primero);
        }
    } while(x!=-1);
}

template<typename T>
void Lista<T>::insertarCabezaLista(T entrada){
    Nodo<T>* nuevo;
    nuevo=new Nodo<T>(entrada);
    nuevo->ponerEnlace(primero);
    primero=nuevo;
}

template<typename T>
void Lista<T>::visualizar(){
    Nodo<T>* n;
    int k=0;
    n=primero;
    while(n!=NULL){
        char c;
        k++;
        c=(k%15!=0?' ':'\n');
        cout<<n->datoNodo()<<c;
        n=n->enlaceNodo();
    }
}

template<typename T>
Nodo<T>* Lista<T>::buscarLista(T destino){
    Nodo<T>* indice;
    for(indice = primero;indice!=NULL;indice=indice->enlaceNodo()){
        if(destino==indice->datoNodo()){
            return indice;
        }
    }
    return NULL;
}

template<typename T>
Nodo<T>* Lista<T>::buscarPosicion(int posicion){
    Nodo<T>* indice;
    int i;
    if(0>=posicion){
        return NULL;
    }

    indice =primero;
    for(i=1;(i<posicion)&&(indice!=NULL);i++){
        indice = indice->enlaceNodo();
    }
    return indice;
}

template<typename T>
void Lista<T>::eliminar(T entrada){
    Nodo<T> *actual, *anterior;
    bool encontrado;

    actual=primero;
    anterior=NULL;
    encontrado=false;
    while((actual!=NULL)&&!encontrado){
        encontrado=(actual->datoNodo()==entrada);
        if(!encontrado){
            anterior=actual;
            actual=actual->enlaceNodo();
        }
    }
    if(actual!=NULL){
        if(actual==primero){
            primero=actual->enlaceNodo();
        }
        else{
            anterior->ponerEnlace(actual->enlaceNodo());
        }
        delete actual;
    }
}