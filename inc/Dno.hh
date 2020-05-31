#ifndef DNO_HH
#define DNO_HH

#define margines 1

#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"
#include <cmath>

class Dno: public Plaszczyzna, Przeszkoda
{
    double m_wysokosc;

public:
    Dno()=delete;

    Dno(double wymX, double wymY, double wysokosc):
        Plaszczyzna(wymX, wymY, 0, 0, wysokosc), m_wysokosc(wysokosc)
    {std::cout<<m_wysokosc;}

    bool czy_kolizja(std::shared_ptr<InterfejsDrona> D)override;

};

#endif