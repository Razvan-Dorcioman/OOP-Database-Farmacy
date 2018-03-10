#include <iostream>
#include "chestionar.h"
#include <windows.h>

using namespace std;

int main()
{
    farmacie f1, f2("Catena" , 10 , 203.54 ) , f3(f1);
    farmacieOnline x1 , x2("Sensi Blue" , 100 , 600.23  , "www.cevavava.com" , 2) , x3("Catenaa" , 150 , 512.32 , "www.lala.ro" , 3);
    chestionar <farmacieOnline> c2(1);
    chestionar <farmacie> c1(1);
    int x;
    int y;
    int z;



    cout<<"Meniu:"<<endl;

    cout<<"1-Farmacie Simpla"<<endl<<"2-Farmacie Online"<<endl<<"0-EXIT"<<endl<<"Selectati optiunea dorita: ";
    cin>>x;
    while(x && x != 1 && x != 2)
         {
        cout<<"Optiunea aleasa nu exista!"<<endl<<"Introduceti o noua optiune: ";
        cin>>x;
         }

         if(!x)
        cout<<"La revedere!";

        else

    while(x)
    {

    switch(x)
    {
case 1:
    system("cls"); cout<<"Lista optiuni:"<<endl<<"1-Adaugare farmacie"<<endl<<"2-Stergere farmacie"<<endl<<"3-Afisare farmacie"<<endl<<"4-Afisare lista farmacii"<<endl<<"5-Adauga angajat"<<endl<<"6-Adauga profit"<<endl<<"7-Transfer"<<endl<<"0-EXIT"<<endl;
    cout<<"Alegeti optiunea: ";
    cin>>y;

    while(y < 0 || y > 7)
    {
        cout<<"Optiunea aleasa nu exista!"<<endl<<"Introduceti o noua optiune: ";
        cin>>y;
    }


    system("cls");
    while(y)
    {
        switch(y)
        {

    case 1:
        system("cls"); cout<<"Introduceti datele despre farmacie"<<endl;
        cin>>f1;
        c1.add(f1);
        break;

    case 2:
        system("cls"); cout<<"Introduceti id-ul farmaciei pe care doriti sa o eliminati: ";
        if(c1.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";
            break;
        }
        cin>>z;
        while (z < 1 || z > c1.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        c1.sterg(z);
        break;

    case 3:
        system("cls");
        cout<<"Introduceti id-ul farmaciei pentru a fi afisate datele despre aceasta: ";
          if(c1.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";
            cout<<endl;
          cout<<"Introduceti un id nou: ";
            break;
        }
        cin>>z;
        while (z < 1 || z > c1.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        c1.afis(z);
        break;

    case 4:
        system("cls");
        c1.display();
        break;

    case 5:
        system("cls");
        cout<<"Introduceti id-ul farmaciei: ";
          if(c1.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";
            cout<<endl;
          cout<<"Introduceti un id nou: ";
            break;
        }
        cin>>z;
        while (z < 1 || z > c1.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        c1.angajat(z);
        break;

    case 6:
        system("cls");
        cout<<"Introduceti id-ul farmaciei: ";
          if(c1.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";
            cout<<endl;
          cout<<"Introduceti un id nou: ";
            break;
        }
        cin>>z;
        while (z < 1 || z > c1.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        c1.marire(z);
        break;

    case 7:
        system("cls");
        cout<<"Introduceti id-ul farmaciei pentru conversie: ";
             if(c2.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";
            cout<<endl;
          cout<<"Introduceti un id nou: ";
            break;
        }
        cin>>z;
        while (z < 1 || z > c2.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        f1 = (farmacie)(c2.getFarmacie(z));
        c1.add(f1);
        c2.sterg(z);
        break;


        }


    cout<<endl; cout<<"Lista optiuni:"<<endl<<"1-Adaugare farmacie"<<endl<<"2-Stergere farmacie"<<endl<<"3-Afisare farmacie"<<endl<<"4-Afisare lista farmacii"<<endl<<"5-Adauga angajat"<<endl<<"6-Adauga profit"<<endl<<"7-Transfer"<<endl<<"0-EXIT"<<endl;
    cout<<"Alegeti optiunea: ";
    cin>>y;

    while(y < 0 || y > 7)
    {
        cout<<"Optiunea aleasa nu exista!"<<endl<<"Introduceti o noua optiune: ";
        cin>>y;
    }

    }
      break;

    case 2:
        system("cls"); cout<<"Lista optiuni:"<<endl<<"1-Adaugare farmacie"<<endl<<"2-Stergere farmacie"<<endl<<"3-Afisare farmacie"<<endl<<"4-Afisare lista farmacii"<<endl<<"5-Adauga angajat"<<endl<<"6-Adauga profit"<<endl<<"7-Verifica vizitatorii"<<endl<<"0-EXIT"<<endl;
    cout<<"Alegeti optiunea: ";
    cin>>y;

    while(y < 0 || y > 7)
    {
        cout<<"Optiunea aleasa nu exista!"<<endl<<"Introduceti o noua optiune: ";
        cin>>y;
    }

    system("cls");
    while(y)
    {
        switch(y)
        {

    case 1:
        system("cls"); cout<<"Introduceti datele despre farmacie"<<endl;
        cin>>x1;
        c2.add(x1);
        break;

    case 2:
        system("cls"); cout<<"Introduceti id-ul farmaciei pe care doriti sa o eliminati: ";
          if(c2.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";
            break;
        }
        cin>>z;
        while (z < 1 || z > c2.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        c2.sterg(z);
        break;

    case 3:
        system("cls");
        cout<<"Introduceti id-ul farmaciei pentru a fi afisate datele despre aceasta: ";
          if(c2.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";
            break;
        }
        cin>>z;
        while (z < 1 || z > c2.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        c2.afis(z);
        break;

    case 4:
        system("cls");
        c2.display();
        break;

    case 5:
        system("cls");
        cout<<"Introduceti id-ul farmaciei: ";
          if(c2.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";

            break;
        }
        cin>>z;
        while (z < 1 || z > c2.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        c2.angajat(z);
        break;

    case 6:
        system("cls");
        cout<<"Introduceti id-ul farmaciei: ";
          if(c2.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";
            break;
        }
        cin>>z;
        while (z < 1 || z > c2.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        c2.marire(z);
        break;

    case 7:
        system("cls");
          cout<<"Introduceti id-ul farmaciei: ";
          if(c2.getNr() == 1)
        {
            cout<<"Nu exista farmacii in lista!";
            break;
        }
        cin>>z;
        while (z < 1 || z > c2.getNr()-1)
        {
          cout<<"Farmacia aleasa nu exista!";
          cout<<endl;
          cout<<"Introduceti un id nou: ";
        cin>>z;
        }
        c2.vizit(z);
        break;
        }




    cout<<endl; cout<<"Lista optiuni:"<<endl<<"1-Adaugare farmacie"<<endl<<"2-Stergere farmacie"<<endl<<"3-Afisare farmacie"<<endl<<"4-Afisare lista farmacii"<<endl<<"5-Adauga angajat"<<endl<<"6-Adauga profit"<<endl<<"7-Verifica vizitatorii"<<endl<<"0-EXIT"<<endl;
    cout<<"Alegeti optiunea: ";
    cin>>y;

    while(y < 0 || y > 7)
    {
        cout<<"Optiunea aleasa nu exista!"<<endl<<"Introduceti o noua optiune: ";
        cin>>y;
    }

    }
    break;

    }

    system("cls");

        cout<<"Meniu:"<<endl;

    cout<<"1-Farmacie Simpla"<<endl<<"2-Farmacie Online"<<endl<<"0-EXIT"<<endl<<"Selectati optiunea dorita: ";
    cin>>x;
    while(x && x != 1 && x != 2)
         {
        cout<<"Optiunea aleasa nu exista!"<<endl<<"Introduceti o noua optiune: ";
        cin>>x;
    }


    }

    return 0;
}
