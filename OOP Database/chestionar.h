#include <iostream>
#include <string.h>
#include "farmacieOnline.h"

using namespace std;

template <class T>
class chestionar
{
    T* *lista;
    int nr;


public:
    chestionar();
    chestionar(int);
    ~chestionar();

    void display();
    void add(T);
    void sterg(int);
    void afis(int);
    void angajat(int);
    void marire(int);
    int getNr();
    void vizit(int);
    T getFarmacie(int);



};

template <class T>
T chestionar<T>::getFarmacie(int x)
{
    return *(lista[x]);
}


template <class T>
void chestionar<T>::vizit(int x)
{
    lista[x]->vizite();
}

template <class T>
chestionar<T>::getNr()
{
    return nr;
}

template <class T>
chestionar<T>::chestionar()
{

    *lista = new T;
    nr = 1;
}

template <class T>
chestionar<T>::chestionar(int n)
{
    nr = n;
    lista = new T*[n];
    for (int i=0;i<n;++i)
        lista[i]=new T;
}

template <class T>
chestionar<T>::~chestionar()
{
    for (int i=0;i<nr;++i)
        delete lista[i];
    delete[] lista;
}

template <class T>
void chestionar<T>::display()
{
    cout<<"Lista farmacii:"<<endl;
    for(int i = 1 ; i < nr ; i++)
    {   cout<<i<<":"<<endl;
        lista[i]->display();
        cout<<endl;
    }

}

template <class T>
void chestionar<T>::add(T x)
{
    try{
    T* *temp = new T*[nr+1];
    for(int i = 0 ; i < nr ; i++)
        temp[i] = lista[i];

    temp[nr] = new T;
    (*temp[nr]) = x;

    nr++;

    delete[] lista;

    lista = new T*[nr];

    for(int i = 0 ; i < nr ; i++)
        lista[i] = temp[i];

    delete[] temp;

    cout<<"Lista farmaciilor a fost actualizata!"<<endl<<endl;
    }
    catch(bad_alloc& e)
    {
        cout<<"Memorie insuficienta!";
    }
}

template <class T>
void chestionar<T>::sterg(int x)
{
    try{
    T* *temp = new T*[nr-1];

        for(int i = 0 ; i < x ; i++)
        temp[i] = lista[i];

        for(int i = x+1 ; i < nr ; i++)
            temp[i-1] = lista[i];

        nr--;

        delete[] lista;

        lista = new T*[nr];


    for(int i = 0 ; i < nr ; i++)
        lista[i] = temp[i];

    delete[] temp;

    cout<<"Lista farmaciilor a fost actualizata!"<<endl<<endl;
    }
    catch(bad_alloc& e)
    {
        cout<<"Memorie insuficienta!";
    }

}

template <class T>
void chestionar<T>::afis(int x)
{
    cout<<"Informatii despre farmacie:"<<endl;
    lista[x]->display();
    cout<<endl;
}

template <class T>
void chestionar<T>::angajat(int x)
{
    (*lista[x])++;
    cout<<"Numarul de angajati pentru farmacia "<<lista[x]->getNume()<<" a fost actualizat!"<<endl;
}

template <class T>
void chestionar<T>::marire(int x)
{
    double y;
    cout<<"Introduceti profitul pe aceasta luna: "; cin>>y;

    (*lista[x]) = (*lista[x]) + y;

    cout<<"Profitul pentru farmacia "<<lista[x]->getNume()<<" a fost actualizat!"<<endl;
}
