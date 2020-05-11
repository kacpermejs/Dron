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
    //double m_kat;
    //char m_kierunek;
public:
    MacierzOb()
    {
        UstawMacierzOb(0,'z');
    }

    MacierzOb(double kat, char kierunek)
    {
        UstawMacierzOb(kat, kierunek);
    }
    MacierzOb(MacierzKw<double,3> Mac2)
    {
        UstawMacierz(Mac2);
    }

    void UstawMacierzOb(double kat, char kierunek);

    void Set(double kat, char kierunek) {(*this)=MacierzOb(kat, kierunek);}
    const MacierzOb Get() const {return *this;}

    //const double GetKat() const {return m_kat;}
    
};

#endif