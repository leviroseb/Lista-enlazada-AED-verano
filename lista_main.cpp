#include<iostream>
#include "lista.h"
using namespace std;



int main()
{
    int d,n,j;
    //Nodo<int>* p;
    Lista<int> lista;
    cout<<"Elementos de la lista, termina con -1"<<endl;
    do{
        cout<<"Ingrese un elemento: ";
        cin>>d;
        lista.insertarCabezaLista(d);
    } while(d!=-1);

    cout<<"\t Elementos de la lista generados al azar" <<endl;
    lista.visualizar();

    cout<<"Buscando un elemento: "<<endl;
    cout<<"Ingresa un numero buscado: ";
    cin>>n;
    cout<<lista.buscarLista(n);

    cout<<"Eliminar un nodo: ";
    cin>>j;
    lista.eliminar(j);
    lista.visualizar();
    return 0;
}