#ifndef DRON_PODWODNY

#define DRON_PODWODNY

#include "InterfejsDrona.hh"
#include "Prostopadloscian.hh"
#include "Sruba.hh"

#define WymiarXdrona 8
#define WymiarYdrona 4
#define WymiarZdrona 4

class Dron: public InterfejsDrona, public Prostopadloscian
{
    Sruba L;
    Sruba P;
public:
    Dron():
        Prostopadloscian(0,0,0,WymiarXdrona,WymiarYdrona,WymiarZdrona), 
        L(Wektor3D{-WymiarXdrona/2,WymiarYdrona/2,0}, MacierzOb(90, 'y')),
        P(Wektor3D{-WymiarXdrona/2,-WymiarYdrona/2,0}, MacierzOb(90, 'y'))
    {}
    Dron(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ):
        Prostopadloscian(WspX, WspY, WspZ, WymX, WymY, WymZ),
        L(Wektor3D{-WymX/2,WymY/2,0}, MacierzOb(90, 'y')),
        P(Wektor3D{-WymX/2,-WymY/2,0}, MacierzOb(90, 'y'))
    {}

    void RysowaieDrona();

    void WymazDrona();
    
    void Sterowanie();
    
    void AnimacjaWynurzania();
    void AnimacjaZanurzania();
    void PlynPrzod();
    void PlynTyl();
    void SkrecLewo();
    void SkrecPrawo();
    
};

#endif