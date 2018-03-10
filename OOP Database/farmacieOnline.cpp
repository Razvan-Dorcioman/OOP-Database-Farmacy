#include <iostream>
#include <string.h>
#include "farmacieOnline.h"

using namespace std;

farmacieOnline::farmacieOnline()
{
    adresa = new char[4];
    strcpy(adresa , "N/A");

    vizitatori = 0;
    rating = 0;

}

farmacieOnline::farmacieOnline(char *s , int a , double p, char* adr , int r):farmacie(s,a,p)
{
    adresa = new char[strlen(adr) +1];
    strcpy(adresa , adr);
    rating = r;

}

farmacieOnline::farmacieOnline( const farmacieOnline& x ):farmacie(x)
{
    adresa = new char[strlen(x.adresa) +1];
    strcpy(adresa , x.adresa);
    vizitatori = x.vizitatori;
    rating = x.rating;
}

farmacieOnline::~farmacieOnline()
{
    delete[] adresa;
}

void farmacieOnline::display()
{
    farmacie::display();
    cout<<"Adresa web: "<<adresa<<endl<<"Rating: "<<rating<<endl;
}

char* farmacieOnline::getAdresa()
{
    return adresa;
}

void farmacieOnline::vizite()
{
    int temp = 0;
    int x , y;
    cout<<"Introduceti ora: ";
    cin>>x>>y;
    if(x > 24 || y > 60 || x < 0 || y < 0)
        cout<<"Formatul orei este incorect!"<<endl<<"Introduceti ora din nou: ";
        while(x > 24 || y > 60 || x < 0 || y < 0)
        {
               cin>>x>>y;
    if(x > 24 || y > 60 || x < 0 || y < 0)
        cout<<"Formatul orei este incorect!"<<endl<<"Introduceti ora din nou: ";
        }



    temp += x*60 + y;
    int z = 0;
    if(x > 15 && x <= 18)

        {
            for(int i = 15 ; i <= x ; i++)
        z += 4*60;
        }
    else
        if(x > 18)
        z += 16*60;

    temp += z;

    temp *= rating;


        vizitatori = temp;



    if(y)
        if(y<10)
    cout<<"Numarul total de vizitatori pana la "<<x<<":0"<<y<<" este: "<<vizitatori<<endl;
        else
    cout<<"Numarul total de vizitatori pana la "<<x<<":"<<y<<" este: "<<vizitatori<<endl;
    else
    cout<<"Numarul total de vizitatori pana la "<<x<<":00 este: "<<vizitatori<<endl;

}

istream& operator>> (istream& in , farmacieOnline& x)
{
    try{
     char temp[100];

     cout<<"Nume: ";
    in.get();
    in.get(temp,100);


    x.nume = new char[strlen(temp) +1];
    strcpy(x.nume , temp);

    delete[] temp;

    cout<<"Numar angajati: ";
    in>>x.angajati;
    cout<<"Profit total: ";
    in>>x.profit;


     cout<<"Adresa Web: ";
     char temp1[100];

     in.get();
     in.get(temp1,100);
     //in.get();

     x.adresa = new char[strlen(temp1) +1];

     strcpy(x.adresa , temp1);

     delete[] temp1;

     cout<<"Raiting: ";
     in>>x.rating;
    }
    catch(bad_alloc& e)
    {
        cout<<"Memorie insuficienta!";
    }

    return in;
}

farmacieOnline & farmacieOnline :: operator= (farmacieOnline x)
{
    if(nume)
        delete[] nume;
try{
    nume = new char[strlen(x.nume) +1];
    strcpy(nume , x.nume);
    angajati = x.angajati;
    profit = x.profit;

    if(adresa)
        delete[] adresa;
    adresa = new char[strlen(x.adresa) +1];

    strcpy(adresa , x.adresa);
    vizitatori = x.vizitatori;
    rating = x.rating;
}
catch(bad_alloc& e)
    {
        cout<<"Memorie insuficienta!";
    }
}

farmacieOnline & farmacieOnline::operator()(char* n , int a , double p , char* adr , int r)
{
    if(nume)
        delete[] nume;

    nume = new char[strlen(n)+1];
    strcpy(nume, n);
    angajati = a;
    profit = p;

    if(adresa)
        delete[] adresa;

    adresa = new char[strlen(adr)+1];
    strcpy(adresa, adr);

    rating = r;

    return *this;
}

farmacieOnline operator+(farmacieOnline& x , double z)
{
    farmacieOnline y;
    y = x;
    y.profit = y.profit + z;

    return y;
}

farmacieOnline operator+( double z , farmacieOnline& x)
{
    farmacieOnline y;
    y = x;
    y.profit = y.profit + z;

    return y;
}

