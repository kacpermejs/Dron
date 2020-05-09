#ifndef MACIERZ_OB

#define MACIERZ_OB

#include <cmath>
#include <vector>
#include "Macierz.hh"
#include "Wektor.hh"

#define PI 3.14159265

class MacierzOb: public MacierzKw<double, 3>
{
protected:
    double m_kat;
    char m_kierunek;
public:
    MacierzOb():
        m_kat(0), m_kierunek('z')
    {
        UstawMacierzOb();
    }

    MacierzOb(double kat, char kierunek):
        m_kat(kat), m_kierunek(kierunek)
    {
        UstawMacierzOb();
    }

    void UstawMacierzOb();

    void Set(double kat, char kierunek) {(*this)=MacierzOb(kat, kierunek);}
    const MacierzOb Get() const {return *this;}
    
};

#endif