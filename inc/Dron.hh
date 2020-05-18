#ifndef DRON_PODWODNY

#define DRON_PODWODNY

#include "InterfejsDrona.hh"
#include "Prostopadloscian.hh"

#define WymiarXdrona 4
#define WymiarYdrona 8
#define WymiarZdrona 4

class Dron: public InterfejsDrona, public Prostopadloscian
{
    Prostopadloscian m_WirnikLewy;
    Prostopadloscian m_WirnikPrawy;
    Wektor<double,3> m_lewyWirnikLok;
    Wektor<double,3> m_prawyWirnikLok;
public:
    Dron(): Prostopadloscian(0,0,0,WymiarXdrona,WymiarYdrona,WymiarZdrona), m_WirnikLewy(-2,-4,0,1,2,1), m_WirnikPrawy(2,-4,0,1,2,1)
    {
        m_lewyWirnikLok=m_WirnikLewy.GetWekPol();
        m_prawyWirnikLok=m_WirnikPrawy.GetWekPol();
    }
    Dron(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ): Prostopadloscian(WspX, WspY, WspZ, WymX, WymY, WymZ) {}

    void RysowaieDrona();
    
    void Sterowanie();
    
    void AnimacjaWynurzania();
    void AnimacjaZanurzania();
    void PlynPrzod();
    void PlynTyl();
    void SkrecLewo();
    void SkrecPrawo();
    
};

#endif