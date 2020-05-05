#ifndef DRON_PODWODNY

#define DRON_PODWODNY

#include "Macierz.hh"
#include "Wektor.hh"
#include "Dr3D_gnuplot_api.hh"
#include <cmath>

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

class InterfejsRysowania: public APIGnuPlot3D
{
public:
    
};

class MacierzOb: public MacierzKw<double, 3>
{
public:


};

class Bryla
{
protected:
    MacierzOb MacOb;
    Wektor<double, 3> WekPol;
};

class Prostopadloscian : public Bryla
{
    Wektor<double, 3> Wymiary; //(x,y,z)
};

class InterfejsDrona: public InterfejsRysowania
{

public:
    void Rysuj();

};

class Dron: public InterfejsDrona, public Prostopadloscian
{


};


#endif