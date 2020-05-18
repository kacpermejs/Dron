#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "InterfejsRysowania.hh"
#include "MacierzOb.hh"

class Plaszczyzna: public InterfejsRysowania
{
protected:
    double m_wymiarX;
    double m_wymiarY;
    MacierzOb m_MacierzOrientacji;
    std::vector<std::vector<drawNS::Point3D>> m_punkty;
    //std::vector<Wektor<double,3>> m_punkty;
    Wektor<double,3> m_punktPodstawowy;
public:
    Plaszczyzna():
        m_wymiarX(10), m_wymiarY(10), m_MacierzOrientacji(), m_punktPodstawowy({0,0,0})
    { UstawPunktyGlobalnie(); }

    Plaszczyzna(double wymX, double wymY, double X, double Y, double Z):
        m_wymiarX(wymX), m_wymiarY(wymY), m_punktPodstawowy({X,Y,Z}), m_MacierzOrientacji()
    { UstawPunktyGlobalnie(); }

    void Rysuj()override;
    void UstawPunktyGlobalnie();

    void obroc(double kat, char kierunek)
    {
        assert(kierunek=='x' || kierunek=='y' || kierunek=='z');
        m_MacierzOrientacji*=MacierzOb(kat, kierunek);    
    }



};


#endif