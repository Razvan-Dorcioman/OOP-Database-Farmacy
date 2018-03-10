#include <iostream>
#include "farmacie.h"

using namespace std;

class farmacieOnline : public farmacie
{
    char* adresa;
    int vizitatori;
    int rating;

public:
    farmacieOnline();
    farmacieOnline(char* , int , double , char* , int);
    farmacieOnline(const farmacieOnline&);

   ~farmacieOnline();

   void display();
   void vizite();
   char* getAdresa();


//    farmacieOnline operator++();
//    farmacieOnline operator++(int);
    friend farmacieOnline operator+(farmacieOnline& , double);
    friend farmacieOnline operator+(double , farmacieOnline&);

    farmacieOnline& operator=(farmacieOnline);

    farmacieOnline & operator()(char* , int , double , char* , int);



 friend istream& operator>>(istream&, farmacieOnline&);



};
