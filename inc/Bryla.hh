#ifndef BRYLA

#define BRYLA

#include "MacierzOb.hh"

class Bryla
{
protected:
    MacierzOb MacOb;
    Wektor<double,3> WekPol; //wektor wspolrzednych srodka obiektu
public:
    Bryla(): WekPol{0,0,0} {}
    Bryla(double WspX, double WspY, double WspZ): WekPol{WspX, WspY, WspZ} {}

    void SetWekPol(Wektor<double,3> Wek2) {this->WekPol=Wek2;}
    const Wektor<double,3> GetWekPol(){return this->WekPol;}

    const MacierzKw<double, 3> GetMacierzObrotu() {return this->MacOb;}

    virtual void obroc(double kat, char kierunek)=0;
    virtual void przesun(Wektor<double,3> V)=0;

};

#endif