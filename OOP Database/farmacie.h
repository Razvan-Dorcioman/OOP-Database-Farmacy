#include <iostream>
#include "farmacieAbstract.h"

using namespace std;

class farmacie : public farmacieAbstract
{
protected:

    char* nume;
    int angajati;
    double profit;


public:
    farmacie();
    farmacie(char* , int , double);
    farmacie( const farmacie& );

    ~farmacie();


    void display();
    farmacie& operator=(farmacie);
    char* getNume();

    farmacie operator++();
    farmacie operator++(int);
    friend farmacie operator+(farmacie& , double);
    friend farmacie operator+(double , farmacie&);

    friend istream& operator>>(istream&, farmacie&);

    farmacie & operator()(char* , int , double);


};
