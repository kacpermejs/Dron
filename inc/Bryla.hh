#ifndef BRYLA

#define BRYLA

#include "MacierzOb.hh"

class Bryla
{
protected:
    
    Wektor<double,3> WekPol; //wektor wspolrzednych srodka obiektu
public:
    MacierzOb MacOb;
    Bryla(): WekPol{0,0,0} {}
    Bryla(double WspX, double WspY, double WspZ): WekPol{WspX, WspY, WspZ} {}

    void SetX(double x){this->WekPol[0]=x;}
    void SetY(double y){this->WekPol[1]=y;}
    void SetZ(double z){this->WekPol[2]=z;}

    const double GetX(){return this->WekPol[0];}
    const double GetY(){return this->WekPol[1];}
    const double GetZ(){return this->WekPol[2];}

    virtual void obroc(double kat, char kierunek)=0;

};

#endif