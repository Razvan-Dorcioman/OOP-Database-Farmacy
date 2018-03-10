#include <iostream>
#include "farmacie.h"
#include <string.h>

using namespace std;

farmacie::farmacie()
{
    nume = new char[8];
    strcpy(nume , "Unknown");
    angajati = 0;
    profit = 0;
}

farmacie::farmacie(char *s , int x , double y)
{
    nume = new char[strlen(s)+1];
    strcpy(nume , s);
    angajati = x;
    profit = y;
}

farmacie::farmacie( const farmacie& x )
{
    nume = new char[strlen(x.nume) +1];
    strcpy(nume , x.nume);
    angajati = x.angajati;
    profit = x.profit;
}

farmacie::~farmacie()
{
    delete[] nume;

}

void farmacie::display()
{
    cout<<"Nume: "<<nume<<endl<<"Numar angajati: "<<angajati<<endl<<"Profit: "<<profit<<endl;

}

farmacie & farmacie :: operator= (farmacie x)
{
    if(nume)
        delete[] nume;
try
    {
        nume = new char[strlen(x.nume) +1];
        strcpy(nume , x.nume);
    angajati = x.angajati;
    profit = x.profit;
    }
    catch(bad_alloc& e)
    {
        cout<<"Memorie insuficienta!";
    }
}

istream& operator>> (istream& in , farmacie& x)
{

try{
    cout<<"Nume: ";
    char temp[100];
    in.get();
    in.get(temp,100);
    //in.get();

    x.nume = new char[strlen(temp) +1];
    strcpy(x.nume , temp);

    delete[] temp;

    cout<<"Numar angajati: ";
    in>>x.angajati;
    cout<<"Profit total: ";
    in>>x.profit;
}

  catch(bad_alloc& e)
    {
        cout<<"Memorie insuficienta!";
    }

    return in;
}

farmacie farmacie::operator++()
{
    this->angajati++;

    return *this;

}

farmacie farmacie::operator++(int)
{
    this->angajati++;

    return *this;
}

farmacie operator+(farmacie& x , double z)
{
    farmacie y;
    y = x;
    y.profit = y.profit + z;

    return y;
}

farmacie operator+( double z , farmacie& x)
{
    farmacie y;
    y = x;
    y.profit = y.profit + z;

    return y;
}

farmacie & farmacie::operator()(char* n , int a , double p)
{
    if(nume)
        delete[] nume;

    nume = new char[strlen(n)+1];
    strcpy(nume, n);
    angajati = a;
    profit = p;

    return *this;
}

char* farmacie::getNume()
{
    return nume;
}
